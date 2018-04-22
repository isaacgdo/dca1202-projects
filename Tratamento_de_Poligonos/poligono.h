#ifndef POLIGONO_H
#define POLIGONO_H
#include "ponto.h"
#include <iostream>
#define N 100

using namespace std;

/**
 * @brief A classe Poligono representa polígonos convexos de até 100 vértices
 */
class Poligono
{
private:
    Ponto vert[N];
    int nVertices;
public:
    /**
     * @brief setnVertices insere vértices no Poligono
     * @param n é o parâmetro que determina a quantidade de vértices do Poligono
     */
    void setnVertices(int n);

    /**
     * @brief numVetPol recupera a quantidade de vértices que foram inseridos no Poligono
     * @return valor com a quantidade de vértices inseridos
     */
    int numVetPol(void);

    /**
     * @brief setVetPol altera os valores das coordenadas x e y de um vértice (Ponto) do Poligono
     * @param i é o parâmetro que indica o vértice (Ponto) a ser alterado
     * @param x é o valor a ser alterado na coordenada x do vértice
     * @param y é o valor a ser alterado na coordenada y do vértice
     */
    void setVetPol(int i,float x,float y);

    /**
     * @brief addPol adiciona valores aos vértices do Polígono
     * @param n é a quantidade de vértices a serem adicionados no Poligono
     */
    void addPol(int n);

    /**
     * @brief calcAreaPol calcula a área de um Poligono
     * @return valor da área do Poligono
     */
    float calcAreaPol(void);

    /**
     * @brief transladaPol translada um Poligono
     * @param a é o valor a ser transladado pelo Poligono no eixo x
     * @param b é o valor a ser trnsladado pelo Poligono no eixo y
     */
    void transladaPol(float a, float b);

    /**
     * @brief rotacionarPol rotaciona um Poligono em torno de um Ponto informado
     * @param angulo é o ângulo de rotação a ser aplicado
     * @param a é o valor da componente x do ponto de referência da rotacão
     * @param b é o valor da componente y do ponto de referência da rotacao
     */
    void rotacionarPol(float angulo,float a, float b);

    /**
     * @brief imprimePol exibe um Poligono
     */
    void imprimePol();
};

#endif // POLIGONO_H
