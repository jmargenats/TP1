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

void matarSoldadoCorrecto(Soldados soldados[SOLDADOS], int fil, int col){
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

void concretarAtaque(Casillero tablero1[ALTO][ANCHO], Casillero tablero2[ALTO][ANCHO], Soldados soldados[SOLDADOS], int fil, int col){
	if (tablero1[fil][col].estado == 'S') {
		matarSoldadoCorrecto(soldados, fil, col);
		cout << "Felicidades! Mataste a un soldado enemigo" << endl;
	} else if (tablero2[fil][col].estado == 'S'){
		matarSoldadoCorrecto(soldados, fil, col);
		cout << "Felicidades! Mataste a un soldado enemigo" << endl;
	}
	tablero1[fil][col].estado = 'X';
	tablero2[fil][col].estado = 'X';
}

void pedirAtaque(Casillero tablero1[ALTO][ANCHO], Casillero tablero2[ALTO][ANCHO], Soldados soldados[SOLDADOS]){
	cout << "Elija una casilla para atacar:" << endl;
	int fil = pedirFila();
	int col = pedirColumna() - 1;
	concretarAtaque(tablero1, tablero2, soldados, fil, col);
}

