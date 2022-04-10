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

void imprimirTableroInicial(Casillero tablero[Alto][Ancho], int num){
	cout << "Tablero del jugador " << num << ":" << endl;
	for(int i = 0; i < Alto; ++i){
			for(int j = 0; j < Ancho; ++j){
				cout << "|" << tablero[i][j].letra << " " << tablero[i][j].numero << "| ";
			}
			cout << endl << "------------------------------------------------------------" <<endl;
		}
}

