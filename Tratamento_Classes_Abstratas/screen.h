#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

class Screen
{
private:
    int nlin, ncol;
    char brush = '*';

    vector< vector<char> > mat;
public:
    Screen(int _nlin = 10, int _ncol = 10);
    void setPixel(int x, int y);
    void clear();
    void setBrush(char _brush = ' ');
    friend ostream& operator<<(ostream &os, Screen &t);
};

#endif // SCREEN_H
