//
// Created by vicente on 2/04/24.
//

#include "TablaHashCampos.h"
#include <iostream>

TablaHashCampos::TablaHashCampos() : elementos(0) {
    tabla.resize(CAPACIDAD_INICIAL);
}

size_t TablaHashCampos::hash(std::string nombre) const {
    size_t hash = 0;
    for (char c : nombre) {
        hash += c;
    }
    return hash % tabla.size();
}

void TablaHashCampos::rehash() {
    int nuevaCapacidad = tabla.size() * 2;
    std::vector<std::vector<Campo>> nuevaTabla(nuevaCapacidad);

    for (const auto& lista : tabla) {
        for (const auto& campo : lista) {
            size_t indice = hash(campo.nombre);
            nuevaTabla[indice].push_back(campo);
        }
    }

    tabla = std::move(nuevaTabla);
}

void TablaHashCampos::agregarCampo(std::string nombre, std::string tipo) {
    if (elementos >= CAPACIDAD_INICIAL * 0.6) {
        rehash();
    }

    Campo nuevoCampo(nombre, tipo);
    size_t indice = hash(nombre);
    tabla[indice].push_back(nuevoCampo);
    ++elementos;
    std::cout << "Campo '" << nombre << "' asignado al índice: " << indice << std::endl;
}

bool TablaHashCampos::buscarCampo(std::string nombre, std::string tipo) const {
    size_t indice = hash(nombre);
    for (const auto& campo : tabla[indice]) {
        if (campo.nombre == nombre && campo.tipo == tipo) {
            return true;
        }
    }
    return false;
}