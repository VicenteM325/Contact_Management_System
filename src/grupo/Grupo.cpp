
#include <iostream>
#include "Grupo.h"


// Constructor
Grupo::Grupo(std::string nombre) {
    this->nombre = nombre;
    this->cabeza = nullptr;
}

// Método para agregar un nuevo nodo a la lista
void Grupo::agregarCampo(std::string nombre, std::string tipo) {
    Nodo* nuevo_nodo = new Nodo(nombre, tipo);
    if (cabeza == nullptr) {
        cabeza = nuevo_nodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }

}

// Método para agregar un nuevo contacto al grupo
void Grupo::agregarContacto(std::string contacto) {
    contactos.push_back(contacto);
    std::cout << "Nuevo contacto agregado al grupo '" << nombre << "': " << contacto << std::endl;
}



void Grupo::buscarContactos(const std::string& campo) const {
    std::list<std::string> contactosEncontrados;
    for (const auto& contacto : contactos) {
        // Separar el contacto en nombre y valor
        size_t pos = contacto.find(',');
        std::string nombre = contacto.substr(0, pos);
        std::string valor = contacto.substr(pos + 1);

        // Verificar si el nombre del campo coincide
        if (nombre == campo) {
            contactosEncontrados.push_back(valor);
        }
    }

    // Mostrar resultados
    if (!contactosEncontrados.empty()) {
        std::cout << "Contactos encontrados en el campo '" << campo << "':" << std::endl;
        for (const auto& contacto : contactosEncontrados) {
            std::cout << contacto << std::endl;
        }
    } else {
        std::cout << "No se encontraron contactos con el dato '" << campo << "' en el campo especificado." << std::endl;
    }
}
void Grupo::mostrarContactos() const {
    std::cout << "Contactos del grupo '" << nombre << "':" << std::endl;
    for (const auto& contacto : contactos) {
        std::cout << contacto << std::endl;
    }
}


// Destructor
Grupo::~Grupo() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}