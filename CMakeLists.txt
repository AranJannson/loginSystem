cmake_minimum_required(VERSION 3.26)
project(loginSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(loginSystem main.cpp
        cmake-build-debug/login.h
        cmake-build-debug/Register.h
        cmake-build-debug/Register.cpp
        cmake-build-debug/Login.cpp
)
