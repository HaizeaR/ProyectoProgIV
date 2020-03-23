/*
 * main.c
 *
 *  Created on: Feb 22, 2020
 *      Author: Haizea
 */


// Prueba de repositorio

#include <stdio.h>


// structura con todos los datos
// de una reserva
typedef struct{
	int idReserva;
	//char nombre[];
	char correo[];
	// ...

}Reserva;


// manu de opciones de reserva

// Mostrar rserva final


int main(void) {


	printf("Bienvenido a la cadena de hoteles ... \n\n");
	// \n\n doble salto de linea

	int opcion;
	// Meter ciudades en Array ?? y si pongo 1 saque el de la pos 0 ?
	// realmente hacer con BD
	do{
		printf("¿Dónde quieres ir? \n" );

			printf( " \t1. Madrid \n"
					" \t2. Barcelona\n"
					" \t3. Bilabo\n"
					" \t4. Sevilla\n\n" );

			printf("Introduce tu opción:  " );
			   scanf( "%d", &opcion );
			  // printf("%d", opcion);


	}while ( opcion >= 5 );

    return 0;

}


