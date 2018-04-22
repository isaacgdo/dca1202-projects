#include "ponto.h"
#include <iostream>
#include <cmath>

using namespace std;


Ponto::Ponto(float _x, float _y)
{
    x = _x;
    y = _y;
   // cout << "costrutor"<<endl;
}

void Ponto::setX(float _x)
{
   x = _x;
}

void Ponto::setY(float _y)
{
    y = _y;
}

float Ponto::getX()
{
    return x;
}

float Ponto::getY()
{
    return y;
}

void Ponto::setXY(float _x, float _y)
{
    setX(_x); setY(_y);
}

void Ponto::add(Ponto p)
{
    x = x + p.x;
    y = y + p.y;
}

void Ponto::sub(Ponto p)
{
    x = x - p.x;
    y = y - p.y;
}

float Ponto::norma()
{
    float n=0;
    n = sqrt(pow(x,2)+pow(y,2));
    return n;
}

void Ponto::translada(float a, float b)
{
   x = x + a;
   y = y + b;
}

void Ponto::imprime(void)
{
   cout << "("<<x<<","<<y<<")";
}


