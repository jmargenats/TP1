/*
 * turnos.h
 *
 *  Created on: Apr 12, 2022
 *      Author: juli
 */

#ifndef TURNOS_H_
#define TURNOS_H_

#include <iostream>
#include <string>
#include "inicializacionTablero.h"

//arregla el contador en caso de iniciar con un soldado muerto
void arreglarContador(Soldados soldados[3], int contadorSoldados);

//llama a las funciones y modifica los estados del tablero y el los soldados.
void turnos(Casillero tablero1[Alto][Ancho], Casillero tablero2[Alto][Ancho], Soldados soldados1[3], Soldados soldados2[3]);




#endif /* TURNOS_H_ */
