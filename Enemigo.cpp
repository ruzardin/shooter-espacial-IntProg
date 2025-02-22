#include<iostream>
#include <conio2.h>
#include "Enemigo.h"

using namespace std;

Enemigo::Enemigo() : sprite('V') {
	x = rand() % 49; // aleatoria horizontal
	y = rand() % 5;  // aleatoria vertical cerca de arriba
	velocidad = rand() % 1 + 2;  // Velocidad aleatoria (1 o 2)
}

void Enemigo::mover() {
	if (x >= 49) {
		velocidad = -velocidad;  // cambia de dirección al llegar al borde derecho
	}
	if (x <= 1) {
		velocidad = -velocidad;  // cambia de dirección al llegar al borde izquierdo
	}
	x += velocidad;  // movimiento horizontal
}

void Enemigo::dibujar() {
	gotoxy(x, y);
	textcolor(12);  // rojo
	cout << sprite;
}

int Enemigo::getX() {
	return x;
}

int Enemigo::getY() {
	return y;
}
