#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int main()
{
  std::thread thr1(sleep, 1);
  std::thread thr2(sleep, 5);
  std::mutex mut;
  std::condition_variable var;
  std::unique_lock lock;

  

  return 0;
}