//
// Created by vicente on 2/04/24.
//

#ifndef CONTACT_MANAGEMENT_SYSTEM_NODOAVL_H
#define CONTACT_MANAGEMENT_SYSTEM_NODOAVL_H


#include "campo/Campo.h"

class NodoAVL {
public:
    Campo campo;
    NodoAVL* izquierdo;
    NodoAVL* derecho;
    int altura;

    NodoAVL(const Campo& campo);
};

class AVL {
private:
    NodoAVL* raiz;

    int altura(NodoAVL* nodo);
    int balance(NodoAVL* nodo);
    NodoAVL* rotarDerecha(NodoAVL* nodo);
    NodoAVL* rotarIzquierda(NodoAVL* nodo);
    NodoAVL* insertar(NodoAVL* nodo, const Campo& campo);
    bool buscar(NodoAVL* nodo, const std::string& nombre, const std::string& tipo);
    void destruirArbol(NodoAVL* nodo);

public:
    AVL();
    ~AVL();

    void insertar(const Campo& campo);
    bool buscar(const std::string& nombre, const std::string& tipo);
};

#endif //CONTACT_MANAGEMENT_SYSTEM_NODOAVL_H
