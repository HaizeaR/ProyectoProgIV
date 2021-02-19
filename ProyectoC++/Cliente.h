/*
 * Cliente.h
 *
 *  Created on: May 4, 2020
 *      Author: Unai , Mireya y Haizea
 */

#ifdef __cplusplus
#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Usuario.h"

class Cliente:public Usuario{

private:
  char * tarjeta;
  int puntos;

public:

  Cliente(const char * dni, const char * nombre, const char * apellido, const char * email, int telefono, const char * tarjeta, int puntos);
  Cliente(const Cliente &c);
  virtual ~Cliente();
  char * getTarjeta();
  int getPuntos();
  void setPuntos(int puntos);
  void incrementarPuntos(float importeReserva);
  int mostrarDescuento();
  void quemarPuntos();
  virtual void imprimir();

};

#endif /* CLIENTE_H_ */
#endif
