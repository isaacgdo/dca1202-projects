#include "circulo.h"
#include "screen.h"
#include<iostream>

using namespace std;

Circulo::Circulo(int _x0, int _y0, int _raio, bool _fillmode,char _brush)
{
    x0 = _x0;
    y0 = _y0;
    raio = _raio;
    fillmode = _fillmode;
    brush = _brush;
}

void Circulo::draw(Screen &t)
{
    //Altera o caracter de desenho
    t.setBrush(brush);
    int x = 0;
    int y = raio;
    int d = 1 - raio;
    while(y > x){
        //Desenha os pontos no 2 octante e nos octantes restantes
        t.setPixel(x0 + x, y0 + y);
        t.setPixel(x0 + y, y0 + x);
        t.setPixel(x0 - y, y0 + x);
        t.setPixel(x0 - x, y0 + y);
        t.setPixel(x0 - x, y0 - y);
        t.setPixel(x0 - y, y0 - x);
        t.setPixel(x0 + y, y0 - x);
        t.setPixel(x0 + x, y0 - y);

        //Verifica se o circulo é preenchido e o desenha totalmente preenchido
        if(fillmode == 1){
            for (int i = x0 - x; i <= x0 + x; i++)
            {
                t.setPixel(i, y0 + y);
                t.setPixel(i, y0 - y);
            }
            for (int i = x0 - y; i <= x0 + y; i++)
            {
                t.setPixel(i, y0 + x);
                t.setPixel(i, y0 - x);
            }
        }
        if(d < 0){
            d = d + 2*x + 3;
            x = x + 1;
        }
        else{
            d = d + 2*(x-y) + 5;
            x = x + 1;
            y = y - 1;
        }
    }
}
