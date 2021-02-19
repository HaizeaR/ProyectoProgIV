/*
 * Bd.cpp
 *
 *  Created on: May 5, 2020
 *      Author: Haizea
 */

#include <string.h>
#include <iostream>
extern "C" {
#include "sqlite3.h"
}
#include "BD.h"
#include "Cliente.h"
#include "Admin.h"

const int nTablas = 5;
using namespace std;

bool VerificarTablas(sqlite3 *db){

    char consulta[36];

    char *tabla[] = {
        "hotel",
        "admin",
        "cliente",
        "pension",
        "reserva"

    };

	   for(int i = 0; i < nTablas; i++) {
	        sprintf(consulta, "SELECT COUNT(*) FROM %s;", tabla[i]);
	        if(SQLITE_OK != sqlite3_exec(db, consulta, 0, 0, 0)) {
	            //cout << "La tabla " << tabla[i] << " no existe." << endl;

	               return false;
	            }
	        }
	    return true;
}


bool CrearTablas(sqlite3 *db) {

    char *tabla[] = {
        "hotel",
        "admin",
        "cliente",
        "pension",
        "reserva"

    };


    char *create[] = {
        "CREATE TABLE hotel("
			  "id_hotel INTEGER PRIMARY KEY AUTOINCREMENT,"
			  "nombre TEXT,"
			  "direccion TEXT,"
			  "ciudad TEXT,"
			  "hDoble INTEGER,"
			  "hTriple INTEGER,"
			  "hFamiliar INTEGER);",

        "CREATE TABLE admin("
		  	  "dni TEXT PRIMARY KEY,"
          	  "nombre TEXT,"
          	  "apellido TEXT,"
          	  "email TEXT,"
		  	  "telefono INTEGER,"
          	  "id_hotel INTEGER);",

		"CREATE TABLE cliente("
			  "dni TEXT PRIMARY KEY,"
			  "nombre TEXT,"
			  "apellido TEXT,"
			  "email TEXT,"
			  "telefono INTEGER,"
			  "tarjeta TEXT,"
			  "puntos INTEGER);",

        "CREATE TABLE pension("
			  "id_pension INTEGER PRIMARY KEY AUTOINCREMENT,"
			  "nombre TEXT,"
			  "descripcion TEXT,"
			  "precio INTEGER);",

        "CREATE TABLE reserva("
			  "id_reserva INTEGER PRIMARY KEY AUTOINCREMENT,"
			  "dni TEXT,"
			  "id_hotel INTEGER,"
			  "dia INTEGER,"
			  "mes INTEGER,"
			  "ano INTEGER,"
			  "numNoches INTEGER,"
			  "adultos INTEGER,"
			  "ninos INTEGER,"
			  "cuna INTEGER,"
			  "parking INTEGER,"
			  "id_pension INTEGER,"
			  "importe FLOAT);"

    };




    for(int i = 0; i < nTablas; i++) {
            if(SQLITE_OK != sqlite3_exec(db, create[i], 0, 0, 0)) {
               cout << "Error al crear la tabla " << tabla[i] << endl;
               return false;
            }

    }

    return true;
}

//// DEFAULT INSERTS ////

