#include "retangulo.h"

Retangulo::Retangulo(int _x0, int _y0, int _l, int _a)
{
    x0 = _x0;
    y0 = _y0;
    l = _l;
    a = _a;
}

void Retangulo::draw(Screen &t){
    for(int i=x0; i<(x0+l);i++){
        for(int j=y0;j<(y0+a);j++){
            t.setPixel(i,j);
        }
    }
}
