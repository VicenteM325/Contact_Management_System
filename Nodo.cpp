//
// Created by vicente on 2/04/24.
//

#include "Nodo.h"

Nodo::Nodo(std::string nombre, std::string tipo) {
    this->nombre = nombre;
    this->tipo = tipo;
    this->siguiente = nullptr;
}
