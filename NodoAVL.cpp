//
// Created by vicente on 2/04/24.
//

#include "NodoAVL.h"

NodoAVL::NodoAVL(const Campo& campo) : campo(campo), izquierdo(nullptr), derecho(nullptr), altura(1) {}

AVL::AVL() : raiz(nullptr) {}

int AVL::altura(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return nodo->altura;
}

int AVL::balance(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return altura(nodo->izquierdo) - altura(nodo->derecho);
}

NodoAVL* AVL::rotarDerecha(NodoAVL* nodo) {
    // Implementación de rotación a la derecha
}

NodoAVL* AVL::rotarIzquierda(NodoAVL* nodo) {
    // Implementación de rotación a la izquierda
}

NodoAVL* AVL::insertar(NodoAVL* nodo, const Campo& campo) {
    // Implementación de la inserción en el árbol AVL
}

bool AVL::buscar(NodoAVL* nodo, const std::string& nombre, const std::string& tipo) {
    // Implementación de la búsqueda en el árbol AVL
}

void AVL::destruirArbol(NodoAVL* nodo) {
    // Implementación de la destrucción del árbol AVL
}

AVL::~AVL() {
    destruirArbol(raiz);
}

void AVL::insertar(const Campo& campo) {
    raiz = insertar(raiz, campo);
}

bool AVL::buscar(const std::string& nombre, const std::string& tipo) {
    return buscar(raiz, nombre, tipo);
}