/*
 * Cliente.h
 *
 *  Created on: May 5, 2020
 *      Author: Unai , Mireya y Haizea
 */

#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin(const char * dni, const char * nombre, const char * apellido, const char * email, int telefono, int id_hotel): Usuario(dni, nombre, apellido, email, telefono)
{
	this->id_hotel = id_hotel;
}

Admin::Admin(const Admin& a):Usuario(a)
{
	this->id_hotel = a.id_hotel;
}

Admin::~Admin()
{
	cout << "Destructor Admin" << endl;
}
void Admin::imprimir()
{

	cout << "Datos Administrador" << endl;
	cout << "- - - - - - - - " << endl;
	Usuario::imprmir();
	cout << "ID HOTEL:" << this->id_hotel <<endl;
	cout << " " << endl;

}

int Admin::getIdHotel()
{
	return id_hotel;
}


