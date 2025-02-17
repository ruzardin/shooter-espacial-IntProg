#include "Nave.h"

class Juego {
private:
    Nave jugador;
    bool jugando;
    void procesarInput();
    void actualizar();
    void dibujar();
    void limpiarPantalla();

public:
    Juego();
    void iniciar();
};
