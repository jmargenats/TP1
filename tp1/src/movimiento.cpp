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

void posicionarSoldado(Casillero tablero[Alto][Ancho], Soldados soldados[3], int vertical, int horizontal, int numSoldado){
	switch (vertical) {
		case 1:
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = ' ';
			tablero[soldados[numSoldado].fila + 1][soldados[numSoldado].columna].estado = 'S';
			++soldados[numSoldado].fila;
			break;
		case 2:
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = ' ';
			tablero[soldados[numSoldado].fila - 1][soldados[numSoldado].columna].estado = 'S';
			--soldados[numSoldado].fila;
			break;
		case 3:
			break;
		default:
			cout << "El numero debe ser 1, 2 o 3" << endl;
			movimientoVertical();
	}
	switch (horizontal) {
		case 1:
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = ' ';
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna + 1].estado = 'S';
			++soldados[numSoldado].columna;
			break;
		case 2:
			tablero[soldados[numSoldado].fila][soldados[numSoldado].columna].estado = ' ';
			tablero[soldados[numSoldado].fila - 1][soldados[numSoldado].columna - 1].estado = 'S';
			--soldados[numSoldado].columna;
			break;
		case 3:
			break;
		default:
			cout << "El numero debe ser 1, 2 o 3" << endl;
			movimientoHorizontal();
	}
}

void Movimiento(Casillero tablero1[Alto][Ancho], Casillero tablero2[Alto][Ancho], Soldados soldados[3], int numSoldado){
	int vertical = movimientoVertical();
	int horizontal = movimientoHorizontal();
	posicionarSoldado(tablero1, soldados, vertical, horizontal, numSoldado);
}


