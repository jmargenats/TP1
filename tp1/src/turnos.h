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
int arreglarContador(Soldados soldados[SOLDADOS], int contadorSoldados);

//llama a las funciones y modifica los estados del tablero y el los soldados.
void turnos(Casillero tablero1[ALTO][ANCHO], Casillero tablero2[ALTO][ANCHO], Soldados soldados1[SOLDADOS], Soldados soldados2[SOLDADOS], std::string rutaSalida1, std::string rutaSalida2);




#endif /* TURNOS_H_ */
