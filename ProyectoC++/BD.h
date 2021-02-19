/*
 * BD.h
 *
 *  Created on: 5 may. 2020
 *      Author: HP
 */

#ifdef __cplusplus
#ifndef BD_H_
#define BD_H_

#include "sqlite3.h"
#include "Cliente.h"
#include "Reserva.h"
#include "Admin.h"


bool VerificarTablas(sqlite3 *db);
bool CrearTablas(sqlite3 *db);


//// DEFAULT INSERTS ////
int insertDefaultHotel(sqlite3 *db);
int insertDefaultAdmin(sqlite3 *db);
int insertDefaultCliente(sqlite3 *db);
int insertDefaultPension(sqlite3 *db);
int insertDefaultReserva(sqlite3 *db);


//// INSERT ////
int insertCliente(sqlite3 *db, Cliente* c);
int insertAdmin(sqlite3 *db, Admin* a);
int insertReserva(sqlite3 *db, Reserva* r);
int insertHotel(sqlite3 *db, char nombre[], char direccion[], char ciudad[], int hDoble, int hTriple, int hFamiliar);


//// SELECT ////
int mostrarHoteles(sqlite3 *db);
int mostrarPensiones(sqlite3 *db);
int mostrarReservasDNI(sqlite3 *db, char dni[]);
//int mostrarReservasCiudad(sqlite3 *db, char ciudad[]);
int selectNombreAdmin(sqlite3 *db, char dni[]);
int selectDNICliente(sqlite3 *db, char dni[]);
Cliente* selectCliente(sqlite3 *db, char dni[]); // ?? comprobar si funciona
Admin* selectAdmin(sqlite3 *db, char dni[]);


//// UPDATE ////
int updateCliente(sqlite3 *db, Cliente* c);
int selectCapacidad(sqlite3 *db, Admin* a, int opcion);
int decrementarHabitacion(sqlite3 *db, Admin* a, int opcion);
int incrementarHabitacion(sqlite3 *db, Admin* a, int opcion);


//// DELETE ////
int borrarAdmin(sqlite3 *db, char dni[]);
int borrarReserva(sqlite3 *db, int id_reserva);


#endif /* BD_H_ */
#endif
