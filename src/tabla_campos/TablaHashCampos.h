//
// Created by vicente on 2/04/24.
//

#ifndef CONTACT_MANAGEMENT_SYSTEM_TABLAHASHCAMPOS_H
#define CONTACT_MANAGEMENT_SYSTEM_TABLAHASHCAMPOS_H


#include <vector>
#include "../campo/Campo.h"

class TablaHashCampos {
private:
    static const int CAPACIDAD_INICIAL = 5;
    std::vector<std::vector<Campo>> tabla;
    int elementos;
    int capacidad;

    size_t hash(std::string nombre) const;
    void rehash();

public:
    TablaHashCampos();
    void agregarCampo(std::string nombre, std::string tipo);
    bool buscarCampo(std::string nombre, std::string tipo) const;
    double porcentajeOcupacionCampos();
};

#endif //CONTACT_MANAGEMENT_SYSTEM_TABLAHASHCAMPOS_H
