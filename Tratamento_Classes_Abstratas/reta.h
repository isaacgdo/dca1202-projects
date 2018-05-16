#ifndef RETA_H
#define RETA_H
#include "figurageometrica.h"
#include "screen.h"

/**
 * @brief A classe Reta cria um objeto do tipo Reta que pode ser desenhada numa Screen
 * @details Esta classe extende a classe FiguraGeometrica
 */
class Reta : public FiguraGeometrica
{
private:
    int xi, yi, xf, yf;
    char brush;
public:

    /**
     * @brief Reta é o construtor da classe Reta
     * @param _xi é a coordenada x do ponto inicial da Reta
     * @param _yi é a coordenada y do ponto inicial da Reta
     * @param _xf é a coordenada x do ponto final da Reta
     * @param _yf é a coordenada y do ponto final da Reta
     * @param _brush é o caractere a ser usado para desenhar a Reta
     */
    Reta(int _xi=0, int _yi=0, int _xf=0, int _yf=0,char _brush='*');

    /**
     * @brief draw é uma função que desenha a Reta criada numa tela
     * @param t é a tela na qual se deseja desenhar
     */
    void draw(Screen &t);

    /**
     * @brief Sinal é uma função auxialiar usada no algoritmo de desenhar uma Reta digital
     * @param x é um parâmetro usado para o cálculo da reta digital
     * @return valor inteiro (-1, 0 ou 1) que indicará o sinal de uma operação necessária para desenhar a Reta
     */
    int Sinal(int x);
};

#endif // RETA_H
