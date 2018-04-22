#ifndef PONTO_H
#define PONTO_H

/**
 * @brief A classe Ponto representa pontos no espaço bidimensional
 */
class Ponto
{
private:
    //coordenadas x e y de um ponto
    float x,y;
public:
    /**
     * @brief Ponto é o construtor da classe Ponto
     * @param _x é o parâmetro que define a coordenada x de um objeto da classe Ponto
     * @param _y é o parâmetro que define a coordenada y de um objeto da classe Ponto
     * @details se um objeto dessa classe for criado sem a passagem de parâmetros
     * para o construtor, o objeto será um Ponto de coordenada (0,0)
     */
    Ponto(float _x = 0, float _y = 0);

    /**
     * @brief setX altera o valor da coordenada x de um objeto da classe Ponto
     * @param _x é o parâmetro para o valor a ser alterado na coordenada x.
     */
    void setX(float _x);

    /**
     * @brief setY altera o valor da coordenada y de um objeto da classe Ponto
     * @param _y é o parâmetro para o valor a ser alterado na coordenada y.
     */
    void setY(float _y);

    /**
     * @brief getX recupera o valor da coordenada x de um objeto da classe Ponto
     * @return valor da coordenada x da classe Ponto
     */
    float getX(void);

    /**
     * @brief getY recupera o valor da coordenada y de um objeto da classe Ponto
     * @return valor da coordenada y da classe Ponto
     */
    float getY(void);

    /**
     * @brief setXY altera os valores das coordenadas x e y de um objeto da classe Ponto
     * @param _x é o parâmetro para o valor a ser alterado na coordenada x.
     * @param _y é o parâmetro para o valor a ser alterado na coordenada y.
     */
    void setXY(float _x,float _y);

    /**
     * @brief add realiza a operação de soma de 2 pontos
     * @param p é o objeto do tipo Ponto a ser somado
     */
    void add(Ponto p);

    /**
     * @brief sub realiza a operação de subtração de 2 pontos
     * @param p é o objeto do tipo Ponto a ser subtraído
     */
    void sub(Ponto p);

    /**
     * @brief norma calcula a norma de um ponto
     * @return o valor da norma do ponto.
     */
    float norma(void);

    /**
     * @brief translada é um método que translada um objeto da classe Ponto
     * @param a é o valor a ser transladado na coordenada x.
     * @param b é o valor a ser transladado na coordenada y.
     */
    void translada(float a,float b);

    /**
     * @brief imprime exibe um objeto da classe Ponto
     */
    void imprime(void);
};

#endif // PONTO_H
