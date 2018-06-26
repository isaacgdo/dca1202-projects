#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include<vector>

class Plotter : public QWidget
{
    Q_OBJECT
private:
    std::vector<double> tempos;
    std::vector<double> dados;
    float time;
public:
    /** @brief Construtor do componente Plotter
   * @details adiciona os valores aos vectores  de tempos e de dados
  **/
    explicit Plotter(QWidget *parent = 0);
    /** @brief Paint event
   * @details Desenha o  grafico utilizando retas, usando dois pontos de cada vez.
  **/
    void paintEvent(QPaintEvent *e);
    /** @brief Função que carrega os dados referentes aos tempos e aos dados
   * @details Recebe os 30 ultimos dados e os usa na classe Plotter.
  **/
    void loadData(std::vector <double>,std::vector <double>);
};

#endif // PLOTTER_H
