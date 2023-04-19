#include "Usuario.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

Usuario::Usuario()
{
    //ctor
}

void Usuario::modificar()
{
	system("cls");
	fstream file,file1;
	string nameUsuario, codigo;
	int found=0, opcion;
	cout<<"\n-------------------------Modificacion Detalles Usuario-------------------------"<<endl;
	file.open("nombresUsuarios.txt",ios::in);
	cout<<"\n Ingrese su nombre de usuario: ";
    cin>>nameUsuario;
    cout<<" Ingrese la contraseña: ";
    cin>>codigo;
    file1.open("Record.txt",ios::app | ios::out);
    file >> nombre >> contrasena;
    while(!file.eof())
    {
        if(nameUsuario!=nombre && codigo!=contrasena){
         file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena << "\n";
        }
        else{
            cout << "\n\tQue desea modificar?" << endl;
            cout << "\t1. Usuario" << endl;
            cout << "\t2. Contraseña" << endl;
            cout << "\tIngrese una opcion" << endl;
            cin >> opcion;
            if (opcion == 1){
                cout<<"\n Ingrese su nombre de usuario: ";
                cin>>nombre;
                file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<<std::left<<std::setw(15)<< score<< "\n";
                found++;
            }
            else{
                if (opcion == 2){
                    cout<<" Ingrese la contraseña: ";
                    cin>>contrasena;
                }
            file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<<std::left<<std::setw(15)<< score << "\n";
            found++;
            }
        }
        file >> nombre >> contrasena;
    }
    if(found==0)
    {
        cout<<"\n\t\t\t Usuario no encontrado...";
    }
    file1.close();
    file.close();
    remove("nombresUsuarios.txt");
    rename("Record.txt","nombresUsuarios.txt");
}
