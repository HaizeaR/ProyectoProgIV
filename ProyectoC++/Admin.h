/*
 * Cliente.h
 *
 *  Created on: May 4, 2020
 *      Author: Unai , Mireya y Haizea
 */

#ifdef __cplusplus
#ifndef ADMIN_H__
#define ADMIN_H__

#include "Usuario.h"

class Admin:public Usuario{

private:
	int id_hotel;

public:

	Admin(const char * dni, const char * nombre, const char * apellido, const char * email, int telefono, int id_hotel);
	Admin(const Admin &a);
	virtual ~Admin();
	int getIdHotel();
	virtual void imprimir();

};

#endif /* ADMIN_H_ */
#endif
