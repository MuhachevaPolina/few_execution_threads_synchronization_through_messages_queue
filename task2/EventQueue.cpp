#include "EventQueue.h"

EventQueue::~EventQueue() {
    stop();
}

void EventQueue::push(const std::shared_ptr<const Event>& event) {
    if (this->m_stopped) return;
    
    {
        std::lock_guard<std::mutex> lock(this->m_mtx);
        this->m_queue.push(event);
    }
    this->m_cv.notify_one();
}

std::shared_ptr<const Event> EventQueue::pop(const std::chrono::seconds& duration) {
    std::unique_lock<std::mutex> lock(this->m_mtx);
    
    if (this->m_cv.wait_for(lock, duration, [this]() { 
        return !this->m_queue.empty() || this->m_stopped; 
    })) {
        if (!this->m_queue.empty()) {
            auto event = this->m_queue.front();
            this->m_queue.pop();
            return event;
        }
    }
    
    return nullptr;
}

void EventQueue::stop() {
    this->m_stopped = true;
    this->m_cv.notify_all();
}

bool EventQueue::empty() const {
    std::lock_guard<std::mutex> lock(this->m_mtx);
    return this->m_queue.empty();
}

size_t EventQueue::size() const {
    std::lock_guard<std::mutex> lock(this->m_mtx);
    return this->m_queue.size();
}