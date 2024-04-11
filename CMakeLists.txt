cmake_minimum_required(VERSION 3.27)
project(turing_machine_simulator C)

set(CMAKE_C_STANDARD 11)

add_executable(turing_machine_simulator main.c
        controller.c
        model.h
        view.c
        view.h
        service.c
        service.h)
