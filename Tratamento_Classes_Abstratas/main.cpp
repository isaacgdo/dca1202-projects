#include <iostream>
#include "screen.h"
#include "retangulo.h"
#include "reta.h"

using namespace std;

int main()
{
    Screen t;
    t.setPixel(0,0);
    cout << "Exibindo primeira tela" << endl;
    cout << t;

    t.clear();
    t.setBrush('@');
    t.setPixel(0,0);
    t.setPixel(0,9);
    t.setPixel(5,5);
    t.setPixel(9,0);
    t.setPixel(9,9);
    cout << "Exibindo segunda tela" << endl;
    cout << t;

    t.clear();
    FiguraGeometrica *retangulo;
    retangulo = new Retangulo(0,0,9,9);
    retangulo->draw(t);
    cout << "exibindo um Retangulo" << endl;
    cout << t;

    t.clear();
    FiguraGeometrica *reta;
    reta = new Reta(5,5,20,20);
    reta->draw(t);
    cout << "exibindo uma Reta" << endl;
    cout << t;

    return 0;
}
