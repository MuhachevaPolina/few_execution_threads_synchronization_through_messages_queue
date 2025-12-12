#include "src/parallel_executor/EventQueue.h"
#include "src/parallel_executor/WorkDoneEvent.h"
#include "src/parallel_executor/DeviceB.h"

#include <iostream>
#include <memory>
#include <chrono>

int main()
{
  EventQueue queue;
  std::shared_ptr<Device> dev(new DeviceB());
  std::shared_ptr<const Event> ev(new const WorkDoneEvent(dev));
  queue.push(ev);
  auto gottenEv = queue.pop(std::chrono::seconds(10));
  //Event* gottenEv = gottenPtr.get();
  std::cout << gottenEv->toString() << std::endl;
  return 0;
}