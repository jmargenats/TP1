/*
 * principal.cpp
 *
 *  Created on: Apr 5, 2022
 *      Author: juli
 */

#include <iostream>
#include <string>
#include "inicializacionTablero.h"
#include "muestraTablero.h"
#include "colocarSoldados.h"
#include "atacar.h"
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

void turnos(Casillero tablero1[Alto][Ancho], Casillero tablero2[Alto][Ancho], Soldados soldados1[3], Soldados soldados2[3]){
	int contadorJugador = 1;
	int contadorSoldados1 = 0;
	int contadorSoldados2 = 0;
	while ((soldados1[0].estado == 'V' ||
			soldados1[1].estado == 'V' ||
			soldados1[2].estado == 'V') &&
			(soldados2[0].estado == 'V' ||
			 soldados2[1].estado == 'V' ||
			 soldados2[2].estado == 'V')){
		//jugador1
		if (contadorJugador % 2 != 0){
			pedirAtaque(tablero1, tablero2, soldados2);
			Movimiento( tablero1,  tablero2,  soldados1 , 0);
			if (verificarPosicionSoldados(tablero1, tablero2, soldados1[0].fila, soldados1[0].columna) == true){
				cout << " \nEsa posicion era utilizada por un soldado enemigo, ambos moriran y la celda quedara inactiva" << endl;
				soldados1[0].estado = 'M'; // M representa los soldados muertos
				soldados2[0].estado = 'M';
				tablero1[soldados1[0].fila][soldados1[0].columna].estado = 'X'; //x representa el inactivo
				tablero2[soldados1[0].fila][soldados1[0].columna].estado = 'X';
			}
			++contadorSoldados1;
			if (contadorSoldados1 == 3){
				contadorSoldados1 = 0;
			}
		}
		//jugador 2
		if (contadorJugador % 2 == 0){
			pedirAtaque(tablero1, tablero2, soldados2);
			Movimiento( tablero1,  tablero2,  soldados1 , 0);
			if (verificarPosicionSoldados(tablero1, tablero2, soldados1[0].fila, soldados1[0].columna) == true){
				cout << " \nEsa posicion era utilizada por un soldado enemigo, ambos moriran y la celda quedara inactiva" << endl;
				soldados1[0].estado = 'M'; // M representa los soldados muertos
				soldados2[0].estado = 'M';
				tablero1[soldados1[0].fila][soldados1[0].columna].estado = 'X'; //x representa el inactivo
				tablero2[soldados1[0].fila][soldados1[0].columna].estado = 'X';
			}
			++contadorSoldados2;
			if (contadorSoldados2 == 3){
				contadorSoldados2 = 0;
			}
		}

	}
}

int main (){
	Casillero tablero1[Alto][Ancho], tablero2[Alto][Ancho];
	Soldados soldados1[3], soldados2[3];
	inicializarTablero(tablero1);
	inicializarTablero(tablero2);
	imprimirTablero(tablero1, 1);
	imprimirTablero(tablero2, 2);
	colocarSoldados(tablero1, tablero2, soldados1, soldados2);
	imprimirTablero(tablero1, 1);
	imprimirTablero(tablero2, 2);
	turnos( tablero1,  tablero2,  soldados1,  soldados2);
	return 0;
}



