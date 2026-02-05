#include "EventQueue.h"

void EventQueue::push(const std::shared_ptr<const Event>& event)
{
  std::unique_lock<std::mutex> lock(this->m_mtx);
  this->m_condVar.wait(lock);

  this->m_queue.push(event);

  this->m_condVar.notify_one();
}

std::shared_ptr<const Event> EventQueue::pop(std::chrono::seconds& duration)
{
  std::unique_lock<std::mutex> lock(this->m_mtx);

  if (!this->m_queue.empty())
  {
    this->m_condVar.wait(lock);
    auto lastEv = this->m_queue.front();
    this->m_queue.pop();

    this->m_condVar.notify_one();
    return lastEv;
  }

  this->m_condVar.notify_one();
  return nullptr;
}