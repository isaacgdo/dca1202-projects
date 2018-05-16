#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "screen.h"

/**
 * @brief A classe FiguraGeometrica é uma classe abstrata que desenha Figuras Geometricas
 */
class FiguraGeometrica
{
public:

    /**
     * @brief FiguraGeometrica é o construtor da classe FiguraGeometrica
     */
    FiguraGeometrica();

    /**
     * @brief draw é o método da classe Abstrata que ira desenhar objetos de outras classes que implementam esse método
     * @param t é a tela na qual se deseja desenhar
     */
    virtual void draw(Screen &t)=0;
};

#endif // FIGURAGEOMETRICA_H
