/*
 * Cliente.h
 *
 *  Created on: May 5, 2020
 *      Author: Unai , Mireya y Haizea
 */

#include "Usuario.h"
#include <iostream>
#include <string.h>
using namespace std;

Usuario::Usuario(const char * dni, const char * nombre, const char * apellido, const char * email, int telefono)
{
	//cout << "Constructor Usuario" << endl;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->apellido = new char[strlen(apellido) + 1];
	strcpy(this->apellido, apellido);

	this->dni = new char[strlen(dni) + 1];
	strcpy(this->dni, dni);

	this->telefono = telefono;

	this->email = new char[strlen(email) + 1];
	strcpy(this->email, email);
}

Usuario::Usuario(const Usuario& u)
{
	//cout << "Constructor Copia Usuario" << endl;
	this->nombre = new char[strlen(u.nombre) + 1];
	strcpy(this->nombre, u.nombre);

	this->apellido = new char[strlen(u.apellido) + 1];
	strcpy(this->apellido, u.apellido);

	this->dni = new char[strlen(u.dni) + 1];
	strcpy(this->dni, u.dni);

	this->telefono = u.telefono;

	this->email = new char[strlen(u.email) + 1];
	strcpy(this->email, u.email);
}

Usuario::~Usuario()
{
	//cout << "Destructor Usuario" << endl;
	delete[] nombre;
	delete[] apellido;
	delete[] dni;
	delete[] email;
}

char* Usuario::getNombre()
{
	return this->nombre;
}

char* Usuario::getApellido()
{
	return this->apellido;
}

char* Usuario::getDni()
{
	return this->dni;
}

int Usuario::getTelefono()
{
	return this->telefono;
}

char* Usuario::getEmail()
{
	return this->email;
}

void Usuario::imprmir()
{
	cout << "Nombre: " << this->nombre << endl;
	cout << "Apellido: " << this->apellido << endl;
	cout << "DNI: " << this->dni << endl;
	cout << "Telefono: " << this->telefono << endl;
	cout << "EMAIL: " << this->email << endl;
}
