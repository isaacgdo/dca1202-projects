#include "screen.h"
#include <iostream>

using namespace std;

//constructor
Screen::Screen(int _nlin, int _ncol)
{
    nlin = _nlin;
    ncol = _ncol;
    mat = vector<vector<char>>(nlin, vector<char>(ncol,' '));
}

void Screen::setPixel(int x, int y)
{
    if((x >=0 && x < nlin) && (y >= 0 && y < ncol)){
        mat[x][y] = brush;
    }
}

void Screen::clear()
{
    for(int i=0; i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            mat[i][j] = ' ';
        }
    }
}

void Screen::setBrush(char _brush)
{
    brush = _brush;
}

ostream& operator<<(ostream &os, Screen &t)
{
    for(int i=0; i<t.nlin; i++){
        for(int j=0; j<t.ncol; j++){
            os << t.mat[i][j];
        }
        os << endl;
    }

    return os;
}
