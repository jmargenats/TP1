/*
 * movimiento.cpp
 *
 *  Created on: Apr 12, 2022
 *      Author: juli
 */

#include <iostream>
#include <string>
#include "inicializacionTablero.h"
#include "colocarSoldados.h"
using namespace std;

int movimientoVertical(){
	int vertical;
	cout << "Para moverse hacia adelante presione 1, hacia atras presione 2. Para quedarse en el lugar presione 3\n" << endl;
	cin >> vertical;
	return vertical;
}

int movimientoHorizontal(){
	int horizontal;
	cout << "Para moverse hacia la derecha presione 1, hacia la izquierda presione 2. Para quedarse en el lugar presione 3\n" << endl;
	cin >> horizontal;
	return horizontal;
}

void posicionarSoldado(Casillero tablero[ALTO][ANCHO], Soldados soldados[SOLDADOS], int vertical, int horizontal, int numSoldado){
	switch (vertical) {
	//el jugador se mueve hacia adelante
		case 1:
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = ' ';
			--soldados[numSoldado].fila;
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = 'S';
			break;

			//el jugador se mueve hacia atras
		case 2:
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = ' ';
			++soldados[numSoldado].fila;
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = 'S';
			break;

			//el jugador se queda en su lugar
		case 3:
			break;
			//el jugador ingresa un numero incorrecto
		default:
			cout << "El numero debe ser 1, 2 o 3" << endl;
			movimientoVertical();
	}
	switch (horizontal) {

		//el jugador se mueve hacia la derecha
		case 1:
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = ' ';
			++soldados[numSoldado].columna;
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = 'S';
			break;

			//el jugador se mueve hacia la izquierda
		case 2:
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = ' ';
			--soldados[numSoldado].columna;
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = 'S';
			break;

			//el jugador se queda en el lugar
		case 3:
			break;

			//el jugador inngresa un numero incorrecto
		default:
			cout << "El numero debe ser 1, 2 o 3" << endl;
			movimientoHorizontal();
	}
}

void Movimiento(Casillero tablero1[ALTO][ANCHO], Casillero tablero2[ALTO][ANCHO], Soldados soldados[SOLDADOS], int numSoldado, int numJugador){
	int vertical = movimientoVertical();
	int horizontal = movimientoHorizontal();

	//depende de a que jugador le toque, modifica el tablero correspondiente
	if (numJugador == 1){
		posicionarSoldado(tablero1, soldados, vertical, horizontal, numSoldado);
	} else {
		posicionarSoldado(tablero2, soldados, vertical, horizontal, numSoldado);

	}
}


