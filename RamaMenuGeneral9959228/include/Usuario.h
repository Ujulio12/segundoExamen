#ifndef USUARIO_H
#define USUARIO_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
class Usuario
{
	private:
		string nombre, contrasena;
	public:
		void iniciarSesion();
		void menuSecundario();
		void insertar();
		void modificar();
		void borrar();


};


#endif // USUARIO_H
