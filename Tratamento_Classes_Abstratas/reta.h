#ifndef RETA_H
#define RETA_H
#include "figurageometrica.h"
#include "screen.h"

class Reta : public FiguraGeometrica
{
private:
    int xi, yi, xf, yf;
    char brush;
public:
    Reta(int _xi=0, int _yi=0, int _xf=0, int _yf=0,char _brush='*');
    void draw(Screen &t);
    int Sinal(int x);
};

#endif // RETA_H
