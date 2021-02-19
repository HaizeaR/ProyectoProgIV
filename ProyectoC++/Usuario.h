/*
 * Usuario.h
 *
 *  Created on: May 4, 2020
 *      Author: Unai, Mireya y Haizea
 */

#ifndef USUARIO_H_
#define USUARIO_H_

class Usuario{

protected:

	char * dni;
	char * nombre;
	char * apellido;
	char * email;
	int  telefono;


public:

	Usuario(const char * dni, const char * nombre, const char * apellido, const char * email, int telefono);
	Usuario(const Usuario &u);
	virtual ~Usuario();
	char*  getNombre();
	char*  getApellido();
	char*  getDni();
	int    getTelefono();
	char*  getEmail();
	virtual void imprmir();

};


#endif /* USUARIO_H_ */
