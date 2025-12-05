#include "EventQueue.h"

void EventQueue::push(const std::shared_ptr<const Event>& event)
{
  this->m_queue.push(event);
}

std::shared_ptr<const Event> EventQueue::pop(const std::chrono::seconds& duration)
{
  std::shared_ptr<const Event> tmp_ev;
  auto start_time = std::chrono::steady_clock::now();

  while (std::chrono::steady_clock::now() - start_time < duration)
  {
    if (!this->m_queue.empty())
    {
      tmp_ev = this->m_queue.front();
      this->m_queue.pop();
      break;
    }
    tmp_ev = nullptr;
  }

  return tmp_ev;
}