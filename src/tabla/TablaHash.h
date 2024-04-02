//
// Created by vicente on 23/03/24.
//

#ifndef CONTACT_MANAGEMENT_SYSTEM_TABLAHASH_H
#define CONTACT_MANAGEMENT_SYSTEM_TABLAHASH_H

#include <list>
#include <string>
#include <iostream>
#include "../grupo/Grupo.h"

class TablaHash {
private:
    static const double FACTOR_CARGA_MAXIMO;
    std::list<Grupo*>* tabla;
    int capacidad;
    int elementos;

    int calcularHash(const std::string& nombre);
    void rehash();

public:
    TablaHash();
    ~TablaHash();

    void agregarGrupo(Grupo* grupo);
    std::list<Grupo*>* obtenerTabla();
    double porcentajeOcupacion();
    void mostrarGrupos();
    Grupo* buscarGrupo(const std::string& nombre);

    static const int CAPACIDAD_INICIAL = 5;

    void mostrarContactosEnGrupos();
};

#endif //CONTACT_MANAGEMENT_SYSTEM_TABLAHASH_H

