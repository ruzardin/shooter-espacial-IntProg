#include <iostream>
#include <conio2.h>
#include "Disparo.h"

using namespace std;

Disparo::Disparo(int startX, int startY) : x(startX), y(startY) {}

void Disparo::mover() {
	if (y > 1) {
		y--;
	}
}

void Disparo::dibujar() {
	gotoxy(x, y);
	textcolor(4); // Rojo
	cout << "|";
}

bool Disparo::fueraDePantalla() {
	return y <= 1;
}

int Disparo::getX() const {
	return x;
}

int Disparo::getY() const {
	return y;
}
