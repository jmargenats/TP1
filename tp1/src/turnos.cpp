/*
 * turnos.cpp
 *
 *  Created on: Apr 12, 2022
 *      Author: juli
 */

#include <iostream>
#include <string>
#include "inicializacionTablero.h"
#include "colocarSoldados.h"
#include "atacar.h"
#include "movimiento.h"
using namespace std;


void arreglarContador(Soldados soldados[3], int contadorSoldados){
	while (soldados[contadorSoldados].estado == 'M'){
		if (contadorSoldados == 2){
			contadorSoldados = 0;
		} else {
			++contadorSoldados;
		}
	}
}


void turnos(Casillero tablero1[Alto][Ancho], Casillero tablero2[Alto][Ancho], Soldados soldados1[3], Soldados soldados2[3]){
	int contadorJugador = 1;
	int contadorSoldados1 = 0;
	int contadorSoldados2 = 0;
	while ((soldados1[0].estado == 'V' ||
			soldados1[1].estado == 'V' ||
			soldados1[2].estado == 'V') &&
			(soldados2[0].estado == 'V' ||
			 soldados2[1].estado == 'V' ||
			 soldados2[2].estado == 'V')){
		arreglarContador(soldados1, contadorSoldados1);
		arreglarContador(soldados2, contadorSoldados2);
		//jugador1
		if (contadorJugador == 1){
			pedirAtaque(tablero1, tablero2, soldados2);
			Movimiento( tablero1,  tablero2,  soldados1 , contadorSoldados1);
			if (verificarPosicionSoldados(tablero1, tablero2, soldados1[contadorSoldados1].fila, soldados1[contadorSoldados1].columna) == true){
				cout << " \nEsa posicion era utilizada por un soldado enemigo, ambos moriran y la celda quedara inactiva" << endl;
				soldados1[contadorSoldados1].estado = 'M'; // M representa los soldados muertos
				matarSoldadoCorrecto(soldados2, soldados1[contadorSoldados1].fila, soldados1[contadorSoldados1].columna);
				tablero1[soldados1[contadorSoldados1].fila][soldados1[contadorSoldados1].columna].estado = 'X'; //x representa el inactivo
				tablero2[soldados1[contadorSoldados1].fila][soldados1[contadorSoldados1].columna].estado = 'X';
			}
			contadorJugador = 2;
			++contadorSoldados1;
			if (contadorSoldados1 >= 3){
				contadorSoldados1 = 0;
			}
		}

		//jugador 2
		if (contadorJugador == 2){
			pedirAtaque(tablero1, tablero2, soldados2);
			Movimiento( tablero1,  tablero2,  soldados1 , contadorSoldados2);
			if (verificarPosicionSoldados(tablero1, tablero2, soldados1[contadorSoldados2].fila, soldados1[contadorSoldados2].columna) == true){
				cout << " \nEsa posicion era utilizada por un soldado enemigo, ambos moriran y la celda quedara inactiva" << endl;
				matarSoldadoCorrecto(soldados1, soldados2[contadorSoldados2].fila, soldados2[contadorSoldados2].columna); // M representa los soldados muertos
				soldados2[contadorSoldados2].estado = 'M';
				tablero1[soldados1[contadorSoldados2].fila][soldados1[contadorSoldados2].columna].estado = 'X'; //x representa el inactivo
				tablero2[soldados1[contadorSoldados2].fila][soldados1[contadorSoldados2].columna].estado = 'X';
			}
			contadorJugador = 1;
			++contadorSoldados2;
			if (contadorSoldados2 >= 3){
				contadorSoldados2 = 0;
			}
		}

	}
}


