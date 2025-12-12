#include <iostream>

#include "StartedEvent.h"
#include "DeviceA.h"
#include "EventQueue.h"

int main()
{
  Device* dev = new DeviceA;
  std::shared_ptr<Device> ptr_dev(dev);

  const Event* ev = new StartedEvent(ptr_dev);
  EventQueue queue;
  std::shared_ptr<const Event> ptr_ev(ev);

  queue.push(ptr_ev);
  std::chrono::seconds duration{5};
  std::shared_ptr<const Event> got_ev = queue.pop(duration);
  std::string str = got_ev->toString();
  std::cout << str << std::endl;

  return 0;
}