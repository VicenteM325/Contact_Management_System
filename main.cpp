#include <iostream>
#include <regex>
#include <string>
#include "Grupo.h"
#include "TablaHash.h"
#include "TablaHashCampos.h"

using namespace std;

int main() {
    // Expresiones regulares
    regex nuevoGrupo("ADD NEW-GROUP (\\w+) FIELDS \\((.*)\\);");
    regex nuevoContacto(R"(ADD CONTACT IN (\w+) FIELDS \(([\w, -]+)\);)");
    regex buscarContacto(R"(FIND\s+CONTACT\s+IN\s+(\w+)\s+CONTACT-FIELD\s+(\w+)=(\w+);)");

    // Tabla hash para almacenar grupos
    TablaHash tabla;
    // Tabla hash para campos
    TablaHashCampos tablaCampos;

    // Variables para entrada del usuario
    string entrada;
    string conti;
    char opcion;
    bool continuar = true;
    // Ciclo para ingresar entradas del usuario
    while (continuar) {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Agregar un nuevo grupo" << endl;
        cout << "2. Agregar un nuevo contacto" << endl;
        cout << "3. Buscar un contacto" << endl;
        cout << "4. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1': {
                do {
                    cout
                            << "Ingrese los datos del nuevo grupo en el formato 'ADD NEW-GROUP <nombre> FIELDS (campo1 tipo1, campo2 tipo2, ...);'"
                            << endl;
                    cin.ignore(); // Limpiar el buffer de entrada
                    getline(cin, entrada);

                    // Procesamiento de entrada
                    smatch matches;
                    if (regex_match(entrada, matches, nuevoGrupo)) {
                        Grupo *nuevo_grupo = new Grupo(matches[1].str());

                        // Parsear campos
                        string campos_str = matches[2].str();
                        regex campo_regex("([\\w-]+)\\s+(STRING|INTEGER|CHAR)");
                        auto campos_begin = sregex_iterator(campos_str.begin(), campos_str.end(), campo_regex);
                        auto campos_end = sregex_iterator();
                        for (sregex_iterator i = campos_begin; i != campos_end; ++i) {
                            string nombre = (*i)[1].str();
                            string tipo = (*i)[2].str();
                            nuevo_grupo->agregarCampo(nombre, tipo);
                            tablaCampos.agregarCampo(nombre, tipo);
                        }

                        // Agregar nuevo grupo a la tabla hash
                        tabla.agregarGrupo(nuevo_grupo);
                        cout << "Porcentaje ocupado de la tabla hash: " << tabla.porcentajeOcupacion() << "%" << endl;
                    } else {
                        cout << "Entrada no válida." << endl;
                    }
                    cout << "Si desea ingresar otro grupo (s/n): ";
                    cin>> conti;
                }while(conti != "n" && conti != "N");
                break;
            }
            case '2': {
                do {
                    cout<< "Ingrese los datos del nuevo contacto en el formato 'ADD CONTACT IN <nombre_grupo> FIELDS (contacto1, contacto2, ...);'"<< endl;
                    cin.ignore(); // Limpiar el buffer de entrada
                    getline(cin, entrada);

                    // Procesamiento de entrada
                    smatch matches;
                    if (regex_match(entrada, matches, nuevoContacto)) {
                        string nombreGrupo = matches[1].str();
                        string nuevoContacto = matches[2].str();

                        // Buscar el grupo correspondiente en la tabla hash
                        Grupo *grupo = tabla.buscarGrupo(nombreGrupo);

                        // Verificar si se encontró el grupo
                        if (grupo != nullptr) {
                            // Agregar el nuevo contacto al grupo
                            grupo->agregarContacto(nuevoContacto);
                        } else {
                            cout << "El grupo '" << nombreGrupo << "' no existe." << endl;
                        }
                    } else {
                        cout << "Entrada no válida." << endl;
                    }
                    cout << "Si desea ingresar otro grupo (s/n): ";
                    cin>> conti;
                }while(conti !="N" && conti !="n");

                break;
            }
            case '3':
                do{
                    cout << "Ingrese el nombre del grupo y el campo a buscar en el formato 'FIND CONTACT IN <nombre_grupo> CONTACT-FIELD <campo>=<valor>;'" << endl;
                    cin.ignore();
                    getline(cin, entrada);

                    smatch matches;
                    if (regex_match(entrada, matches, buscarContacto)) {
                        string nombreGrupo = matches[1].str();
                        string campo = matches[2].str();

                        // Buscar el grupo correspondiente en la tabla hash
                        Grupo* grupo = tabla.buscarGrupo(nombreGrupo);

                        // Verificar si se encontró el grupo
                        if (grupo != nullptr) {
                            // Buscar contactos en el campo especificado
                            grupo->buscarContactos(campo);
                        } else {
                            cout << "El grupo '" << nombreGrupo << "' no existe." << endl;
                        }
                    }
                    else {
                        cout << "Entrada no válida." << endl;
                    }
                    cout << "Si desea ingresar otro grupo (s/n): ";
                    cin>> conti;
                }while(conti !="N" && conti !="n");
                break;
            case '4':
                continuar = false;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    }

    // Liberar la memoria asignada a los grupos
    for (int i = 0; i < TablaHash::CAPACIDAD_INICIAL; ++i) {
        for (Grupo* grupo : *tabla.obtenerTabla()) {
            delete grupo;
        }
    }

    return 0;
}