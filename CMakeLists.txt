cmake_minimum_required(VERSION 3.27)
project(Contact_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Contact_Management_System main.cpp
        tabla/TablaHash.h
        grupo/Grupo.h
        nodo/Nodo.h
        grupo/Grupo.cpp
        nodo/Nodo.cpp
        tabla_campos/TablaHashCampos.h
        tabla_campos/TablaHashCampos.cpp
        campo/Campo.cpp
        tabla/TablaHash.cpp
        arbol_avl/ArbolAVL.h
        arbol_avl/ArbolAVL.cpp
        GeneradorDot.cpp
        arbol_avl/ArbolAVL.cpp
        arbol_avl/ArbolAVL.cpp
        arbol_avl/ArbolAVL.h
)
