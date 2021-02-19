/*
 * Reserva.h
 *
 *  Created on: May 7, 2020
 *      Author: Haizea
 */

#ifndef RESERVA_H_
#define RESERVA_H_

#include "sqlite3.h"

// estructura con todos los datos
// de una reserva

typedef struct{

	// DATOS DE VIAJE
	int id_hotel; // hotel
	//char * fechaI;
	int dia;
	int mes;
	int ano;
	int numeroNoches;
	int adultos;
	int ninos;
	int cuna;
	int pension; // id pension ( tabla )
	int parking;
	// DATOS COMPRADOR
	//int tarjeta;
	char * dni;
	//char * nombre;
	//char * correo;
	//IMPORTE
	//Cliente  c;
	float importe;

}Reserva;


void clearIfNeeded(char *str, int max_line);

void seleccionarDestino(Reserva * reserva);

void seleccionarFechas(Reserva * reserva);

void seleccionarPersonas(Reserva * reserva);

void seleccionarPension(Reserva * reserva);

void seleccionarParking(Reserva *  reserva);

void calcularImporte(Reserva * reserva);

void resumenDeDatos(Reserva * reserva);

int continuarCompra();

void resumenReserva(Reserva * reserva);


#endif /* RESERVA_H_ */
