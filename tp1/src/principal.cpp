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
#include "movimiento.h"
#include "turnos.h"
using namespace std;


int main (){
	Casillero tablero1[ALTO][ANCHO], tablero2[ALTO][ANCHO];
	Soldados soldados1[SOLDADOS], soldados2[SOLDADOS];
	string archivoTurnos1 = "texto/salida1.txt";
	string archivoTurnos2 = "texto/salida2.txt";
	inicializarTablero(tablero1);
	inicializarTablero(tablero2);
	imprimirTablero(tablero1, 1);
	imprimirTablero(tablero2, 2);
	colocarSoldados(tablero1, tablero2, soldados1, soldados2);
	imprimirTablero(tablero1, 1);
	imprimirTablero(tablero2, 2);
	turnos( tablero1,  tablero2,  soldados1,  soldados2, archivoTurnos1, archivoTurnos2);
	return 0;
}



