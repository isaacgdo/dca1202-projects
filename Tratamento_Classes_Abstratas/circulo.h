#ifndef CIRCULO_H
#define CIRCULO_H
#include "figurageometrica.h"
#include "screen.h"

class Circulo
{
private:
    int x0, y0, raio;
    bool fillmode;
public:
    Circulo(int _x0, int _y0, int _raio, bool _fillmode);
    void draw(Screen &t);
};

#endif // CIRCULO_H
