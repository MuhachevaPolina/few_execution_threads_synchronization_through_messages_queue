cmake_minimum_required(VERSION 3.15.0)
										
set(SOURCE_EXE main.cpp)		

set(SOURCE_LIB DataEvent.cpp
            Device.cpp
            DeviceA.cpp
            DeviceB.cpp
            DeviceEvent.cpp
            DeviceReader.cpp
            EventQueue.cpp
            StartedEvent.cpp
            WorkDoneEvent.cpp
            DataStorage.cpp)	

add_library(device STATIC ${SOURCE_LIB})	
target_link_libraries(device Threads::Threads)	