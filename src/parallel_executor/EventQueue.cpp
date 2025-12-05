#include "EventQueue.h"

void EventQueue::push(const std::shared_ptr<const Event>& event)
{
  this->m_queue.push(event);
}

std::shared_ptr<const Event> EventQueue::pop(const std::chrono::seconds& duration)
{
  std::shared_ptr<const Event> tmp_ev = this->m_queue.front();
  this->m_queue.pop();
  return tmp_ev;
}