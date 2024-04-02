//
// Created by vicente on 2/04/24.
//

#ifndef CONTACT_MANAGEMENT_SYSTEM_CAMPO_H
#define CONTACT_MANAGEMENT_SYSTEM_CAMPO_H


#include <string>

class Campo {
public:
    std::string nombre;
    std::string tipo;

    Campo(std::string nombre, std::string tipo);
    size_t hashCampo() const;
};


#endif //CONTACT_MANAGEMENT_SYSTEM_CAMPO_H
