#include <iostream>
#include "ponto.h"
#include "poligono.h"
#include "retangulo.h"

using namespace std;

void limpar(void){
    cout<<"\e[H\e[2J";
}


int main()
{
    //Menu de escolha, o usuario pode definir operações utilizando pontos,
    //retangulos e poligonos. Quando o usuario digitar -1 o programa finaliza.
    int menu = -1, opcao;
    //Variavel de controle de menus
    int controlador = -1;
    while(menu !=0){
        //Função que cria uma formatação na tela de exibição, que causa um
        //efeito de limpeza na tela.
        limpar();

        //Menu para a escolha de tratamento de operações.
        cout<<"----------------------------------------"<<endl;
        cout<<"\t\t MENU\t\t"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"ESCOLHA UMA OPCAO:"<<endl
            <<"1 - PONTO"<<endl
            <<"2 - RETANGULO"<<endl
            <<"3 - POLIGONO"<<endl
            <<"0 - SAIR"<<endl;
        cout<<"----------------------------------------"<<endl
            <<"OPCAO:";
        cin >> menu;
        controlador = menu;

        switch (menu) {
            case 1:{
                Ponto U,V;
                //variaveis necessaria para a utilização da opção com pontos
                float x,y,a,b;
                limpar();
                cout<<"Para utilizar a opcao de utilizar pontos e necessario adicionar um ponto."<<endl;
                cout<<"Digite a coordenada x do seu ponto:"<<endl<<"x=";
                cin >> x;
                cout<<"Digite a coordenada y do seu ponto:"<<endl<<"y=";
                cin >> y;
                U.setXY(x,y);
                limpar();
                while(controlador == 1){
                    //Menu com as operções estabelecidas para pontos
                    cout<<"----------------------------------------"<<endl;
                    cout<<"\t\t PONTO\t\t"<<endl;
                    cout<<"----------------------------------------"<<endl;
                    cout<<"ESCOLHA UMA OPCAO:"<<endl
                        <<"1 - SOMAR PONTOS"<<endl
                        <<"2 - SUBTRAIR PONTOS"<<endl
                        <<"3 - NORMA DO PONTO"<<endl
                        <<"4 - TRANSLADAR PONTO"<<endl
                        <<"5 - IMPRIMIR PONTO"<<endl
                        <<"0 - MENU PRINCIPAL"<<endl
                        <<"-1 - SAIR"<<endl;
                    cout<<"----------------------------------------"<<endl
                        <<"OPCAO:";
                    cin >>opcao;
                    switch (opcao) {
                        case 1:{
                            limpar();
                            cout<<"Digite a coordenada x do seu ponto a ser somado com o definido anteriormente:"<<endl<<"x=";
                            cin >> a;
                            cout<<"Digite a coordenada y do seu ponto a ser somado com o definido anteriormente:"<<endl<<"y=";
                            cin >> b;
                            V.setXY(a,b);
                            U.add(V);
                            break;
                        }
                        case 2:{
                            limpar();
                            cout<<"Digite a coordenada x do seu ponto a ser subtraido com o definido anteriormente:"<<endl<<"x=";
                            cin >> a;
                            cout<<"Digite a coordenada y do seu ponto a ser subtraido com o definido anteriormente:"<<endl<<"y=";
                            cin >> b;
                            V.setXY(a,b);
                            U.sub(V);
                            break;
                        }
                        case 3:{
                            limpar();
                            cout << "A norma de ";
                            U.imprime();
                            cout<<" e "<<U.norma()<<endl;
                            break;
                        }
                        case 4:{
                            limpar();
                            cout<<"Digite o valor da transalção da coordenada x:"<<endl<<"a=";
                            cin >> a;
                            cout<<"Digite o valor da transalção da coordenada y:"<<endl<<"b=";
                            cin >> b;
                            U.translada(a,b);
                            break;
                        }
                        case 5:{
                            limpar();
                            cout << "O ponto e  ";
                            U.imprime();
                            cout<<endl;
                            break;
                        }
                        case 0:{
                            controlador = -1;
                            break;
                        }
                        case -1:{
                            exit(0);
                        }
                        default:
                            break;
                    }
                }
                break;
            }

            case 2:{
                limpar();
                //variaveis necessaria para a utilização da opção com retangulo
                float x2,y2,a2,b2,rx,ry,largura,altura,angulo;
                limpar();
                cout<<"Para utilizar a opcao de utilizar retangulos e necessario adicionar um retangulo."<<endl;
                cout<<"Digite a coordenada x do canto superior esquerdo do seu retangulo:"<<endl<<"x=";
                cin >> x2;
                cout<<"Digite a coordenada y do canto superior esquerdo do seu retangulo:"<<endl<<"y=";
                cin >> y2;
                cout <<"Digite a largura do seu retangulo:"<<endl<<"Largura:";
                cin >> largura;
                while(largura<=0){
                    cout<<"Valor de largura invalido! Digite novamente."<<endl<<"Largura:";
                    cin >> largura;
                }
                cout <<"Digite a altura do seu retangulo:"<<endl<<"Altura:";
                cin >> altura;
                while(altura<=0){
                    cout<<"Valor de altura invalido! Digite novamente."<<endl<<"Altura:";
                    cin >> altura;
                }
                Retangulo R(x2,y2,largura,altura);
                limpar();

                while(controlador == 2){
                    //Menu com as operções estabelecidas para retangulos
                    cout<<"----------------------------------------"<<endl;
                    cout<<"\t\t RETANGULO\t\t"<<endl;
                    cout<<"----------------------------------------"<<endl;
                    cout<<"ESCOLHA UMA OPCAO:"<<endl
                        <<"1 - CALCULAR AREA DO RETANGULO"<<endl
                        <<"2 - TRANSLADAR RETANGULO"<<endl
                        <<"3 - ROTACIONAR RETANGULO"<<endl
                        <<"4 - IMPRIMIR RETANGULO"<<endl
                        <<"0 - MENU PRINCIPAL"<<endl
                        <<"-1 - SAIR"<<endl;
                    cout<<"----------------------------------------"<<endl
                        <<"OPCAO:";
                    cin >>opcao;
                    switch (opcao){
                        case 1:{
                            limpar();
                            cout<< "A area do retangulo e de "<<R.calcAreaPol()<<endl;
                            break;
                        }
                        case 2:{
                            limpar();
                            cout<<"Digite o valor da translação da componente x do retangulo:"<<endl<<"a=";
                            cin >> a2;
                            cout<<"Digite o valor da translação da componente y do retangulo:"<<endl<<"b=";
                            cin >> b2;
                            R.transladaPol(a2,b2);
                            break;
                        }
                        case 3:{
                            limpar();
                            cout<<"Digite o valor da componente x do ponto de referencia da rotacao :"<<endl<<"rx=";
                            cin >> rx;
                            cout<<"Digite o valor da componente y do ponto de referencia da rotacao :"<<endl<<"ry=";
                            cin >> ry;
                            cout<<"Digite o valor do angulo de rotacao em graus:"<<endl<<"Angulo=";
                            cin >>angulo;
                            R.rotacionarPol(angulo,rx,ry);
                            break;
                        }
                        case 4:{
                            limpar();
                            cout << "O retangulo e:" <<endl;
                            R.imprimePol();
                            cout<<endl;
                            break;
                        }
                        case 0:{
                            controlador = -1;
                            break;
                        }
                        case -1:{
                            exit(0);
                        }
                        default:{
                            break;
                        }
                    }
                }
                break;
            }

            case 3:{
                limpar();
                //variaveis necessaria para a utilização da opção com retangulo
                float a3,b3,rx,ry,angulo;
                int nvertices;
                Poligono P;
                limpar();
                cout<<"Para utilizar a opcao de utilizar poligonos e necessario adicionar "
                      "um poligono."<<endl;
                cout<<"Quantos vertices tem o seu poligono:"<<endl<<"Numero de vertices=";
                cin >>nvertices;
                P.addPol(nvertices);
                limpar();
                while(controlador == 3){
                    //Menu com as operções estabelecidas para poligonos
                    cout<<"----------------------------------------"<<endl;
                    cout<<"\t\t POLIGONOS\t\t"<<endl;
                    cout<<"----------------------------------------"<<endl;
                    cout<<"ESCOLHA UMA OPCAO:"<<endl
                        <<"1 - CALCULAR AREA DO POLIGONO"<<endl
                        <<"2 - TRANSLADAR POLIGONO"<<endl
                        <<"3 - ROTACIONAR POLIGONO"<<endl
                        <<"4 - IMPRIMIR POLIGONO"<<endl
                        <<"0 - MENU PRINCIPAL"<<endl
                        <<"-1 - SAIR"<<endl;
                    cout<<"----------------------------------------"<<endl
                    <<"OPCAO:";
                    cin >>opcao;
                    switch (opcao) {
                        case 1:{
                            limpar();
                            cout<< "A area do poligono e de "<<P.calcAreaPol()<<endl;
                            break;
                        }
                        case 2:{
                            limpar();
                            cout<<"Digite o valor da translação da componente x do poligono:"<<endl<<"a=";
                            cin >> a3;
                            cout<<"Digite o valor da translação da componente y do poligono:"<<endl<<"b=";
                            cin >> b3;
                            P.transladaPol(a3,b3);
                            break;
                        }
                        case 3:{
                            limpar();
                            cout<<"Digite o valor da componente x do ponto de referencia da rotacao :"<<endl<<"rx=";
                            cin >> rx;
                            cout<<"Digite o valor da componente y do ponto de referencia da rotacao :"<<endl<<"ry=";
                            cin >> ry;
                            cout<<"Digite o valor do angulo de rotacao em graus:"<<endl<<"Angulo=";
                            cin >>angulo;
                            P.rotacionarPol(angulo,rx,ry);
                            break;
                        }
                        case 4:{
                            limpar();
                            cout << "O poligono e:" <<endl;
                            P.imprimePol();
                            cout<<endl;
                            break;
                        }
                        case 0:{
                            controlador = -1;
                            break;
                        }
                        case -1:{
                            exit(0);
                        }
                        default:{
                            break;
                        }
                    }
                }
                break;
            }

            default:{
                break;
            }

        }
    }
}
