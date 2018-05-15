#include "retangulo.h"

Retangulo::Retangulo(int _x0, int _y0, int _l, int _a, int _fillmode, char _brush)
{
    x0 = _x0;
    y0 = _y0;
    l = _l;
    a = _a;
    fillmode = _fillmode;
    brush = _brush;
}

void Retangulo::draw(Screen &t){
    //Altera o caracter de desenho
    t.setBrush(brush);
    //Verifica se o retangulo é preenchido e o desenha, se não,
    //ele desenha apenas o contorno do retangulo
    //Retangulo preenchido
    if(fillmode == 1){
        for(int i=x0; i<(x0+l);i++){
            for(int j=y0;j<(y0+a);j++){
                t.setPixel(i,j);
            }
        }
    }
    //Retangulo preenchido
    else{
        for(int i=x0; i<(x0+l);i++){
            for(int j=y0;j<(y0+a);j++){
                if(((i == x0 || i==x0+l-1) || (j ==y0 || j==y0+a-1))){
                t.setPixel(i,j);
                }
            }
        }
    }
}
