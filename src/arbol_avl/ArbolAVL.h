//
// Created by vicente on 2/04/24.
//

#ifndef CONTACT_MANAGEMENT_SYSTEM_ARBOLAVL_H
#define CONTACT_MANAGEMENT_SYSTEM_ARBOLAVL_H


#include "../campo/Campo.h"

class ArbolAVL {
private:
    struct Nodo {
        Campo campo;
        Nodo* izquierda;
        Nodo* derecha;
        int altura;

        Nodo(Campo campo) : campo(campo), izquierda(nullptr), derecha(nullptr), altura(1) {}
    };
    const Nodo* obtenerRaiz() const{
        return raiz;
    }

    Nodo* raiz;

    Nodo* insertar(Nodo* nodo, Campo campo);
    Nodo* eliminar(Nodo* nodo, const std::string& nombre);
    Nodo* encontrarMinimo(Nodo* nodo) const;
    int obtenerAltura(Nodo* nodo) const;
    int obtenerBalance(Nodo* nodo) const;
    void actualizarAltura(Nodo* nodo);
    Nodo* rotarDerecha(Nodo* nodo);
    Nodo* rotarIzquierda(Nodo* nodo);
    Nodo* balancear(Nodo* nodo);
    void destruir(Nodo* nodo);

    friend class GeneradorDot;

public:
    ArbolAVL();
    ~ArbolAVL();
    void insertar(Campo campo);
    void eliminar(const std::string& nombre);
    bool buscar(const std::string& nombre) const;
};



#endif //CONTACT_MANAGEMENT_SYSTEM_ARBOLAVL_H
