add_executable(test_device
    Devices_Tests.cpp
    EventQueueAndEvents_Tests.cpp
    DeviceReader_Tests.cpp
    utilities_Tests.cpp
)

target_link_libraries(test_device
    device
    GTest::gtest
    GTest::gtest_main
)

target_include_directories(test_device
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_BINARY_DIR}
)

add_test(NAME DeviceTests COMMAND test_device)