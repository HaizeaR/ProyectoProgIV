/*
 * Reserva.c
 *
 *  Created on: May 7, 2020
 *      Author: Haizea
 */

#include "Reserva.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRECIO_ADULTO_NOCHE 20
#define PRECIO_NINO_NOCHE 10
#define PRECIO_CUNA 10
#define PRECIO_PARKING 2
#define IVA 0.21
#define MAX_LINE 25


void clearIfNeeded(char *str, int max_line)
{
	// Limpia los caracteres de mÂ·s introducidos
	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
	{
		while (getchar() != '\n');
	}
}


void seleccionarDestino(Reserva * reserva)
{
	char str[MAX_LINE];
	int destino;

	// sacar los datos de BD
	//printf("\t1. Madrid\n");
	//printf("\t2. Barcelona\n");
	//printf("\t3. Bilbao\n");
	//printf("\t4. Sevilla\n");
	//printf("\t5. Granada\n\n");

	printf("\nIntroduce el ID del hotel: ");

	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &destino);
	clearIfNeeded(str, MAX_LINE);

	printf("\n");

	reserva->id_hotel = destino;
}



void seleccionarFechas(Reserva * reserva)
{
	char str[MAX_LINE];

	//char * fI = (char*)malloc(sizeof(char)*15);

	int ano;
	int mes;
	int dia;

	int numeroNoches;

	printf("¿En qué fechas quieres ir?\n\n");

	printf("\tDia: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &dia);
	clearIfNeeded(str, MAX_LINE);

	printf("\n");

	printf("\tMes: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &mes);
	clearIfNeeded(str, MAX_LINE);

	printf("\n");

	printf("\tAño: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &ano);
	clearIfNeeded(str, MAX_LINE);

	printf("\n");

	printf("\tNúmero de noches: ");

	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &numeroNoches);
	clearIfNeeded(str, MAX_LINE);

	printf("\n");

	reserva->dia = dia;
	reserva->mes = mes;
	reserva->ano = ano;
	reserva->numeroNoches = numeroNoches;
}

void seleccionarPersonas(Reserva * reserva)
{
	char str[MAX_LINE];

	int adultos;
	int nino;
	int cuna;

	printf("¿Cuántas personas venís?\n\n");

	printf("\tAdultos: ");

	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &adultos);
	clearIfNeeded(str, MAX_LINE);

	printf("\n");

	printf("\tNiños: ");

	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &nino);
	clearIfNeeded(str, MAX_LINE);

	printf("\n");

	printf("\tCuna: ");

	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &cuna);
	clearIfNeeded(str, MAX_LINE);

	printf("\n");


	reserva->adultos = adultos;
	reserva->ninos = nino;
	reserva->cuna = cuna;
}

void seleccionarPension(Reserva * reserva)
{
	char str[MAX_LINE];
	int pension;

	printf("\nIntroduce el ID de la pensión: ");

	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &pension);
	clearIfNeeded(str, MAX_LINE);

	printf("\n");

	reserva->pension = pension;
}

void seleccionarParking(Reserva * reserva)
{
	char str[MAX_LINE];
	int parking;

	printf("¿Quieres contratar servicio de parking? \n\n");
	printf("\t0. No\n");
	printf("\t1. Si\n");

	printf("\n");

	printf("Parking (0/1): ");

	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &parking);
	clearIfNeeded(str, MAX_LINE);

	printf("\n");

	reserva->parking = parking;
}

void calcularImporte(Reserva * reserva)
{

	int adultos = reserva->adultos;
	int ninos = reserva->ninos;
	int parking = reserva->parking;
	int pension = reserva->pension;
	int cuna = reserva->cuna;
	int noches = reserva->numeroNoches;
	int destino = reserva->id_hotel;

	float importePension = 0;
	float importeConIVA = 0;

	if (pension == 1){
		importePension = 1;
	}else if (pension == 2){
		importePension = 2;
	}else if (pension == 3){
		importePension = 4;
	}


	float importe = ((((adultos * PRECIO_ADULTO_NOCHE) + (ninos * PRECIO_NINO_NOCHE)  ) * noches) * importePension)+ ((parking * PRECIO_PARKING )* noches) + (cuna * PRECIO_CUNA);

	importeConIVA = importe * (1 + IVA);

	reserva->importe = importeConIVA;

}

// creo que funciona sin *
// modificar hay que darle una vuelta a este mÃ©todo
void resumenDeDatos(Reserva * reserva)
{
	printf("\t--------------------\n");
	printf("\t| RESUMEN DE DATOS |\n");
	printf("\t--------------------\n\n");
	printf("\tID del hotel: %i", reserva->id_hotel);

	printf("\n");

	printf("\tFecha Inicio: %i/%i/%i\n", reserva->dia, reserva->mes, reserva->ano);
	printf("\tNumero de noches: %i\n\n", reserva->numeroNoches);

	printf("\tHuespedes\n");
	printf("\t- - - - - - -\n");
	printf("\tAdultos: %i \n", reserva->adultos);
	printf("\tNiños: %i\n", reserva->ninos);
	printf("\tCuna: %i \n\n", reserva->cuna);

	printf("\tTipo de pension: ");

	if ( reserva->pension == 1){
		printf("Media\n");
	}else if ( reserva->pension == 2){
		printf("Completa\n");
	}else if ( reserva->id_hotel == 3){
		printf("Luxury\n");
	}
	printf("\n");


	printf("\tParking: ");
	if ( reserva->parking == 0){
		printf("No\n");

	}else if ( reserva->parking == 1){
		printf("Si\n");
	}
	printf("\n");


	printf("\tPRECIO con IVA: ");
	printf("%.2f € \n ", reserva->importe);

	printf("\t----------------------- \n\n");
}

int continuarCompra()
{
	char str[MAX_LINE];
	int opcion;


	printf("¿Quieres continuar con la reserva? \n\n");

	printf("\t1. Si\n");
	printf("\t2. No\n");

	printf("\n");


	//printf("REVISAR OPCIONES SELECIONADAS ARRIBA \n");
	//printf("-------------------------------------------\n");


	//printf("\n- - - - - - - \n");
	printf("Opción (1/2): ");


	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &opcion);
	clearIfNeeded(str, MAX_LINE);
	printf("\n- - - - - - - \n");
	printf("\n");

	return opcion;
}

void resumenReserva(Reserva * reserva)
{
	int personas = reserva->adultos+reserva->ninos;
	printf("Id_Hotel %i. Fecha Inicio: %i/%i/%i. Num huespedes: %i\n", reserva->id_hotel, reserva->dia, reserva->mes, reserva->ano,personas);
	printf("Importe: %.2f € \n", reserva->importe);
}
