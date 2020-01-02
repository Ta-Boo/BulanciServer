cmake_minimum_required(VERSION 3.13)
project(BulanciServer)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

add_executable(BulanciServer main.cpp Comunication/Socket/Socket.cpp Comunication/Socket/Socket.h Comunication/ComunicationManager/ComunicationManager.cpp Comunication/ComunicationManager/ComunicationManager.h )
