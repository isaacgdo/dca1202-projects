#include "reta.h"
#include "screen.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Reta::Reta(int _xi, int _yi, int _xf, int _yf)
{
    xi = _xi;
    yi = _yi;
    xf = _xf;
    yf = _yf;
}

void Reta::draw(Screen &t)
{
    int x = xi;
    int y = yi;
    int Troca;
    int Delta_x = abs(xf - xi);
    int Delta_y = abs(yf - yi);
    int s1 = Sinal(xf - xi);
    int s2 = Sinal(yf - yi);
    if(Delta_y > Delta_x){
        int Temp = Delta_x;
        Delta_x = Delta_y;
        Delta_y = Temp;
        Troca = 1;
    }
    else{
        Troca = 0;
    }
    int new_e = 2*Delta_y - Delta_x;
    for(int i = 1; i <= Delta_x; i++){
        t.setPixel(x,y);
        while (new_e >= 0){
            if(Troca == 1){
                //Muda para a proxima linha de rasterização
                x = x + s1;
            }
            else{
                y = y + s2;
            }
            new_e = new_e - 2*Delta_x;
        }

        //Permanece nesta linha de rasterização
        if(Troca == 1){
            y = y + s2;
        }
        else{
            x = x + s1;
        }
        new_e = new_e + 2*Delta_y;
    }
}

int Reta::Sinal(int x)
{
    if(x < 0){ return -1; }
    if(x == 0){ return 0; }
    else{ return 1; }
}
