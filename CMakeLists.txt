cmake_minimum_required(VERSION 3.7)
project(RestTest VERSION 0.1.0)

find_package(cpprestsdk REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(hello_world ${CMAKE_CURRENT_SOURCE_DIR}/http_hello_world/main.cpp)
target_link_libraries(hello_world cpprestsdk::cpprest OpenSSL::SSL OpenSSL::Crypto)

install(TARGETS hello_world RUNTIME DESTINATION bin)
