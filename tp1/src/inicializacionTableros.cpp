/*
 * InicializacionTableros.cpp
 *
 *  Created on: Apr 10, 2022
 *      Author: juli
 */
#include <iostream>
#include <string>
#include "inicializacionTablero.h"
using namespace std;


char asignarLetra(int num){
	char letra = 'A';
	switch(num){
		case 0: letra = 'A'; break;
		case 1: letra = 'B'; break;
		case 2: letra = 'C'; break;
		case 3: letra = 'D'; break;
		case 4: letra = 'E'; break;
		case 5: letra = 'F'; break;
		case 6: letra = 'G'; break;
		case 7: letra = 'H'; break;
		case 8: letra = 'I'; break;
		default: letra = 'J'; break;
	}
	return letra;
}


void inicializarTablero(Casillero tablero[Alto][Ancho]){
	for(int i = 0; i < Alto; ++i){
		char letra = asignarLetra(i);
		for(int j = 0; j < Ancho; ++j){
			tablero[i][j].letra = letra;
			tablero[i][j].numero = j+1;
			tablero[i][j].estado = "desconocido";
		}
	}
}


