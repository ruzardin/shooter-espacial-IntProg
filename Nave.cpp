#include <iostream>
#include <conio2.h>
#include "Nave.h"
 
using namespace std;

Nave::Nave() : x(40), y(20), sprite('0') {}

void Nave::mover(char tecla) {
    switch (tecla) {
    case 72: // arriba
        if (y > 1) y--;
        break;
    case 80: // abajo
        if (y < 24) y++;
        break;
    case 75: // izquierda
        if (x > 1) x--;
        break;
    case 77: // derecha
        if (x < 50) x++;
        break;
    }
}

void Nave::dibujar() {
    gotoxy(x, y);
    textcolor(2);  // verde
    cout << sprite;
}

int Nave::getX() {
	return x;
}

int Nave::getY() {
	return y;
}
