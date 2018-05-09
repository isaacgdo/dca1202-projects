#include <iostream>
#include "screen.h"
#include "retangulo.h"

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
    FiguraGeometrica *ret;
    ret = new Retangulo(0,0,9,9);
    ret->draw(t);
    cout << "exibindo um Retangulo" << endl;
    cout << t;

    return 0;
}
