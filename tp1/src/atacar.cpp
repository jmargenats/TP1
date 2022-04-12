/*
 * atacar.cpp
 *
 *  Created on: Apr 11, 2022
 *      Author: juli
 */


#include <iostream>
#include <string>
#include "inicializacionTablero.h"
#include "colocarSoldados.h"
using namespace std;

void matarSoldadoCorrecto(Soldados soldados[3], int fil, int col){
	if (soldados[0].fila == fil &&
		soldados[0].columna == col	){
		soldados[0].estado = 'M';
	} else if (soldados[1].fila == fil &&
			   soldados[1].columna == col){
		soldados[1].estado = 'M';
	} else {
		soldados[2].estado = 'M';
		}
}

void concretarAtaque(Casillero tablero1[Alto][Ancho], Casillero tablero2[Alto][Ancho], Soldados soldados[3], int fil, int col){
	if (tablero1[fil][col].estado == 'S') {
		matarSoldadoCorrecto(soldados, fil, col);
	}
	tablero1[fil][col].estado = 'X';
	tablero2[fil][col].estado = 'X';
}

void pedirAtaque(Casillero tablero1[Alto][Ancho], Casillero tablero2[Alto][Ancho], Soldados soldados[3]){
	cout << "Elija una casilla para atacar:" << endl;
	int fil = pedirFila();
	int col = pedirColumna();
	concretarAtaque(tablero1, tablero2, soldados, fil, col);
}

