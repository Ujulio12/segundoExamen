#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

// Definir la estructura Usuario
struct Usuario {
    string nombre;
    string contrasena;
};
struct Catalogo{
    string nombrepro;
    string precio;
};

// Función para verificar si un usuario ya existe en el archivo
bool usuarioEncontrado(string nombreUsuario) {
    ifstream archivoUsuarios("nombresUsuarios.txt");
    bool existe = false;
    Usuario usuarioActual;
    while (archivoUsuarios >> usuarioActual.nombre >> usuarioActual.contrasena) {
        if (usuarioActual.nombre == nombreUsuario) {
            existe = true;
            break;
        }
    }
    archivoUsuarios.close();
    return existe;
}

// Función para autenticar a un usuario
bool autenticarUsuario(string nombreUsuario, string contrasena) {
    ifstream archivoUsuarios("nombresUsuarios.txt");
    bool autenticado = false;
    Usuario usuarioActual;
    while (archivoUsuarios >> usuarioActual.nombre >> usuarioActual.contrasena) {
        if (usuarioActual.nombre == nombreUsuario && usuarioActual.contrasena == contrasena) {
            autenticado = true;
            break;
        }
    }
    archivoUsuarios.close();
    return autenticado;
}

// Función para agregar un usuario al archivo
void agregarUsuario(string nombreUsuario, string contrasena) {
    ofstream archivoUsuarios("nombresUsuarios.txt", ios_base::app);
    archivoUsuarios << nombreUsuario << " " << contrasena << endl;
    archivoUsuarios.close();
}

int main() {
    // Crear el usuario "Administrador" si no existe
    if (!usuarioEncontrado("Julio")) {
        agregarUsuario("Julio", "1205");
    }
    // Pedir al usuario que ingrese su nombre y contraseña
    string nombreUsuario, contrasena;
    cout << "Ingrese su nombre de usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;
    // Autenticar al usuario
    if (autenticarUsuario(nombreUsuario, contrasena)) {
        // Mostrar el menu general
        system("cls");
        cout << "Bienvenido, " << nombreUsuario << endl;
        cout << "Menu General" << endl;
        cout << "--------------" << endl;
        cout << "1. Catalogos" << endl;
        cout << "2. Informes" << endl;
        cout << "3. Salir del sistema" << endl;
        int opcionM;
        cin >> opcionM;
        switch (opcionM) {
            case 1: {
                system("cls");
                // Mostrar el submenú de catálogos
                cout << "Submenu de Catalogos" << endl;
                cout << "--------------" << endl;
                cout << "1. CRUD de estructuras" << endl;
                cout << "2. Volver al menu general" << endl;
                int opcionC;
                cin >> opcionC;
                switch (opcionC) {
                    case 1: {
                        system("cls");
                        // Mostrar las opciones de CRUD
                        cout << "CRUD de estructuras" << endl;
                        cout << "--------------" << endl;
                        cout << "1. Alta" << endl;
                        cout << "2. Baja" << endl;
                        cout << "3. Modificacion" << endl;
                        cout << "4. Consulta" << endl;
                        cout << "5. Salir"<< endl;
                        int opcionE;
                        cin>>opcionE;
                        switch (opcionE)
                        {
                        case 1:
                            string name;
                            int precio;
                            system("cls");
                            fstream file;
                            cout<<"\n------------------------------------------------------------------------------------------------------------------------";
                            cout<<"\n-------------------------------------------------Agregar detalles Producto ---------------------------------------------"<<endl;
                            cout<<"\t\t\tIngresa Nombre Producto     : ";
                            cin>>name;
                            cout<<"\t\t\tIngresa Direccion Persona  : ";
                            cin>>precio;
                            file.open("catalogo.txt", ios::app | ios::out);
                            file<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< precio << "\n";
                            file.close();
                            break;
                        case 2:

                            break;
                        case 3:
                        fstream file;
                        int total = 0;
                        cout << "\n-------------------------Tabla de Detalles de Usuarios -------------------------" << endl;
                        file.open("Catalogo.txt",ios::in);
                        if(!file)
                        {
                        cout << "\n\t\t\tNo hay información...";
                        file.close();
                        }
                        else
                        {
                        file >>name >> precio;
                        while(!file.eof())
                        {
                        total++;
                        cout << "\t\t\t Nombre Prdocuto: " << name << endl;
                        cout << "\t\t\t Precio: " << precio <<endl;
                        file >> name >> precio;
                        }
                        if(total == 0)
                        {
                        cout<<"\n\t\t\tNo hay informacion...";
                        }
                        file.close();


                            break;
                        case 4:

                            break;
                        case 5:

                            break;
                        }
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
                system("cls");
                cout << "Submenu de Informes" << endl;
                cout << "--------------" << endl;
                cout << "1. Impresion a TXT de estructuras" << endl;
                cout << "2. Volver al menu general" << endl;
                int opcionInformes;
                cin >> opcionInformes;
                switch (opcionInformes) {
                    case 1: {
                        // Realizar la impresión a TXT
                        cout << "Estructuras" << endl;
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
                cout << "Opcion invalida" << endl;
                break;
            }
        }
    }
    } else {
        // Credenciales inválidas
        cout << "Usuario invalido" << endl;
    }
    return 0;
}
