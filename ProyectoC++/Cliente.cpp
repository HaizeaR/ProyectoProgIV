/*
 * Cliente.cpp
 *
 *  Created on: May 4, 2020
 *      Author: Haizea
 */

#include <math.h>
#include "Cliente.h"
#include <string.h>
#include <iostream>
using namespace std;

Cliente::Cliente(const char* dni, const char* nombre, const char* apellido, const char* email, int telefono, const char * tarjeta, int puntos):Usuario(dni, nombre, apellido, email, telefono)
{
	this->tarjeta = new char[strlen(tarjeta) + 1];
	strcpy(this->tarjeta, tarjeta);
	this->puntos = puntos;
}

Cliente::Cliente(const Cliente& c):Usuario(c)
{
	this->tarjeta = new char[strlen(c.tarjeta) + 1];
	strcpy(this->tarjeta, c.tarjeta);
	this->puntos = c.puntos;
}

Cliente::~Cliente()
{
	cout << "Destructor Cliente" << endl;
	delete[] tarjeta;
}

void Cliente::imprimir()
{

	cout << "Datos cliente" << endl;
	cout << "- - - - - - - - " << endl;
	Usuario::imprmir();
	cout << "Tarjeta: " << this->tarjeta << endl;
	cout << "Puntos: " << this->puntos << endl;

}

char * Cliente::getTarjeta()
{
	return this->tarjeta;
}


int Cliente::getPuntos()
{
	return puntos;
}


void Cliente::setPuntos(int puntos)
{
	this->puntos = puntos;
}

void Cliente::incrementarPuntos(float importeReserva)
{

	if (importeReserva > 200){
		this->puntos += 25;
	}else if(importeReserva > 350){
		this->puntos += 50;
	}else if(importeReserva > 450){
		this->puntos += 75;
	}

}

int Cliente::mostrarDescuento()
{
	int descuento = floor(this->puntos / 100);
	if(descuento==0){
		return 1;
	}
	return (descuento * 5) / 100;
}

void Cliente::quemarPuntos()
{
	// cada 100 puntos se descuenta un 5%
	// actualiza los puntos restando los utilizados

	this->puntos -= floor(this->puntos / 100)*100;
}
