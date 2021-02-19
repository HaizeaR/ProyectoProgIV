/*
* main.cpp
*
* Created on: May 5, 2020
* Author: Unai, Mireya y Haizea
*/

extern "C" {
#include "sqlite3.h"
#include "Reserva.h"
}

#include "Cliente.h"
#include "Admin.h"
#include "BD.h"

#include <math.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


Cliente * registrarCliente(){

	char * nombre = new char[30];
	char * apellido = new char[30];
	char * dni = new char[10];
	int telefono;
	char * email = new char[50];
	char * tarjeta = new char[17];

	cout << "\nIntroduce los datos del nuevo cliente\n" << endl;
	cout << "Nombre: " << endl;
	cin >> nombre;
	cout << "\nApellido: " << endl;
	cin >> apellido;
	cout << "\nDNI: " << endl;
	cin >> dni;
	cout << "\nTelefono: " << endl;
	cin >> telefono;
	cout << "\nEmail: " << endl;
	cin >> email;
	cout << "\nTarjeta: " << endl;
	cin >> tarjeta;

	cout << "\nDatos del nuevo cliente:\n" << endl;
	cout << nombre << ", " << apellido << ", " << dni << ", " << telefono << ", "
			<< email << ", " << tarjeta << endl;

	Cliente * c = new Cliente(dni, nombre, apellido, email, telefono, tarjeta, 0);
	return c;

}


