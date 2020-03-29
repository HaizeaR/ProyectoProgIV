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




// guarda los datos en un fichero de texto

void FicheroTexto (Reserva * reserva){

	FILE * fo ;
	// a es para que se siga escribiendo y no se borre
	fo = fopen("Reserva2", "a");

	fprintf(fo, "\nReserva\n");
	fprintf(fo, "- - - - - - - - - - -\n");
	fprintf(fo,"Nombre: %s, ", reserva->nombre);
	fprintf(fo, "DNI: %s, ", reserva->dni);
	fprintf(fo, "Correo: %s, ", reserva->correo);
	fprintf(fo, "Tarjeta: %i, ", reserva->tarjeta);
	fprintf(fo, "Destino: %i, ", reserva->destino);
	fprintf(fo, "Fecha Inicio: %s, ", reserva->fechaI);
	fprintf(fo, "Numero de noches: %i, ", reserva->numeroNoches);
	fprintf(fo, "Número de adultos: %i, ", reserva->adultos);
	fprintf(fo, "Número de nños: %i, ", reserva->ninos);
	fprintf(fo, "Cuna: %i, ", reserva->cuna);
	fprintf(fo, "Tipo de pensión: %i, ", reserva->pension);
	fprintf(fo, "Parking: %i, ", reserva->parking);
	fprintf(fo, "Importe: %.2f €.\n",  reserva->importe);

	fclose(fo);
}


//void FicheroBinario (Reserva * reserva){
//
//		FILE * fo;
//
//		fo = fopen("reserva", "ab" ); // abierto fichero en formato escritura
//
//		fwrite(reserva, sizeof(Reserva), 1, fo);
//
//		fclose(fo);
//
//		fo = fopen("reserva", "rb" );
//
//		//fread(reserva, sizeof(reserva), 1, fo);
//		fread(&reserva, sizeof(reserva), 1, fo);
//}


int main(void) {

	// Inicializar una reserva

	Reserva * reserva = (Reserva*)malloc(sizeof(Reserva));

	// inicializar array de char de la reserva

	reserva->dni = (char*)malloc(sizeof(char)*9);
	reserva->nombre = (char*)malloc(sizeof(char)*20);
	reserva->correo = (char*)malloc(sizeof(char)*25);
	reserva->fechaI = (char*)malloc(sizeof(char)*15);


	seleccionarDestino(reserva);
	seleccionarFechas(reserva);
	seleccionarPersonas(reserva);
	seleccionarPension(reserva);
	seleccionarParking(reserva);
	calcularImporte(reserva);
	resumenDeDatos(reserva);

	if ( continuarCompra() == 1){
		datosComprador(reserva);
		mostrarDatosComprador(reserva);
		printf("¡Gracias por su compra!\n\n");
		// solo guardamos las reservas confirmadas y completadas
		// si le da a cancelar NO guarda en fichero
		FicheroTexto(reserva);

	}else{
		printf("Su reserva ha sido cancelada\n ");
	}


	// LIBERAR MEMORIA

	free(reserva);
	free(reserva->correo);
	free(reserva->dni);
	free(reserva->fechaI);
	free(reserva->nombre);



	printf("Fin del programa.");

	return 0;

}


