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

void imprimirTablero(Casillero tablero[Alto][Ancho], int num){
	cout << "\nTablero del jugador " << num << ":" << endl << endl;
	for(int i = 0; i < Alto; ++i){
			for(int j = 0; j < Ancho; ++j){
				cout << "|" << tablero[i][j].letra << " " << tablero[i][j].numero << " Estado: " <<tablero[i][j].estado<<"| ";
			}
			cout << endl << "------------------------------------------------------------" <<endl;
		}
}

