#include<iostream>
#include <conio2.h>
#include <ctime>
#include <vector>
#include "Juego.h"

using namespace std;

Juego::Juego() : jugando(true) {}

void Juego::iniciar() {
	clock_t tempo = clock(); 
	clock_t paso = CLOCKS_PER_SEC / 11; //velocidad del juego
	while (jugando) {
		while (bandera){
			if (clock() - tempo >= paso) { 
				limpiarPantalla();
				borde(); 
				procesarInput();
				generarMeteorito();  
				generarEnemigo();    
				actualizar();        
				dibujar();    
				tempo = clock(); // Actualiza el tiempo de referencia para el siguiente ciclo
			}
		}
		
	}
}

void Juego::procesarInput() {
	if (kbhit()) {
		char tecla = getch();
		if (tecla == 27) {  // ESC para salir
			jugando = false;
		}
		if (tecla == ' ' && disparos.size()<5) {
			disparos.push_back(Disparo(jugador.getX(), jugador.getY() - 1));
		}
		jugador.mover(tecla);
	}
}

void Juego::generarMeteorito() {
	if (rand() % 10 == 0) {  //probabilidad de generacion
		if (meteoritos.size() < 10) { 
			meteoritos.push_back(Meteorito());
		}
	}
}

void Juego::generarEnemigo() {
	if (rand() % 20 == 0) {  //probabilidad de generacion
		if (enemigos.size() < 20) { 
			enemigos.push_back(Enemigo());
		}
	}
}

void Juego::actualizarDisparos() {
	for (auto it = disparos.begin(); it != disparos.end();) {
		it->mover();
		if (it->fueraDePantalla()) {
			it = disparos.erase(it);
		} else {
			++it;
		}
	}
}


void Juego::actualizar() {
	// actualiza movimiento
	actualizarMeteoritos();
	actualizarEnemigos();  
	actualizarDisparos();
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

void Juego::delay(int tiempoDelay){
	clock_t tempo = clock();  
	clock_t paso = CLOCKS_PER_SEC / 11;  
	while (clock() - tempo < tiempoDelay * paso) {
		dibujar();
		gotoxy(25, 10);
		textcolor(12);  
		cout << "BOOM!" << endl;
		
	}
}

void Juego::verificarColisiones() {
	for (auto& meteorito : meteoritos) {
		if (meteorito.getX() == jugador.getX() && meteorito.getY() == jugador.getY()) {
			jugador.setSprite('X');
			vidas--;
			delay(3);
			jugador.setSprite('0');
			if (vidas <= 0) {
				limpiarPantalla();  // Limpiar pantalla para el mensaje de Game Over
				cout << "Game Over!" << endl;
				gotoxy(40, 12);
				textcolor(12);  
				cout << "Puntaje Final: " << puntaje << endl;
				jugando = false;  
			}
		}
	}
	
	for (auto& enemigo : enemigos) {
		if (enemigo.getX() == jugador.getX() && enemigo.getY() == jugador.getY()) {
			jugando = false; 
		}
	}
	
	for (auto it = disparos.begin(); it != disparos.end();) {
		bool eliminado = false;
		for (auto et = enemigos.begin(); et != enemigos.end();) {
			if (it->getX() == et->getX() && it->getY() == et->getY()) {
				et = enemigos.erase(et);
				it = disparos.erase(it);
				puntaje += 10; 
				eliminado = true;
				break;
			} else {
				++et;
			}
		}
		if (!eliminado) {
			++it;
		}
	}
}

void Juego::borde() {
	for (int i = 0; i < 51; ++i) {
		gotoxy(i, 1);//borde sup
		cout << "@";
		gotoxy(i, 25);//borde inf
		cout << "@";
	}
	for (int i = 1; i < 25; ++i) {
		gotoxy(1, i);//borde izq
		cout << "@";
		gotoxy(51, i);//borde der
		cout << "@";
	}
}

void Juego::mostrarTexto(){
	gotoxy(70, 10);
	textcolor(15);
	cout<<"Vidas: "<< vidas << "  Puntaje: " << puntaje << endl;
	gotoxy(60, 12);
	cout<< "Teclas de movimiento: Flechas direccionales "<<endl;
	gotoxy(70, 14);
	cout<< "Disparar: SPACEBAR"<<endl;
	gotoxy(59, 16);
	cout<< "Debes dispararle a las naves, cuidado con los asteroides!! "<<endl;
	
	if (puntaje % 30 == 0 && puntaje > 0) {
		gotoxy(70, 20);
		textcolor(10);  // verde
		cout << "Nice Shoot!" << endl;
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
	for (auto &disparo : disparos) {
		disparo.dibujar();
	}
	mostrarTexto(); 
}

void Juego::limpiarPantalla() {
	clrscr();
}
