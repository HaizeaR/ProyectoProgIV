/*
 * main.c
 *
 *  Created on: Feb 22, 2020
 *      Author: Unai Mendiondo, Mireya Quintana y Haizea Rodriguez
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "menu.h"

#define MAX_LINE 10




int main(void) {

	char * d[4];

	d[0]= (char*)malloc(sizeof(char)*7);



	// d[0] = "Madrid";
	 d[1]= "Barcelona";
	 d[2]= "Bilbao";
	 d[3]= "Sevilla";
	 d[4]= "Granda";






	//Reserva reserva;
	Reserva * reserva[1];

	seleccionarDestino(reserva);
	//mostrarFechas(reserva);
	seleccionarPersonas(reserva);
	seleccionarPension(reserva);
	seleccionarParking(reserva);
	resumenDeDatos(reserva, d);
	if ( continuarCompra() == 1){
		datosComprador(reserva);
		mostrarDatosComprador(reserva);
	}else{
		printf("Su reserva ha sido cancelada\n ");
	}

	// guardar fichero ( escritura )

	// mostrar reservas ( lectura de fichero )




	free(reserva);
	return 0;



}


