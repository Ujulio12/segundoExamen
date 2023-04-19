#include <iostream>
#include "Usuario.h.h"
using namespace std;

int main()
{
// Mostrar el menu general
        cout << "Bienvenido " << nombreUsuario << endl;
        cout << "--------------" << endl;
        cout << "|Menu General|" << endl;
        cout << "--------------" << endl;
        cout << "1. Catalogos" << endl;
        cout << "--------------" << endl;
        cout << "2. Informes" << endl;
        cout << "--------------" << endl;
        cout << "3. Salir " << endl;
        cout << "--------------" << endl;
        int opcion;
        cin >> opcion;
        switch (opcion) {
            case 1: {
                // Mostrar el submenú de catálogos
                system("cls");
                cout << "--------------------------" << endl;
                cout << "Submenu de Catalogos" << endl;
                cout << "--------------------------" << endl;
                cout << "1. CRUD de estructuras" << endl;
                cout << "--------------------------" << endl;
                cout << "2. Volver al menu general" << endl;
                cout << "--------------------------" << endl;
                int opcionC;
                cin >> opcionC;
                switch (opcionC) {
                    case 1: {
                        // Mostrar las opciones de CRUD
                        system("cls");
                        cout << "CRUD de estructuras" << endl;
                        cout << "--------------------" << endl;
                        cout << "1. Agregar" << endl;
                        cout << "--------------------" << endl;
                        cout << "2. Eliminar" << endl;
                        cout << "--------------------" << endl;
                        cout << "3. Modificar" << endl;
                        cout << "--------------------" << endl;
                        cout << "4. Consulta" << endl;
                        cout << "--------------------" << endl;
                        break;
                    }
                    case 2: {
                        // Volver al menú general
                        break;
                    }
                    default: {
                        // Opción inválida
                        cout << "Opcion invalida" << endl;
                        break;
                    }
                }
                break;
            }
            case 2: {
                // Mostrar el submenú de informes
                cout << "Submenu de Informes" << endl;
                cout << "--------------" << endl;
                cout << "1. Impresion a TXT de estructuras" << endl;
                cout << "2. Volver al menu general" << endl;
                int opcionInformes;
                cin >> opcionInformes;
                switch (opcionInformes) {
                    case 1: {
                        // Realizar la impresión a TXT
                        cout << "Impresion a TXT de estructuras" << endl;
                        break;
                    }
                    case 2: {
                        // Volver al menú general
                        break;
                    }
                    default: {
                        // Opción inválida
                        cout << "Opcion invalida" << endl;
                        break;
                    }
                }
                break;
            }
            case 3: {
                // Salir del sistema
                cout << "Saliendo del sistema..." << endl;
                break;
            }
            default: {
                // Opción inválida
                cout << "OPCION NO EXISTE" << endl;
                cout << "Intente de nuevo." << endl;
                break;
            }
            }
}