int insertDefaultHotel(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into hotel (nombre, direccion, ciudad, hDoble, hTriple, hFamiliar) values ('Bilbao Deusto', 'Francisco Maciá, 9', 'Bilbao', 50, 40, 20),"
			"('Madrid Atocha', 'Paseo Infanta Isabel, 9', 'Madrid', 40, 20, 20),"
			"('Barcelona Calderón', 'Rambla Catalunya, 26', 'Barcelona', 50, 50, 20)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into hotel table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}

int insertDefaultAdmin(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into admin (dni, nombre, apellido, email, telefono, id_hotel) values ('11111111M', 'Mireya', 'Quintana', 'mireyaquintana@gmail.com', 635062019, 1),"
			"('22222222H', 'Haizea', 'Rodriguez', 'haizearodriguez@gmail.com', 654321100, 2),"
			"('33333333U', 'Unai', 'Mendiondo', 'unaimendiondo@gmail.com', 669874222, 3)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into admin table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}


int insertDefaultCliente(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into cliente (dni, nombre, apellido, email, telefono, tarjeta, puntos) values ('11111111A', 'Asier', 'Perallos', 'asierperallos@gmail.com', 693822017, '1234567891234567', 0)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into cliente table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}


int insertDefaultPension(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into pension (nombre, descripcion, precio) values ('Media pensión', 'Desayuno más comida o cena', 1),"
			"('Pensión completa', 'Desayuno, comida y cena', 2),"
			"('Luxury', 'Todo incluido', 4)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into pension table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}

int insertDefaultReserva(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into reserva (dni, id_hotel, dia, mes, ano, numNoches, adultos, ninos, cuna, parking, id_pension, importe) values "
			"('11111111A', 1, 08, 05, 2020, 5, 2, 1, 0, 0, 2, 550.0)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into reserva table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}

//// INSERT ////

int insertCliente(sqlite3 *db, Cliente* c) {
	sqlite3_stmt *stmt;

	char* dni = new char[strlen(c->getDni()) + 1];
	strcpy(dni, c->getDni());

	char* nombre = new char[strlen(c->getNombre()) + 1];
	strcpy(nombre, c->getNombre());

	char* apellido = new char[strlen(c->getApellido()) + 1];
	strcpy(apellido, c->getApellido());

	char* email = new char[strlen(c->getEmail()) + 1];
	strcpy(email, c->getEmail());

	int telefono = c->getTelefono();

	char* tarjeta = new char[strlen(c->getTarjeta()) + 1];
	strcpy(tarjeta, c->getTarjeta());

	int puntos = c->getPuntos();

	char sql[1200];

	sprintf(sql, "insert into cliente (dni, nombre, apellido, email, telefono, tarjeta, puntos) values ('%s', '%s', '%s', '%s', %d, '%s', %d)",
			dni, nombre, apellido, email, telefono, tarjeta, puntos);

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into cliente table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}

int insertAdmin(sqlite3 *db, Admin* a) {
	sqlite3_stmt *stmt;

	char* dni = new char[strlen(a->getDni()) + 1];
	strcpy(dni, a->getDni());

	char* nombre = new char[strlen(a->getNombre()) + 1];
	strcpy(nombre, a->getNombre());

	char* apellido = new char[strlen(a->getApellido()) + 1];
	strcpy(apellido, a->getApellido());

	char* email = new char[strlen(a->getEmail()) + 1];
	strcpy(email, a->getEmail());

	int telefono = a->getTelefono();
	int id_hotel = a->getIdHotel();

	char sql[1000];

	sprintf(sql, "insert into admin (dni, nombre, apellido, email, telefono, id_hotel) values ('%s', '%s', '%s', '%s', %d, %d)",
			dni, nombre, apellido, email, telefono, id_hotel);

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into admin table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}

int insertReserva(sqlite3 *db, Reserva* r) {

	sqlite3_stmt *stmt;

	char* dni = new char[strlen(r->dni) + 1];
	strcpy(dni, r->dni);

	int id_hotel = r->id_hotel;

	int dia = r->dia;

	int mes = r->mes;

	int ano = r->ano;

	int numNoches = r->numeroNoches;

	int adultos = r->adultos;

	int ninos = r->ninos;

	int cuna = r->cuna;

	int parking = r->parking;

	int id_pension = r->pension;

	float importe = r->importe;

	char sql[1000];

	sprintf(sql, "insert into reserva (dni, id_hotel, dia, mes, ano, numNoches, adultos, ninos, cuna, parking, id_pension, importe) "
			"values('%s', %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %f)",
			dni, id_hotel, dia, mes, ano, numNoches, adultos, ninos, cuna, parking, id_pension, importe);

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into reserva table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;

}

int insertHotel(sqlite3 *db, char nombre[], char direccion[], char ciudad[], int hDoble, int hTriple, int hFamiliar) {

	sqlite3_stmt *stmt;

	char sql[1000];

	sprintf(sql, "insert into hotel (nombre, direccion, ciudad, hDoble, hTriple, hFamiliar) values ('%s', '%s', '%s', %d, %d, %d)",
			nombre, direccion, ciudad, hDoble, hTriple, hFamiliar);

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into admin table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;

}


//// SELECT ////

int mostrarHoteles(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select * from hotel";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int id_hotel;
	char nombre[30];
	char direccion[100];
	char ciudad[30];

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id_hotel = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(direccion, (char *) sqlite3_column_text(stmt, 2));
			strcpy(ciudad, (char *) sqlite3_column_text(stmt, 3));
			printf("ID: %d, Nombre: %s, Dirección: %s, Ciudad: %s\n", id_hotel, nombre, direccion, ciudad);
		}
	} while (result == SQLITE_ROW);


	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}

int mostrarPensiones(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select * from pension";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int id_pension;
	char nombre[30];
	char descripcion[100];

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id_pension = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(descripcion, (char *) sqlite3_column_text(stmt, 2));
			printf("ID: %d, Nombre: %s, Descripción: %s\n", id_pension, nombre, descripcion);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}

// mostrar reservas por dni
int mostrarReservasDNI(sqlite3 *db, char dni[]) {
	sqlite3_stmt *stmt;

	int contador = 0;

	char sql_base[] = "select * from reserva where dni = ";

	int longitud1 = strlen(sql_base);
	int longitud2 = strlen(dni);

	char sql[longitud1 + longitud2 + 5];

	sprintf(sql, "select * from reserva where dni = '%s'", dni);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int id_reserva;
	int id_hotel;
	int dia;
	int mes;
	int ano;
	int numNoches;
	int adultos;
	int ninos;
	int cuna;
	int parking;
	int id_pension;
	float importe;

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			contador ++;
			id_reserva = sqlite3_column_int(stmt, 0);
			id_hotel = sqlite3_column_int(stmt, 2);
			dia = sqlite3_column_int(stmt, 3);
			mes = sqlite3_column_int(stmt, 4);
			ano = sqlite3_column_int(stmt, 5);
			numNoches = sqlite3_column_int(stmt, 6);
			adultos = sqlite3_column_int(stmt, 7);
			ninos = sqlite3_column_int(stmt, 8);
			cuna = sqlite3_column_int(stmt, 9);
			parking = sqlite3_column_int(stmt, 10);
			id_pension = sqlite3_column_int(stmt, 11);
			importe = sqlite3_column_int(stmt, 12);
			printf("");
			printf("id_reserva: %d dni: %s id_hotel: %d fechaI: %d/%d/%d numNoches: %d adultos: %d ninos: %d cuna: %d parking: %d id_pension: %d importe: %f\n",
					id_reserva, dni, id_hotel, dia, mes, ano, numNoches, adultos, ninos, cuna, parking, id_pension, importe);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	if(contador == 0){
		printf("No se han encontrado reservas\n");
		return contador;
	}
	return SQLITE_OK;
}

int selectNombreAdmin(sqlite3 *db, char dni[]) {
	sqlite3_stmt *stmt;

	char sql_base[] = "select * from admin where dni = ";

	int longitud1 = strlen(sql_base);
	int longitud2 = strlen(dni);

	char sql[longitud1 + longitud2 + 5];

	sprintf(sql, "select * from admin where dni = '%s'", dni);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	char nombre[30];

	int contador = 0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			contador++;
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			printf("");
			printf("Bienvenid@ %s!\n", nombre);
		}
	} while (result == SQLITE_ROW);
	if(contador==0){
		return -1;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}

int selectDNICliente(sqlite3 *db, char dni[]) {
	sqlite3_stmt *stmt;

	char sql_base[] = "select * from cliente where dni = ";

	int longitud1 = strlen(sql_base);
	int longitud2 = strlen(dni);

	char sql[longitud1 + longitud2 + 5];

	sprintf(sql, "select * from cliente where dni = '%s'", dni);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	char nombre[30];

	int contador = 0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			contador++;
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));

			printf("\nNombre: %s", nombre);
		}
	} while (result == SQLITE_ROW);
	if(contador==0){
		return -1;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	return SQLITE_OK;
}

