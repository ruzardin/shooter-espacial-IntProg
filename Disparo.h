#include <iostream>
#include <conio2.h>

class Disparo {
private:
	int x, y;
	char sprite;
	bool activo;
	
public:
	Disparo(int startX, int startY);
	void mover();
	void dibujar();
	bool fueraDePantalla();
	int getY() const;
	int getX() const;
};
