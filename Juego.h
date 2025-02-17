#include "Nave.h"
#include "Enemigo.h"
#include "Meteorito.h"
#include <vector>

class Juego {
private:
	Nave jugador;
	bool jugando;
	std::vector<Meteorito> meteoritos; 
	std::vector<Enemigo> enemigos;
	void procesarInput();
	void actualizar();
	void dibujar();
	void limpiarPantalla();
	void generarEnemigo();   
	void actualizarEnemigos();   //movimimiento
	void generarMeteorito();  
	void actualizarMeteoritos();  // movimiento
	void verificarColisiones();  
public:
	Juego();
	void iniciar();
};

