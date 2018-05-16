#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

/**
 * @brief A classe Screen exibe imagens numa tela
 */
class Screen
{
private:
    int nlin, ncol;
    char brush = '*';

    vector< vector<char> > mat;
public:
    /**
     * @brief Screen é o construtor da classe Screen
     * @param _nlin é o número de linhas da tela, ou seja, a altura (dimensão Y)
     * @param _ncol é o número de colunas da tela, ou seja, a largura (dimensão X)
     */
    Screen(int _nlin = 10, int _ncol = 10);

    /**
     * @brief setPixel altera o conteúdo de um pixel da tela
     * @param x é a coordenada x do pixel a ser alterado
     * @param y é a coordenada y do pixel a ser alterado
     */
    void setPixel(int x, int y);

    /**
     * @brief clear limpa a tela deixando-a em branco
     */
    void clear();

    /**
     * @brief setScreen altera as dismensões da tela
     * @param nl é o número de linhas a ser setado
     * @param nc é o número de colunas a ser setado
     */
    void setScreen(int nl,int nc);

    /**
     * @brief setBrush altera o pincel usado para desenhar na tela
     * @param _brush é o parâmetro que recebe o caracetere a ser usado para o pincel
     */
    void setBrush(char _brush = '*');

    /**
     * @brief operator << é a sobrecarga do operador <<
     * @param os é um parâmetro de fluxos de saída
     * @param t é a tela na qual deve ser desenhada
     * @return
     */
    friend ostream& operator<<(ostream &os, Screen &t);
};

#endif // SCREEN_H
