#pragma once

#include "Event.h"

#include <memory>
#include <chrono>
#include <queue>
#include <mutex>
#include <condition_variable>

class EventQueue
{
public:
  void push(const std::shared_ptr<const Event>& event);
  std::shared_ptr<const Event> pop(std::chrono::seconds& duration);

private:
  std::queue<std::shared_ptr<const Event>> m_queue;
  std::mutex m_mtx;
  std::condition_variable m_condVar;
};