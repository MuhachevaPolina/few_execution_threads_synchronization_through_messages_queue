SOURCES=main.cpp CLI/ConsoleLineInterface.cpp src/DataEvent.cpp src/Device.cpp src/DeviceA.cpp src/DeviceB.cpp src/DeviceEvent.cpp src/DeviceReader.cpp src/EventQueue.cpp src/StartedEvent.cpp src/WorkDoneEvent.cpp src/DataStorage.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=run

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	g++ $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -rf *.o run