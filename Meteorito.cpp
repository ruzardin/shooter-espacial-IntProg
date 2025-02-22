#include<iostream>
#include <conio2.h>
#include "Meteorito.h"

using namespace std;

Meteorito::Meteorito() : sprite('*') {
	x = rand() % 50;
	y = 1; 
}

void Meteorito::mover() {
	y++;
	if (y >= 25) { //al llegar al fondo aparece de vuelta arriba
		y = 1;
		x = rand() % 50;
	}
}

void Meteorito::dibujar() {
	gotoxy(x, y);
	textcolor(8);  // Gris
	cout << sprite;
}

int Meteorito::getX() {
	return x;
}

int Meteorito::getY() {
	return y;
}
