#include "EventQueue.h"

void EventQueue::push(const std::shared_ptr<const Event>& event)
{
  std::unique_lock<std::mutex>(this->m_mtx);

  this->m_queue.push(event);
  
  this->m_condVar.notify_one();
}

std::shared_ptr<const Event> EventQueue::pop(std::chrono::seconds& duration)
{
  std::unique_lock<std::mutex>(this->m_mtx);

  if (!this->m_queue.empty())
  {
    auto lastEv = this->m_queue.back();
    this->m_queue.pop();
    return lastEv;
  }

  this->m_condVar.notify_one();
}