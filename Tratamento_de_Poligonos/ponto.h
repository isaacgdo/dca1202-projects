#ifndef PONTO_H
#define PONTO_H

class Ponto
{
private:
    //coordenadas x e y de um ponto
    float x,y;
public:
    Ponto(float _x = 0, float _y = 0);
    void setX(float _x);
    void setY(float _y);
    float getX(void);
    float getY(void);
    void setXY(float _x,float _y);
    void add(Ponto p);
    void sub(Ponto p);
    float norma(void);
    void translada(float a,float b);
    void imprime(void);
};

#endif // PONTO_H
