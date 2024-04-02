//
// Created by vicente on 2/04/24.
//

#include "TablaHash.h"

const double TablaHash::FACTOR_CARGA_MAXIMO = 0.6;

TablaHash::TablaHash() {
    capacidad = CAPACIDAD_INICIAL;
    elementos = 0;
    tabla = new std::list<Grupo*>[capacidad];
}

TablaHash::~TablaHash() {
    delete[] tabla;
}

void TablaHash::agregarGrupo(Grupo* grupo) {
    if ((double)elementos / capacidad >= FACTOR_CARGA_MAXIMO) {
        rehash();
    }
    int indice = calcularHash(grupo->nombre);
    tabla[indice].push_back(grupo);
    ++elementos;
    std::cout << "grupo '" << grupo->nombre << "' asignado al índice: " << indice << std::endl;
}

std::list<Grupo*>* TablaHash::obtenerTabla() {
    return tabla;
}

double TablaHash::porcentajeOcupacion() {
    return (double)elementos / capacidad * 100;
}

void TablaHash::mostrarGrupos() {
    std::cout << "Grupos ingresados:" << std::endl;
    for (int i = 0; i < capacidad; ++i) {
        for (Grupo* grupo : tabla[i]) {
            std::cout << "Nombre del grupo: " << grupo->nombre << std::endl;
            std::cout << "Campos:" << std::endl;
            Nodo* actual = grupo->cabeza;
            while (actual != nullptr) {
                std::cout << "- Nombre: " << actual->nombre << ", Tipo: " << actual->tipo << std::endl;
                actual = actual->siguiente;
            }
            std::cout << std::endl;
        }
    }
}

Grupo* TablaHash::buscarGrupo(const std::string& nombre) {
    int indice = calcularHash(nombre);
    for (Grupo* grupo : tabla[indice]) {
        if (grupo->nombre == nombre) {
            return grupo;
        }
    }
    return nullptr;
}

int TablaHash::calcularHash(const std::string& nombre) {
    int hash = 0;
    for (char c : nombre) {
        hash += c;
    }
    return hash % capacidad;
}

void TablaHash::rehash() {
    int nuevaCapacidad = capacidad * 2;
    std::list<Grupo*>* nuevaTabla = new std::list<Grupo*>[nuevaCapacidad];

    for (int i = 0; i < capacidad; ++i) {
        for (Grupo* grupo : tabla[i]) {
            int nuevoIndice = calcularHash(grupo->nombre);
            nuevaTabla[nuevoIndice].push_back(grupo);
        }
    }

    delete[] tabla;
    tabla = nuevaTabla;
    capacidad = nuevaCapacidad;

    std::cout << "Rehashing realizado. Nueva capacidad: " << capacidad << std::endl;
}