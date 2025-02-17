#include <conio2.h>
#include <windows.h>
#include "Juego.h"

Juego::Juego() : jugando(true) {}

void Juego::iniciar() {
    while (jugando) {
        limpiarPantalla();
        procesarInput();
        actualizar();
        dibujar();
        Sleep(50);  
    }
}

void Juego::procesarInput() {
    if (_kbhit()) {
        char tecla = _getch();
        if (tecla == 27) {  // ESC 
            jugando = false;
        }
        jugador.mover(tecla);
    }
}

void Juego::actualizar() {
   
}

void Juego::dibujar() {
    jugador.dibujar();
}

void Juego::limpiarPantalla() {
    clrscr();
}
