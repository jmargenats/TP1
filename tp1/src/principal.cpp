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
using namespace std;


int main (){
	Casillero tablero1[Alto][Ancho], tablero2[Alto][Ancho];
	inicializarTablero(tablero1);
	Soldados soldados1[3];
	Soldados soldados2[3];
	inicializarTablero(tablero2);
	imprimirTableroInicial(tablero1, 1);
	colocarSoldados(tablero1, tablero2, soldados1, soldados2);
	//imprimirTableroInicial(tablero2, 2);
	return 0;
}



