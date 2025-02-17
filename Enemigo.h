class Enemigo {
private:
	int x, y;
	int velocidad;
	char sprite;
	
public:
	Enemigo();  // Constructor
	void mover(); // Movimiento horizontal
	void dibujar(); // Dibujar el enemigo
	int getX();  // Obtener la posición X
	int getY();  // Obtener la posición Y
};