int main(void) {

	// CREAR BD
	// INTRODUCIR DATOS BD

	int rc;
	sqlite3 *db;

	// Abrir base de datos
	rc = sqlite3_open("hoteles.db", &db);
	if(rc != SQLITE_OK) {
		cout << "Error: No se puede abrir la base de datos" << endl;
		return 1;
	}

	if (VerificarTablas(db)==false){
		CrearTablas(db);

		//// INSERT DEFAULT VALUES ////
		// Hotel
		rc = insertDefaultHotel(db);
		if (rc != SQLITE_OK) {
			return rc;
		}
		// Admin
		rc = insertDefaultAdmin(db);
		if (rc != SQLITE_OK) {
			return rc;
		}
		// Cliente
		rc = insertDefaultCliente(db);
		if (rc != SQLITE_OK) {
			return rc;
		}
		// Pension
		rc = insertDefaultPension(db);
		if (rc != SQLITE_OK) {
			return rc;
		}
		// Reserva
		rc = insertDefaultReserva(db);
		if (rc != SQLITE_OK) {
			return rc;
		}

	}



	int opcion = 0;

	//Reserva * reserva = (Reserva*)malloc(sizeof(Reserva));
	Reserva * reserva = new Reserva[sizeof(Reserva)];
	reserva->dni = new char[10];


	cout << "Bienvenido!\n" << endl;
	cout << "1. Entrar como Admin" << endl;
	cout << "2. Realizar Compra\n" << endl;
	cout << "Introduce tu opción: " << endl;
	cin >> opcion;

	if (opcion == 1){
		// Entrar como Admin
		int opcionAdmin;

		char * dni = new char[30];
		cout << "\nIntroduce el DNI del adminitrador:" << endl;
		cin >> dni;

		if ( selectNombreAdmin(db, dni) != -1){
			// Admin encontrado en BD
			Admin *a = selectAdmin(db, dni);

			while(opcionAdmin != 0){

			cout << "\n1. Mostrar reservas por DNI" << endl;
			cout << "2. Borrar una reserva" << endl;
			cout << "3. CHECK IN" << endl;
			cout << "4. CHECK OUT" << endl;
			cout << "5. Insertar nuevo hotel" << endl;
			cout << "6. Insertar nuevo Admin" << endl;
			cout << "7. Borrar Admin" << endl;
			cout << "0. Salir\n" << endl;
			cout << "Selecciona tu opción: " << endl;
			cin >> opcionAdmin;
			cout << " " << endl;

			if (opcionAdmin == 1){
				// Mostrar reservas por DNI

				char * dni = new char[30];
				cout << "\nIntroduce el DNI del cliente: " << endl;
				cin >> dni;
				mostrarReservasDNI(db, dni);

			}else if(opcionAdmin == 2){
				// Borrar una reserva

				int id_reserva;
				cout << "\nIntroduce el ID de la reserva: " << endl;
				cin >> id_reserva;

				borrarReserva(db, id_reserva);
				cout <<"\nReserva borrada correctamente\n" << endl;

			}else if(opcionAdmin == 3){
				// CHECK IN

				int opcionCI;
				cout << "\n¿Qué habitación quieres asignar?\n" << endl;
				cout << "1. Habitación Doble " << endl;
				cout << "2. Habitación Triple " << endl;
				cout << "3. Habitación Familiar " << endl;
				cout << "\nIntroduce tu opción: " << endl;
				cin >> opcionCI;

				decrementarHabitacion(db, a, opcionCI);
				cout <<"\nCheck In realizado correctamente\n" << endl;

			}else if(opcionAdmin == 4){
				// CHECK OUT

				int opcionCO;
				cout << "\n¿En que habitación se alojaba?\n" << endl;
				cout << "1. Habitación Doble " << endl;
				cout << "2. Habitación Triple " << endl;
				cout << "3. Habitación Familiar " << endl;
				cout << "Introduce tu opción: " << endl;
				cin >> opcionCO;

				incrementarHabitacion(db, a, opcionCO);
				cout <<"\nCheck Out realizado correctamente\n" << endl;

			}else if(opcionAdmin == 5){
				// Insertar nuevo hotel

				char * nombre = new char[30];
				char * direccion = new char[40];
				char * ciudad = new char[20];
				int hDoble;
				int hTriple;
				int hFamiliar;

				cout << "\nDatos del nuevo hotel\n" << endl;
				cout << "Introduce el nombre: " << endl;
				cin >> nombre;
				cin.ignore();
				cout << "\nIntroduce la direccion: " << endl;
				cin >> direccion;
				cout << "\nIntroduce la ciudad: " << endl;
				cin.ignore();
				cin >> ciudad;
				cout << "\n¿De cuántas habitaciones dobles dispone? " << endl;
				cin >> hDoble;
				cout << "\n¿De cuántas habitaciones triples dispone? " << endl;
				cin >> hTriple;
				cout << "\n¿De cuántas habitaciones familiares dispone? " << endl;
				cin >> hFamiliar;


				cout << "\nResumen del nuevo hotel: " << nombre << ", " << direccion << ", "
						<< ciudad << ", " << hDoble << ", " << hTriple << ", "
						<< hFamiliar << endl;

				insertHotel(db, nombre, direccion, ciudad, hDoble, hTriple, hFamiliar);
				cout <<"\nHotel insertado correctamente\n" << endl;

			}else if (opcionAdmin == 6){
				// Insertar nuevo Admin

				char * nombre = new char[30];
				char * apellido = new char[30];
				char * dni = new char[10];
				int telefono;
				char * email = new char[50];
				int id_hotel;

				cout << "\nDatos del nuevo administrador\n" << endl;
				cout << "Nombre: " << endl;
				cin >> nombre;
				cout << "\nApellido: " << endl;
				cin >> apellido;
				cout << "\nDNI: " << endl;
				cin >> dni;
				cout << "\nTelefono: " << endl;
				cin >> telefono;
				cout << "\nEmail: " << endl;
				cin >> email;
				cout << "\nid_hotel: " << endl;
				cin >> id_hotel;

				cout << "\nDatos del nuevo administrador:\n" << endl;
				cout << nombre << ", " << apellido << ", " << dni << ", " << telefono << ", "
					<< email << ", " << id_hotel << endl;

				Admin * aNew = new Admin(dni, nombre, apellido, email, telefono, id_hotel);

				insertAdmin(db, aNew);
				cout <<"\nAdministrador insertado correctamente\n" << endl;

			}else if (opcionAdmin == 7){
				// Borrar Admin

				char * dni = new char[30];
				cout << "\nIntroduce el DNI del administrador: " << endl;
				cin >> dni;

				borrarAdmin(db, dni);
				cout <<"\nAdministrador borrador correctamente\n" << endl;

			}

			}
		}else{
			// Admin no encontrado en BD

			cout << "\nLo siento, no eres un adminsitrador\n" << endl;
		}


	}else if(opcion == 2){
		// Realizar compra

		cin.ignore();

		cout << "\n¿A qué hotel quieres ir?\n" << endl;
		mostrarHoteles(db);
		seleccionarDestino(reserva);
		seleccionarFechas(reserva);
		seleccionarPersonas(reserva);
		cout << "¿Qué pesión deseas?\n" << endl;
		mostrarPensiones(db);
		seleccionarPension(reserva);
		seleccionarParking(reserva);
		calcularImporte(reserva);
		resumenDeDatos(reserva);

		if (continuarCompra() == true){
			// método que pida los datos al usuario apra crear un cliente
			int cliente;
			cout << "¿Eres ya cliente?\n" << endl;
			cout << "1. Si" << endl;
			cout << "2. No, quiero registrarme\n" << endl;
			cout << "Introduce tu opción: " << endl;
			cin >> cliente;

			if (cliente == 1){
				// eres cliente
				char * dni = new char[30];
				cout << "\nIntroduce DNI: " << endl;
				cin >> dni;

				if(selectDNICliente(db, dni)!=-1){
					// cliente encontrado en BD

					Cliente * c = selectCliente(db, dni);

					cout << " " << endl;

					cout << "\nDipones de " << c->getPuntos() << " puntos" << endl;

					//resumenReserva(reserva);

					float importeDescuento = c->mostrarDescuento() * reserva->importe;

					cout << "El importe con descuento es el siguente: " << importeDescuento << endl;

					cout << "\n¿Quieres usar tus puntos de descuento?" << endl;


					int opcionPts;
					cout << "1. Si" << endl;
					cout << "2. No" << endl;
					cout << "Introduce tu opción: " << endl;
					cin >> opcionPts;

					if (opcionPts == 1){
						// usar puntos

						c->quemarPuntos();
						reserva->importe = importeDescuento;
						reserva->dni = c->getDni();

						insertReserva(db, reserva);
						cout << "Reserva finalizada" << endl;

					}else if(opcionPts == 2){
						// no usar puntos

						c->incrementarPuntos(reserva->importe);
						cout << "\nAhora dispones de " << c->getPuntos() << " puntos\n" << endl;

						reserva->dni = c->getDni();
						insertReserva(db, reserva);
						cout << "Reserva finalizada\n" << endl;
					}

				} else {
					// cliente no encontrado en BD

					cout << "\nCliente no encontrado" << endl;
					Cliente * cNuevo = registrarCliente();

					cNuevo->incrementarPuntos(reserva->importe);
					cout << "\nAhora dispones de " << cNuevo->getPuntos() << " puntos\n" << endl;

					insertCliente(db, cNuevo);
					cout << "Cliente insertado correctamente\n" << endl;

					reserva->dni = cNuevo->getDni();
					insertReserva(db, reserva);
					cout << "Reserva finalizada\n" << endl;
				}

			}else if (cliente == 2 ){
				// no eres cliente
				// registrar un nuevo cliente

				Cliente * cNuevo = registrarCliente();

				cNuevo->incrementarPuntos(reserva->importe);
				cout << "\nAhora dispones de " << cNuevo->getPuntos() << " puntos\n" << endl;

				insertCliente(db, cNuevo);
				reserva->dni = cNuevo->getDni();
				cout << "Cliente insertado correctamente\n" << endl;

				insertReserva(db, reserva);
				cout << "Reserva finalizada\n" << endl;
			}
		}
	}

	cout << "Fin del programa." << endl;
	free(reserva);



	return 0;

}
