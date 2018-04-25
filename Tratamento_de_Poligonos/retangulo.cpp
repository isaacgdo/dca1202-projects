#include "retangulo.h"

Retangulo::Retangulo(float x, float y, float largura, float altura)
{
    setnVertices(4);
    setVetPol(3,x,y);
    setVetPol(2,x+largura,y);
    setVetPol(1,x+largura,y-altura);
    setVetPol(0,x,y-altura);
}
