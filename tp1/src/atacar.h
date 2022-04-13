/*
 * atacar.h
 *
 *  Created on: Apr 11, 2022
 *      Author: juli
 */

#ifndef ATACAR_H_
#define ATACAR_H_

#include <iostream>
#include <string>
#include "inicializacionTablero.h"

// realiza el ataque, verifica si hay un soldado en la casilla y le cambia el estado, tambien inhabilita la casilla.
void concretarAtaque(Casillero tablero1[ALTO][ANCHO], Casillero tablero2[ALTO][ANCHO], Soldados soldados[SOLDADOS], int fil, int col);

//le pide al usuario las coordinadas del ataque y llama la funcion para verificar.
void pedirAtaque(Casillero tablero1[ALTO][ANCHO], Casillero tablero2[ALTO][ANCHO], Soldados soldados[SOLDADOS]);

//Se asegura de matar el soldado correcto (1, 2 o 3)
void matarSoldadoCorrecto(Soldados soldados[SOLDADOS], int fil, int col);

#endif /* ATACAR_H_ */