Cliente* selectCliente(sqlite3 *db, char dni[]) {
	sqlite3_stmt *stmt;

	char sql_base[] = "select * from cliente where dni = ";

	int longitud1 = strlen(sql_base);
	int longitud2 = strlen(dni);

	char sql[longitud1 + longitud2 + 5];

	sprintf(sql, "select * from cliente where dni = '%s'", dni);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	char nombre[30];
	char apellido[30];
	char email[50];
	int telefono;
	char tarjeta[17];
	int puntos;

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(apellido, (char *) sqlite3_column_text(stmt, 2));
			strcpy(email, (char *) sqlite3_column_text(stmt, 3));
			telefono = sqlite3_column_int(stmt, 4);
			strcpy(tarjeta, (char *) sqlite3_column_text(stmt, 5));
			puntos = sqlite3_column_int(stmt, 6);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	Cliente * c = new Cliente(dni, nombre, apellido, email, telefono, tarjeta, puntos);

	return c;
}


Admin* selectAdmin(sqlite3 *db, char dni[]) {
	sqlite3_stmt *stmt;

	char sql_base[] = "select * from admin where dni = ";

	int longitud1 = strlen(sql_base);
	int longitud2 = strlen(dni);

	char sql[longitud1 + longitud2 + 5];

	sprintf(sql, "select * from admin where dni = '%s'", dni);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	char nombre[30];
	char apellido[30];
	char email[50];
	int telefono;
	int id_hotel;

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(apellido, (char *) sqlite3_column_text(stmt, 2));
			strcpy(email, (char *) sqlite3_column_text(stmt, 3));
			telefono = sqlite3_column_int(stmt, 4);
			id_hotel = sqlite3_column_int(stmt, 5);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	Admin * a = new Admin(dni, nombre, apellido, email, telefono, id_hotel);

	return a;
}



