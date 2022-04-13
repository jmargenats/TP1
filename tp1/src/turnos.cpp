/*
 * turnos.cpp
 *
 *  Created on: Apr 12, 2022
 *      Author: juli
 */

#include <iostream>
#include <string>
#include <fstream>
#include "muestraTablero.h"
#include "inicializacionTablero.h"
#include "colocarSoldados.h"
#include "atacar.h"
#include "movimiento.h"
using namespace std;


int arreglarContador(Soldados soldados[SOLDADOS], int contadorSoldados){
	while (soldados[contadorSoldados].estado == 'M'){
		if (contadorSoldados == 2){
			contadorSoldados = 0;
		} else {
			++contadorSoldados;
		}
	}

	return contadorSoldados;
}


void turnos(Casillero tablero1[ALTO][ANCHO], Casillero tablero2[ALTO][ANCHO], Soldados soldados1[SOLDADOS], Soldados soldados2[SOLDADOS], string rutaSalida1, string rutaSalida2){
	// dictamina quien empieza jugando
	int contadorJugador = 1;

	//dictamina cual soldado del jugador uno se movera
	int contadorSoldados1 = 0;

	//dictamina cual soldado del jugador 2 atacara
	int contadorSoldados2 = 0;

	//verificia que todos los soldados estren vivos
	while ((soldados1[0].estado == 'V' ||
			soldados1[1].estado == 'V' ||
			soldados1[2].estado == 'V') &&
			(soldados2[0].estado == 'V' ||
			 soldados2[1].estado == 'V' ||
			 soldados2[2].estado == 'V')){

		//llama a una funcion que, en caso del contador estar en un soldado muerto, pasa al siguiente
		contadorSoldados1 = arreglarContador(soldados1, contadorSoldados1);
		contadorSoldados2 = arreglarContador(soldados2, contadorSoldados2);

		//jugador1
		if (contadorJugador == 1){
			cout << "turno del jugador 1"<< endl;
			pedirAtaque(tablero1, tablero2, soldados2);
			Movimiento( tablero1,  tablero2,  soldados1 , contadorSoldados1, contadorJugador);

			//en caso de que el soldado se mueva a una casilla con un soldado enemigo, ambos mueren
			if (verificarPosicionSoldados(tablero1, tablero2, soldados1[contadorSoldados1].fila, soldados1[contadorSoldados1].columna) == true){
				cout << " \nEsa posicion era utilizada por un soldado enemigo, ambos moriran y la celda quedara inactiva" << endl;
				soldados1[contadorSoldados1].estado = 'M'; // M representa los soldados muertos

				//llama a una funcin que verifica cual soldado estaba en esa posicion
				matarSoldadoCorrecto(soldados2, soldados1[contadorSoldados1].fila, soldados1[contadorSoldados1].columna);
				tablero1[soldados1[contadorSoldados1].fila][soldados1[contadorSoldados1].columna].estado = 'X'; //x representa el inactivo
				tablero2[soldados1[contadorSoldados1].fila][soldados1[contadorSoldados1].columna].estado = 'X';
			}

			//escribe el texto en el txt
			escribirTexto1(rutaSalida1, contadorJugador, tablero1);

			//pasa al siguiente soldado, en caso del numero de soldado ser >= 3, este vuelve a 0 (el primer soldado)
			++contadorSoldados1;
			if (contadorSoldados1 >= 3){
				contadorSoldados1 = 0;
			}
			//imprime el tablero del jugador 1
			imprimirTablero(tablero1, 1);


		}

		//jugador 2. Duplica lo que hace el primer jugador pero con los parametros del soldado 2
		if (contadorJugador == 2){
			cout << "turno del jugador 2"<< endl;
			pedirAtaque(tablero1, tablero2, soldados2);
			Movimiento( tablero1,  tablero2,  soldados2 , contadorSoldados2, contadorJugador);
			if (verificarPosicionSoldados(tablero1, tablero2, soldados2[contadorSoldados2].fila, soldados2[contadorSoldados2].columna) == true){
				cout << " \nEsa posicion era utilizada por un soldado enemigo, ambos moriran y la celda quedara inactiva" << endl;
				matarSoldadoCorrecto(soldados1, soldados2[contadorSoldados2].fila, soldados2[contadorSoldados2].columna); // M representa los soldados muertos
				soldados2[contadorSoldados2].estado = 'M';
				tablero1[soldados2[contadorSoldados2].fila][soldados2[contadorSoldados2].columna].estado = 'X'; //x representa el inactivo
				tablero2[soldados2[contadorSoldados2].fila][soldados2[contadorSoldados2].columna].estado = 'X';
			}
			++contadorSoldados2;
			if (contadorSoldados2 >= 3){
				contadorSoldados2 = 0;
			}
			imprimirTablero(tablero2, 2);
			escribirTexto2(rutaSalida2, contadorJugador, tablero2);
		}
		//Pasa el turno al siguiente jugador
		if(contadorJugador == 1){
			contadorJugador = 2;
		} else {
			contadorJugador = 1;
		}

	}

	//anuncia quien gana o si hay empate
	if ((soldados1[0].estado == 'M' &&
		soldados1[1].estado == 'M' &&
		soldados1[2].estado == 'M')&&
		(soldados2[0].estado == 'V' ||
		 soldados2[1].estado == 'V' ||
		 soldados2[2].estado == 'V')) {
		cout << "EL ganador es el jugador 2" << endl;
	} else if ((soldados2[0].estado == 'M' &&
			   soldados2[1].estado == 'M' &&
			   soldados2[2].estado == 'M')&&
			  (soldados1[0].estado == 'V' ||
			   soldados1[1].estado == 'V' ||
			   soldados1[2].estado == 'V') ){
		cout << "El ganador es el jugador 1" << endl;
	} else {
		cout << "NO hay ganador, hubo un empate" << endl;
	}
}


