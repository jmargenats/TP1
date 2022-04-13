/*
 * muestratablero.cpp
 *
 *  Created on: Apr 10, 2022
 *      Author: juli
 */

#include <iostream>
#include <string>
#include "inicializacionTablero.h"
using namespace std;
#include <fstream>


void imprimirTablero(Casillero tablero[ALTO][ANCHO], int num){
	cout << "\nTablero del jugador " << num << ":" << endl << endl;
	for(int i = 0; i < ALTO; ++i){
			for(int j = 0; j < ANCHO; ++j){
				cout << "|" << tablero[i][j].letra << " " << tablero[i][j].numero << " Estado: " <<tablero[i][j].estado<<"| ";
			}
			cout << endl << "------------------------------------------------------------" <<endl;
		}
}

void escribirTexto1(string rutaSalida, int numJugador, Casillero tablero[ALTO][ANCHO]) {

	ofstream salida;
	salida.open(rutaSalida.c_str());

	// escribe el contenido del archivo
	salida << "\nTablero del jugador " << numJugador << ":" << endl << endl;
		for(int i = 0; i < ALTO; ++i){
				for(int j = 0; j < ANCHO; ++j){
					salida << "|" << tablero[i][j].letra << " " << tablero[i][j].numero << " Estado: " <<tablero[i][j].estado<<"| ";
				}
				salida << endl << "-----------------------------------------------------------------------------------------------------------------------" <<endl;
			}

	//cierra el archivo, liberando el recurso
	salida.close();
}

void escribirTexto2(string rutaSalida, int numJugador, Casillero tablero[ALTO][ANCHO]) {

	ofstream salida;
	salida.open(rutaSalida.c_str());

	// escribe el contenido del archivo
	salida << "\nTablero del jugador " << numJugador << ":" << endl << endl;
		for(int i = 0; i < ALTO; ++i){
				for(int j = 0; j < ANCHO; ++j){
					salida << "|" << tablero[i][j].letra << " " << tablero[i][j].numero << " Estado: " <<tablero[i][j].estado<<"| ";
				}
				salida << endl << "-----------------------------------------------------------------------------------------------------------------------" <<endl;
			}

	// cierra el archivo, liberando el recurso
	salida.close();
}