//// UPDATE ////
int updateCliente(sqlite3 *db, Cliente* c) {
	sqlite3_stmt *stmt;

		char* dni = new char[strlen(c->getDni()) + 1];
		strcpy(dni, c->getDni());

		int puntos = c->getPuntos();

		char sql[1200];

		sprintf(sql, "update cliente set puntos = %d where dni = '%s'",
				puntos, dni);

		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into cliente table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		return SQLITE_OK;
}


int selectCapacidad(sqlite3 *db, Admin* a, int opcion) {
	sqlite3_stmt *stmt;

	int id_hotel = a->getIdHotel();

	char sql[1200];

	int columna;
	if(opcion==1){
		sprintf(sql, "select * from hotel where id_hotel = %i", id_hotel);
		columna = 4;
	}else if(opcion==2){
		sprintf(sql, "select * from hotel where id_hotel = %i", id_hotel);
		columna = 5;
	}else if(opcion ==3){
		sprintf(sql, "select * from hotel where id_hotel = %i", id_hotel);
		columna = 6;
	}


	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		int capacidad;

		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				capacidad = sqlite3_column_int(stmt, columna);
			}
		} while (result == SQLITE_ROW);

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		return capacidad;
}

int decrementarHabitacion(sqlite3 *db, Admin* a, int opcion) {

	sqlite3_stmt *stmt;

	int capacidad = selectCapacidad(db, a, opcion);

	char sql[1200];

	if(opcion==1){
			sprintf(sql, "update hotel set hDoble = %i where id_hotel = %i", capacidad-1, a->getIdHotel());

		}else if(opcion==2){
			sprintf(sql, "update hotel set hTriple = %i where id_hotel = %i", capacidad-1, a->getIdHotel());
		}else if(opcion ==3){
			sprintf(sql, "update hotel set hFamiliar = %i where id_hotel = %i", capacidad-1, a->getIdHotel());
		}


	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;

}

int incrementarHabitacion(sqlite3 *db, Admin* a, int opcion) {

	sqlite3_stmt *stmt;

	int capacidad = selectCapacidad(db, a, opcion);

	char sql[1200];

	if(opcion==1){
			sprintf(sql, "update hotel set hDoble = %i where id_hotel = %i", capacidad+1, a->getIdHotel());

		}else if(opcion==2){
			sprintf(sql, "update hotel set hTriple = %i where id_hotel = %i", capacidad+1, a->getIdHotel());
		}else if(opcion ==3){
			sprintf(sql, "update hotel set hFamiliar = %i where id_hotel = %i", capacidad+1, a->getIdHotel());
		}


	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;

}



//// DELETE ////
int borrarAdmin(sqlite3 *db, char dni[]) {

	sqlite3_stmt *stmt;

	char sql_base[] = "delete from admin where dni = ";

	int longitud1 = strlen(sql_base);
	int longitud2 = strlen(dni);

	char sql[longitud1 + longitud2 + 5];

	sprintf(sql, "delete from admin where dni = '%s'", dni);


	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;

}

int borrarReserva(sqlite3 *db, int id_reserva) {

	sqlite3_stmt *stmt;

	char sql[1000];

	sprintf(sql, "delete from reserva where id_reserva = '%d'", id_reserva);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;

}
