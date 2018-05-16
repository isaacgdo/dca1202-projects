#ifndef RETANGULO_H
#define RETANGULO_H
#include "figurageometrica.h"
#include "screen.h"

/**
 * @brief A classe Retangulo cria um objeto do tipo Retangulo que pode ser desenhada numa Screen
 * @details Esta classe extende a classe FiguraGeometrica
 */
class Retangulo: public FiguraGeometrica
{
private:
    int x0, y0, l, a, fillmode;
    char brush;
public:

    /**
     * @brief Retangulo é o construtor da classe Retangulo
     * @param _x0 é o valor da coordenada x do ponto superior esquerdo do Retangulo
     * @param _y0 é o valor da coordenada y do ponto superior esquerdo do Retangulo
     * @param _l é o valor da largura do Retangulo
     * @param _a é o valor da altura do Retangulo
     * @param _fillmode indica se o Retangulo deve ser preenchido ou não
     * @param _brush indica o caractere a ser usado para desenhar o Retangulo uma tela
     */
    Retangulo(int _x0=0, int _y0=0, int _l=0, int _a=0, int _fillmode=0, char _brush='*');

    /**
     * @brief draw desenha um Retangulo numa tela
     * @param t é a tela na qual se deseja desenhar
     */
    void draw(Screen &t);
};

#endif // RETANGULO_H
