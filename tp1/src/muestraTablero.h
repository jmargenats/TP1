/*
 * muestraTablero.h
 *
 *  Created on: Apr 10, 2022
 *      Author: juli
 */

#ifndef MUESTRATABLERO_H_
#define MUESTRATABLERO_H_

#include <iostream>
#include <string>
#include "inicializacionTablero.h"

//escribe el tablero en un txt
void escribirTexto1(std::string rutaSalida, int numJugador, Casillero tablero[ALTO][ANCHO]);
void escribirTexto2(std::string rutaSalida, int numJugador, Casillero tablero[ALTO][ANCHO]);

//le muestra el tablero inicial al usuario
void imprimirTablero(Casillero tablero[ALTO][ANCHO], int num);


#endif /* MUESTRATABLERO_H_ */
