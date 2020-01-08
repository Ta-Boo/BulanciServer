cmake_minimum_required(VERSION 3.13)
project(BulanciServer)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost REQUIRED)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

include_directories( ${Boost_INCLUDE_DIRS})

add_executable(BulanciServer main.cpp Comunication/Socket/Socket.cpp Comunication/Socket/Socket.h Comunication/ComunicationManager/ComunicationManager.cpp Comunication/ComunicationManager/ComunicationManager.h Comunication/Data/PlayerData.cpp Comunication/Data/PlayerData.h)
target_link_libraries(BulanciServer  ${Boost_LIBRARIES} )