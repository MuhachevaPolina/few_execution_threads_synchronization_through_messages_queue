cmake_minimum_required(VERSION 3.15.0)
										
set(SOURCE_EXE main.cpp)		

set(SOURCE_LIB DataEvent.cpp
            DeviceA.cpp
            DeviceB.cpp
            DeviceEvent.cpp
            DeviceReader.cpp
            EventQueue.cpp
            StartedEvent.cpp
            WorkDoneEvent.cpp)	

add_library(device STATIC ${SOURCE_LIB})		