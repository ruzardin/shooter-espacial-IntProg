class Nave {
private:
    int x, y;
    char sprite;

public:
    Nave();
    void mover(char tecla);
    void dibujar();
	int getX();
	int getY();
	char getSprite()const;
	void setSprite(char sprite2);
};

