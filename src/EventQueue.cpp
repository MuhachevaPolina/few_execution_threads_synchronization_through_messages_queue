#include "EventQueue.h"

void EventQueue::push(const std::shared_ptr<const Event>& event)
{
  std::unique_lock<std::mutex> lock(this->m_mtx);

  this->m_queue.push(event);

  lock.unlock();
  this->m_condVar.notify_one();
}

std::shared_ptr<const Event> EventQueue::pop(std::chrono::seconds& duration)
{
  std::unique_lock<std::mutex> lock(this->m_mtx);

  if (this->m_condVar.wait_for(lock, duration, 
        [this]() { return !this->m_queue.empty(); }))
  {
    auto event = this->m_queue.front();
    this->m_queue.pop();
    return event;
  }
  else
  {
    return nullptr;
  }
}