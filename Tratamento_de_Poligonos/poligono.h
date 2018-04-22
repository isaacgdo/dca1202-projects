#ifndef POLIGONO_H
#define POLIGONO_H
#include "ponto.h"
#include <iostream>
#define N 100

using namespace std;

class Poligono
{
private:
    Ponto vert[N];
    int nVertices;
public:
    void setnVertices(int n);
    int numVetPol(void);
    void setVetPol(int i,float x,float y);
    void addPol(int n);
    float calcAreaPol(void);
    void transladaPol(float a, float b);
    void rotacionarPol(float angulo,float a, float b);
    void imprimePol();
};

#endif // POLIGONO_H
