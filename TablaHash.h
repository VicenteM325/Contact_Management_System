//
// Created by vicente on 23/03/24.
//

#ifndef CONTACT_MANAGEMENT_SYSTEM_TABLAHASH_H
#define CONTACT_MANAGEMENT_SYSTEM_TABLAHASH_H


#include <list>
#include <string>
#include <iostream>
#include "Grupo.h"

class TablaHash {
private:
    static const double FACTOR_CARGA_MAXIMO;
    std::list<Grupo*>* tabla;
    int capacidad;
    int elementos;

    // Función hash
    int calcularHash(const std::string& nombre) {
        int hash = 0;
        for (char c : nombre) {
            hash += c;
        }
        return hash % capacidad;
    }

    // Método para rehash
    void rehash() {
        int nuevaCapacidad = capacidad * 2;
        std::list<Grupo*>* nuevaTabla = new std::list<Grupo*>[nuevaCapacidad];

        // Reasignar grupos a la nueva tabla
        for (int i = 0; i < capacidad; ++i) {
            for (Grupo* grupo : tabla[i]) {
                int nuevoIndice = calcularHash(grupo->nombre);
                nuevaTabla[nuevoIndice].push_back(grupo);
            }
        }

        // Eliminar la tabla anterior y actualizar la capacidad
        delete[] tabla;
        tabla = nuevaTabla;
        capacidad = nuevaCapacidad;

        std::cout << "Rehashing realizado. Nueva capacidad: " << capacidad << std::endl;
    }

public:
    TablaHash() {
        capacidad = CAPACIDAD_INICIAL;
        elementos = 0;
        tabla = new std::list<Grupo*>[capacidad];
    }

    // Agregar un grupo a la tabla hash
    void agregarGrupo(Grupo* grupo) {
        if ((double)elementos / capacidad >= FACTOR_CARGA_MAXIMO) {
            rehash();
        }
        int indice = calcularHash(grupo->nombre);
        tabla[indice].push_back(grupo);
        ++elementos;
        std::cout << "Grupo '" << grupo->nombre << "' asignado al índice: " << indice << std::endl;
    }
    //Metodo para obtener la tabla hash
    std::list<Grupo*>* obtenerTabla() {
        return tabla;
    }
    //Metodo para calcular el porcentaje usado de la tabla hash
    double porcentajeOcupacion() {
        return (double)elementos / capacidad * 100;
    }

    // Buscar un grupo por su nombre
    Grupo* buscarGrupo(const std::string& nombre) {
        int indice = calcularHash(nombre);
        for (Grupo* grupo : tabla[indice]) {
            if (grupo->nombre == nombre) {
                return grupo;
            }
        }
        return nullptr; // No se encontró el grupo
    }

    ~TablaHash() {
        delete[] tabla;
    }

    static const int CAPACIDAD_INICIAL = 5;
};

const double TablaHash::FACTOR_CARGA_MAXIMO = 0.6;



#endif //CONTACT_MANAGEMENT_SYSTEM_TABLAHASH_H
