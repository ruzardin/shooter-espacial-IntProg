class Enemigo {
private:
	int x, y;
	int velocidad;
	char sprite;
	
public:
	Enemigo();  //constructor
	void mover(); // movimiento horizontal
	void dibujar(); 
	int getX();  
	int getY();  
};



