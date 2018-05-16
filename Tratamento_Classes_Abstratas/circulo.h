#ifndef CIRCULO_H
#define CIRCULO_H
#include "figurageometrica.h"
#include "screen.h"

/**
 * @brief A classe Circulo cria um objeto do tipo Circulo que pode ser desenhada numa Screen
 * @details Esta classe extende a classe FiguraGeometrica
 */
class Circulo : public FiguraGeometrica
{
private:
    int x0, y0, raio;
    bool fillmode;
    char brush;
public:

    /**
     * @brief Circulo é o construtor da classe Circulo
     * @param _x0 é a coordenada x do centro do Circulo
     * @param _y0 é a coordenada y do centro do Circulo
     * @param _raio é o raio do Circulo
     * @param _fillmode indica se o Circulo deve ser preenchido ou não
     * @param _brush indica o caraceter a ser utilizado para desenhar o Circulo
     */
    Circulo(int _x0, int _y0, int _raio, bool _fillmode,char _brush='*');

    /**
     * @brief draw desenha um Circulo numa tela
     * @param t é a tela na qual se deseja desenhar
     */
    void draw(Screen &t);
};

#endif // CIRCULO_H
