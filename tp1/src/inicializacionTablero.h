/*
 * inicializacionTablero.h
 *
 *  Created on: Apr 10, 2022
 *      Author: juli
 */

#ifndef INICIALIZACIONTABLERO_H_
#define INICIALIZACIONTABLERO_H_

//constantes del ancho y alto de los tableros
const static int Ancho = 10;
const static int Alto = 10;

//estructura de los casilleros que deben tener la letra y el numero, para indicar cual casillero es, y el estado.
struct Casillero{
	char letra;
	int numero;
	char estado;
};

struct Soldados{
	int fila;
	int columna;
	char estado;
};

//Le asigna la letra a los casilleros para que sea mas entendible para el usuario
char asignarLetra(int num);

//Inicializa el tablero poniendole el numero y letra del casillero y el estado (al principio vacio)
void inicializarTablero(Casillero tablero[Alto][Ancho]);




#endif /* INICIALIZACIONTABLERO_H_ */
