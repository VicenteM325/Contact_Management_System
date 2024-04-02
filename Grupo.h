//
// Created by vicente on 2/04/24.
//

#ifndef CONTACT_MANAGEMENT_SYSTEM_GRUPO_H
#define CONTACT_MANAGEMENT_SYSTEM_GRUPO_H


#include <string>
#include <list>
#include "Nodo.h"

// Clase para representar un grupo
class Grupo {
public:
    std::string nombre;
    Nodo* cabeza;

    Grupo(std::string nombre);
    void agregarCampo(std::string nombre, std::string tipo);
    void agregarContacto(std::string contacto);
    void buscarContactos(const std::string& campo) const;
    //hash para grupos
    ~Grupo();

private:
    std::list<std::string> contactos;
};

#endif //CONTACT_MANAGEMENT_SYSTEM_GRUPO_H
