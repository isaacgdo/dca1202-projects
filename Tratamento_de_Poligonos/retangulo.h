#ifndef RETANGULO_H
#define RETANGULO_H
#include "poligono.h"

/**
 * @brief A classe Retangulo é uma subclasse da classe Poligono que representa retângulos.
 */
class Retangulo : public Poligono
{
public:
    /**
     * @brief Retangulo é o construtor da classe Retangulo
     * @param x é a coordenada x do canto superior esquerdo (Ponto Superior Esquerdo) do Retangulo
     * @param y é a coordenada y do canto superior esquerdo (Ponto Superior Esquerdo) do Retangulo
     * @param largura é a largura a ser definida pro Retangulo
     * @param altura é a altura a ser definida pro Retangulo
     */
    Retangulo(float x, float y, float largura, float altura);
};

#endif // RETANGULO_H
