//
// Created by vicente on 2/04/24.
//
#include <string>

#ifndef CONTACT_MANAGEMENT_SYSTEM_NODO_H
#define CONTACT_MANAGEMENT_SYSTEM_NODO_H


#include <string>

class Nodo {
public:
    std::string nombre;
    std::string tipo;
    Nodo* siguiente;

    Nodo(std::string nombre, std::string tipo);
};


#endif //CONTACT_MANAGEMENT_SYSTEM_NODO_H
