class EventQueue

{

public:

//  put message into queue

void push(const std::shared_ptr<const Event>& event);

 

// delete message from queue and return it. if queue is empty and 
// after the duration return empty pointer
  std::shared_ptr<const Event> pop(const std::chrono::seconds& duration);

private:

	std::queue<std::shared_ptr<const Event>> queue;

	std::mutex mtx;

	std::condition_variable cv;

};
