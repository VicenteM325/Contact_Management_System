#include "ArbolAVL.h"
#include <algorithm>

ArbolAVL::ArbolAVL() : raiz(nullptr) {}

ArbolAVL::~ArbolAVL() {
    destruir(raiz);
}

void ArbolAVL::insertar(Campo campo) {
    raiz = insertar(raiz, campo);
}


bool ArbolAVL::buscar(const std::string& nombre) const {
    Nodo* actual = raiz;
    while (actual != nullptr) {
        if (actual->campo.nombre == nombre)
            return true;
        else if (nombre < actual->campo.nombre)
            actual = actual->izquierda;
        else
            actual = actual->derecha;
    }
    return false;
}

ArbolAVL::Nodo* ArbolAVL::insertar(Nodo* nodo, Campo campo) {
    if (nodo == nullptr)
        return new Nodo(campo);

    if (campo.nombre < nodo->campo.nombre)
        nodo->izquierda = insertar(nodo->izquierda, campo);
    else if (campo.nombre > nodo->campo.nombre)
        nodo->derecha = insertar(nodo->derecha, campo);
    else
        return nodo; // Duplicado, no permitido

    return balancear(nodo);
}

ArbolAVL::Nodo* ArbolAVL::eliminar(Nodo* nodo, const std::string& nombre) {
    if (nodo == nullptr)
        return nullptr;

    if (nombre < nodo->campo.nombre)
        nodo->izquierda = eliminar(nodo->izquierda, nombre);
    else if (nombre > nodo->campo.nombre)
        nodo->derecha = eliminar(nodo->derecha, nombre);
    else {
        if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
            delete nodo;
            return nullptr;
        }
        if (nodo->izquierda == nullptr || nodo->derecha == nullptr) {
            Nodo* temp = (nodo->izquierda != nullptr) ? nodo->izquierda : nodo->derecha;
            *nodo = *temp;
            delete temp;
            return nodo;
        }
        Nodo* temp = encontrarMinimo(nodo->derecha);
        nodo->campo = temp->campo;
        nodo->derecha = eliminar(nodo->derecha, temp->campo.nombre);
    }

    return balancear(nodo);
}

ArbolAVL::Nodo* ArbolAVL::encontrarMinimo(Nodo* nodo) const {
    while (nodo->izquierda != nullptr)
        nodo = nodo->izquierda;
    return nodo;
}

int ArbolAVL::obtenerAltura(Nodo* nodo) const {
    return (nodo != nullptr) ? nodo->altura : 0;
}

int ArbolAVL::obtenerBalance(Nodo* nodo) const {
    return (nodo != nullptr) ? obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha) : 0;
}

void ArbolAVL::actualizarAltura(Nodo* nodo) {
    nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));
}

ArbolAVL::Nodo* ArbolAVL::rotarDerecha(Nodo* nodo) {
    Nodo* nuevaRaiz = nodo->izquierda;
    nodo->izquierda = nuevaRaiz->derecha;
    nuevaRaiz->derecha = nodo;
    actualizarAltura(nodo);
    actualizarAltura(nuevaRaiz);
    return nuevaRaiz;
}

ArbolAVL::Nodo* ArbolAVL::rotarIzquierda(Nodo* nodo) {
    Nodo* nuevaRaiz = nodo->derecha;
    nodo->derecha = nuevaRaiz->izquierda;
    nuevaRaiz->izquierda = nodo;
    actualizarAltura(nodo);
    actualizarAltura(nuevaRaiz);
    return nuevaRaiz;
}

ArbolAVL::Nodo* ArbolAVL::balancear(Nodo* nodo) {
    actualizarAltura(nodo);
    int factorBalance = obtenerBalance(nodo);

    if (factorBalance > 1) {
        if (obtenerBalance(nodo->izquierda) < 0)
            nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }
    if (factorBalance < -1) {
        if (obtenerBalance(nodo->derecha) > 0)
            nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void ArbolAVL::destruir(Nodo* nodo) {
    if (nodo != nullptr) {
        destruir(nodo->izquierda);
        destruir(nodo->derecha);
        delete nodo;
    }
}
