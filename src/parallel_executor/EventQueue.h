#pragma once

#include "Event.h"

#include <memory>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

class EventQueue
{
public:
  EventQueue();
  EventQueue(std::queue<std::shared_ptr<const Event>> queue): m_queue(queue);
//  put message into queue
  void push(const std::shared_ptr<const Event>& event);
// delete message from queue and return it. if queue is empty and 
// after the duration return empty pointer
  std::shared_ptr<const Event> pop(const std::chrono::seconds& duration);

private:
	std::queue<std::shared_ptr<const Event>> m_queue;
	std::mutex m_mtx;
	std::condition_variable m_cv;
};
