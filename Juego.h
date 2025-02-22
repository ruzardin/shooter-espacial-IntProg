#include "Nave.h"
#include "Enemigo.h"
#include "Meteorito.h"
#include "Disparo.h"
#include <vector>

using namespace std;

class Juego {
private:
	Nave jugador;
	bool jugando;
	int vidas = 5;
	int puntaje = 0;
	
	
	vector<Meteorito> meteoritos; 
	vector<Enemigo> enemigos;
	vector<Disparo> disparos;
	
	void procesarInput();
	void actualizar();
	void dibujar();
	void borde();
	void mostrarTexto();
	void limpiarPantalla();
	void generarEnemigo();   
	void actualizarEnemigos();   //movimimiento
	void generarMeteorito();  
	void actualizarMeteoritos();  // movimiento
	void actualizarDisparos();
	void manejarDisparos();
	void verificarColisiones();  
	void delay(int tiempoDelay);
public:
	Juego();
	void iniciar();
	
};

