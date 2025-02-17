#include<iostream>
#include <conio2.h>
#include <ctime>
#include <vector>
#include "Juego.h"

using namespace std;

Juego::Juego() : jugando(true) {}

void Juego::iniciar() {
	clock_t tempo = clock(); 
	clock_t paso = CLOCKS_PER_SEC / 20; //velocidad del juego
	while (jugando) {
		if (clock() - tempo >= paso) { 
			limpiarPantalla();
			procesarInput();
			generarMeteorito();  
			generarEnemigo();    
			actualizar();        
			dibujar();    
		tempo = clock(); // Actualiza el tiempo de referencia para el siguiente ciclo
		}
	}
}

void Juego::procesarInput() {
	if (kbhit()) {
		char tecla = getch();
		if (tecla == 27) {  // ESC para salir
			jugando = false;
		}
		jugador.mover(tecla);
	}
}

void Juego::generarMeteorito() {
	if (rand() % 10 == 0) {  //probabilidad de generacion
		meteoritos.push_back(Meteorito());
	}
}

void Juego::generarEnemigo() {
	if (rand() % 50 == 0) {  //probabilidad de generacion
		enemigos.push_back(Enemigo());
	}
}

void Juego::actualizar() {
	// actualiza movimiento
	actualizarMeteoritos();
	actualizarEnemigos();  
	verificarColisiones();
}

void Juego::actualizarMeteoritos() {
	for (auto& meteorito : meteoritos) {
		meteorito.mover();
	}
}

void Juego::actualizarEnemigos() {
	for (auto& enemigo : enemigos) {
		enemigo.mover();
	}
}

void Juego::verificarColisiones() {
	for (auto& meteorito : meteoritos) {
		if (meteorito.getX() == jugador.getX() && meteorito.getY() == jugador.getY()) {
			//sacar vida
		}
	}
	
	for (auto& enemigo : enemigos) {
		if (enemigo.getX() == jugador.getX() && enemigo.getY() == jugador.getY()) {
			//sacar vida o dar puntos
		}
	}
}

void Juego::dibujar() {
	jugador.dibujar();
	for (auto& meteorito : meteoritos) {
		meteorito.dibujar();
	}
	for (auto& enemigo : enemigos) {
		enemigo.dibujar();
	}
}


void Juego::limpiarPantalla() {
	clrscr();
}
