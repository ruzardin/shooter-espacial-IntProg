class Meteorito {
private:
	int x, y;
	char sprite;
	
public:
	Meteorito();//constructor
	void mover(); //mov vertical
	void dibujar();
	int getX();
	int getY();
};
