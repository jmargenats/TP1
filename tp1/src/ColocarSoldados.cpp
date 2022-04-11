/*
 * ColocarSoldados.cpp
 *
 *  Created on: Apr 10, 2022
 *      Author: juli
 */

#include <iostream>
#include <string>
#include "inicializacionTablero.h"
using namespace std;



int definirFilas(char letra){
	int fila = 0;
	switch (letra){
		case 65: fila = 0; break; //Letra 'A' en ASCII
		case 66: fila = 1; break; //Letra 'B' en ASCII
		case 67: fila = 2; break; //Letra 'C' en ASCII
		case 68: fila = 3; break; //Letra 'D' en ASCII
		case 69: fila = 4; break; //Letra 'E' en ASCII
		case 70: fila = 5; break; //Letra 'F' en ASCII
		case 71: fila = 6; break; //Letra 'G' en ASCII
		case 72: fila = 7; break; //Letra 'H' en ASCII
		case 73: fila = 8; break; //Letra 'I' en ASCII
		case 74: fila = 9; break; //Letra 'J' en ASCII
		default: fila = 10; // devuelve un numero que servira para informarle al usuario que el ingreso no es valido
	}
	return fila;
}

int pedirFila(){
	char letra;
	int fila;
	do {
		cout << "\nIngrese la fila: ";
		cin >> letra;
		 fila = definirFilas(letra);
		//en caso de que el ingreso sea invalido, definirFilas devolvera 10
		if (fila == 10){
			cout << "\nLa fila debe ser una letra desde la 'A' a la 'J' en mayuscula"<< endl;
		}
	} while (fila == 10);

	return fila;
}

int pedirColumna(){
	int col;
	do {
		cout << "Ingrese la columna: ";
		cin >> col;
		if (col >= 11){
			cout << "\nLa columna debe ser un numero desde el '1' al '10'"<< endl;
		}
	} while (col >= 11);
	return col;
}

bool verificarPosicionSoldados(Casillero tablero1[Alto][Ancho], Casillero tablero2[Alto][Ancho], int fila, int columna){
	if (tablero1[fila][columna].estado == tablero2[fila][columna].estado) {
		return true;
	} else {
		return false;
	}
}

void colocarSoldados(Casillero tablero1[Alto][Ancho], Casillero tablero2[Alto][Ancho], Soldados soldados1[3], Soldados soldados2[3]){
	cout << "\nIngresar la posicion de los soldados del primer jugador" << endl;
	for (int i = 1; i < 4; ++i){
		cout << "\nIngrese el casillero del soldado nuemro " << i;
		int fil = pedirFila();
		int col = pedirColumna() - 1;
		soldados1[i-1].fila = fil;
		soldados1[i-1].columna = col;
		soldados1[i-1].estado = 'V'; // V significa que el soldado esta vivo
		tablero1[fil][col].estado = 'S'; // S represetna que ahi hay un soldado
		if (verificarPosicionSoldados(tablero1, tablero2, fil, col) == true){
			cout << " \nEsa posicion era utilizada por un soldado enemigo, ambos moriran y la celda quedara inactiva" << endl;
			soldados1[i-1].estado = 'M'; // M representa los soldados muertos
			soldados2[i-1].estado = 'M';
			tablero1[fil][col].estado = 'X'; //x representa el inactivo
			tablero2[fil][col].estado = 'X';
		}
	}
	cout << "\nIngresar la posicion de los soldados del segundo jugador" << endl;
	for (int i = 1; i < 4; ++i){
		cout << "\nIngrese el casillero del soldado nuemro " << i;
		int fil = pedirFila();
		int col = pedirColumna() - 1;
		soldados2[i-1].fila = fil;
		soldados2[i-1].columna = col;
		soldados2[i-1].estado = 'V'; // V significa que el soldado esta vivo
		tablero2[fil][col].estado = 'S'; // S represetna que ahi hay un soldado
		if (verificarPosicionSoldados(tablero1, tablero2, fil, col) == true){
			cout << " \nEsa posicion era utilizada por un soldado enemigo, ambos moriran y la celda quedara inactiva" << endl;
			soldados1[i-1].estado = 'M';
			soldados2[i-1].estado = 'M'; // M representa los soldados muertos
			tablero1[fil][col].estado = 'X';
			tablero2[fil][col].estado = 'X'; //x representa el inactivo
		}
	}
}


