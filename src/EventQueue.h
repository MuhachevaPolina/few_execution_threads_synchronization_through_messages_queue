#pragma once

#include "Event.h"

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <chrono>

class EventQueue 
{
public:
  EventQueue() = default;
  ~EventQueue();
    
  void push(const std::shared_ptr<const Event>& event);
  std::shared_ptr<const Event> pop(const std::chrono::seconds& duration);
  void stop();
  bool empty() const;
  size_t size() const;

private:
  std::queue<std::shared_ptr<const Event>> m_queue;
  mutable std::mutex m_mtx;
  std::condition_variable m_cv;
  bool m_stopped = false;
};
