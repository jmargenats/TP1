/*
 * colocarSoldados.h
 *
 *  Created on: Apr 10, 2022
 *      Author: juli
 */

#ifndef COLOCARSOLDADOS_H_
#define COLOCARSOLDADOS_H_

#include <iostream>
#include <string>
#include "inicializacionTablero.h"

//pasa a posicion de filas la letra que ingrese el usuario
int definirFilas(char letra);

//le pide la letra de la fila al usuario
int pedirFila();

//le pida el numero de columna al usuario
int pedirColumna();

//verifica que la posicion de los soldados no sea la misma
bool verificarPosicionSoldados(Casillero tablero1[Alto][Ancho], Casillero tablero2[Alto][Ancho], int fila, int columna);

//coloca los solados en las casillas, y guarda sus posiciones en otra matriz
void colocarSoldados(Casillero tablero1[Alto][Ancho], Casillero tablero2[Alto][Ancho],Soldados soldados1[3], Soldados soldados2[3]);

#endif /* COLOCARSOLDADOS_H_ */
