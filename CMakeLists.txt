cmake_minimum_required(VERSION 3.27)
project(Contact_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Contact_Management_System main.cpp
        TablaHash.h
        Grupo.h
        Nodo.h
        Grupo.cpp
        Nodo.cpp
        TablaHashCampos.h
        TablaHashCampos.cpp
        Campo.cpp)
