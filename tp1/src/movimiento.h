/*
 * movimiento.h
 *
 *  Created on: Apr 12, 2022
 *      Author: juli
 */

#ifndef MOVIMIENTO_H_
#define MOVIMIENTO_H_

#include <iostream>
#include <string>
#include "inicializacionTablero.h"

//le pregunta al usuario si se quiere mover verticalmente
int movimientoVertical();

//le pregunta al usuario si se quiere mover horizontalmente
int movimientoHorizontal();

//dependiendo del ingreso del ususario posiciona el ususario
void posicionarSoldado(Casillero tablero[ALTO][ANCHO], Soldados soldados[SOLDADOS], int vertical, int horizontal, int numSoldado);

//llama al resto de las funciones para concretar el movimiento
void Movimiento(Casillero tablero1[ALTO][ANCHO], Casillero tablero2[ALTO][ANCHO], Soldados soldados[SOLDADOS], int numSoldado, int numJugador);


#endif /* MOVIMIENTO_H_ */
