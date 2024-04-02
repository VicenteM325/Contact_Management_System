

#include "Campo.h"

Campo::Campo(std::string nombre, std::string tipo) : nombre(nombre), tipo(tipo) {}

size_t Campo::hashCampo() const {
    //Fucion hash para campos
    size_t hash = 0;
    for (char c : nombre) {
        hash += c;
    }
    for (char c : tipo) {
        hash += c;
    }
    return hash;
}