#include "circulo.h"
#include "screen.h"
#include<iostream>

using namespace std;

Circulo::Circulo(int _x0, int _y0, int _raio, bool _fillmode)
{
    x0 = _x0;
    y0 = _y0;
    raio = _raio;
    fillmode = _fillmode;
}

void Circulo::draw(Screen &t)
{

}
