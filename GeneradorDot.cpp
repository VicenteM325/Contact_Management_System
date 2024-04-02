#include <iostream>
#include <fstream>
#include <string>
#include "arbol_avl/ArbolAVL.h"

class GeneradorDot {
public:
    static void generarArchivoDot(const ArbolAVL& arbol, const std::string& nombreArchivo) {
        std::ofstream archivo(nombreArchivo);
        if (!archivo) {
            std::cerr << "Error al abrir el archivo." << std::endl;
            return;
        }

        archivo << "digraph ArbolAVL {" << std::endl;
        generarNodos(arbol.obtenerRaiz(), archivo);
        generarConexiones(arbol.obtenerRaiz(), archivo);
        archivo << "}" << std::endl;
    }

private:
    static void generarNodos(const ArbolAVL::Nodo* nodo, std::ofstream& archivo) {
        if (nodo == nullptr)
            return;

        archivo << "    " << nodo->campo.nombre << " [label=\"" << nodo->campo.nombre << "\"];" << std::endl;
        generarNodos(nodo->izquierda, archivo);
        generarNodos(nodo->derecha, archivo);
    }

    static void generarConexiones(const ArbolAVL::Nodo* nodo, std::ofstream& archivo) {
        if (nodo == nullptr)
            return;

        if (nodo->izquierda != nullptr)
            archivo << "    " << nodo->campo.nombre << " -> " << nodo->izquierda->campo.nombre << ";" << std::endl;

        if (nodo->derecha != nullptr)
            archivo << "    " << nodo->campo.nombre << " -> " << nodo->derecha->campo.nombre << ";" << std::endl;

        generarConexiones(nodo->izquierda, archivo);
        generarConexiones(nodo->derecha, archivo);
    }
};