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



