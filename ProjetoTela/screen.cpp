#include "screen.h"
#include <iostream>
#include <stdlib.h>


using namespace std;

Screen::Screen(int _nlin, int _ncol)
{
    if(_nlin<0 || _ncol<0){

      cout << "Definição da matriz invalida" << endl;

      exit(0);

    }


    nlin= _nlin;
    ncol= _ncol;

    mat = vector<vector<char>>(_nlin, vector<char>(_ncol, ' '));

    brush='*';


}

Screen::Screen()
{
    nlin =0;
    ncol =0;
    brush='*';
}

void Screen::setScreen(int x, int y)
{
    nlin= x;
    ncol= y;
    mat = vector<vector<char>>(x, vector<char>(y, ' '));
}

void Screen::setPixel(int x, int y)
{
    if(x>=nlin || y>=ncol || x<0 || y<0 ){
      cout<< "SETPIXEL -> Numero de linhas ou colunas invalidos";
        return;
    }

    mat[x][y]=(char)brush;
}

void Screen::clear()
{
    for(int i=0; i< nlin ; i++){
        for (int j=0; j<ncol; j++){

            mat[i][j]=' ';

        }

    }
}

void Screen::setBrush(char _brush)
{
    brush=_brush;
}

ostream& operator<<(ostream &os, Screen &t)
{
    for(int i=0; i<t.ncol; i++){

      for(int j=0; j<t.nlin; j++){

        os << t.mat[j][i] << " ";

      }

      os<< endl;

    }

    return os;
}
