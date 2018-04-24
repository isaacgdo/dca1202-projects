#include "poligono.h"
#include <cmath>
#define PI 3.14159265

void Poligono::setnVertices(int n)
{
    if(n>100 || n < 0){
        cout << "Poligono invalido! O poligono deve ter de 0 a 100 vertices"<<endl;
        exit(0);
    }else{
        nVertices = n;
    }
}

void Poligono::setVetPol(int i, float x, float y)
{
        vert[i].setX(x);
        vert[i].setY(y);
}

int Poligono::numVetPol()
{
   return nVertices;
}

void Poligono::addPol(int n)
{
    int i,x,y;
    setnVertices(n);
    for(i = 0;i<numVetPol();i++){
        cout <<" Digite o valor da coordena x e y do vertice (x"<<i<<",y"<<i<<")"<<endl;
        cout <<"x"<<i<<"=";
        cin >> x;
        cout <<"y"<<i<<"=";
        cin >> y;
        setVetPol(i,x,y);
    }
}

float Poligono::calcAreaPol()
{
    float area = 0;
        int n = numVetPol();
        int j = n - 1;
            for (int i = 0; i < n; i++)
            {
                area += (vert[j].getX() + vert[i].getX()) * (vert[j].getY() - vert[i].getY());
                j = i;
            }
        area = abs(area)/2;
        return area;
}

void Poligono::transladaPol(float a, float b)
{
    int i;
    for(i=0;i<=numVetPol();i++){
        vert[i].setX(vert[i].getX()+a);
        vert[i].setY(vert[i].getY()+b);
    }
}

void Poligono::rotacionarPol(float angulo, float a, float b)
{
    int i;
    float xa, ya;
    /* FORMULA DE ROTAÇÃO EM RELAÇÃO AO PONTO NA ORIGEM
        x_final := x_inicial * cos (ang) - y_inicial * sin (ang)
        y_final := y_inicial * cos (ang) + x_inicial * sin (ang)
    */
    //Transladar os ponto em relação a origem para utilizar a formula
    transladaPol(-a,-b);

    for(i=0;i<numVetPol();i++){
        xa = vert[i].getX();
        ya = vert[i].getY();
        //Calcula a rotação em relação a origem
        vert[i].setX((xa*cos(angulo*(PI/180))) - (ya*sin(angulo*(PI/180))));
        vert[i].setY((ya*cos(angulo*(PI/180))) + (xa*sin(angulo*(PI/180))));
    }
    //Desfazer a translação dos pontos iniciais
    transladaPol(a,b);
}

void Poligono::imprimePol()
{
    int i;

    for(i=0;i<numVetPol();i++){
        cout<<"("<<vert[i].getX()<<","<<vert[i].getY()<<") -> ";
    }
    cout <<"("<<vert[0].getX()<<","<<vert[0].getY()<<")"<<endl;
}
