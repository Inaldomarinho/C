#include "retangulo.h"
#include <iostream>

using namespace std;

void bresenham(int x1, int y1, int x2, int y2, Screen &t);

Retangulo::Retangulo(int x_, int y_, int largura_, int altura_, bool preenchido_)
{
            x=x_;
            y=y_;
            largura=largura_;
            altura=altura_;
            preenchido=preenchido_;
}

void Retangulo::draw(Screen &t)
{
     bresenham(x,y,x+largura,y, t);
     bresenham(x,y,x,y+altura, t);
     bresenham(x,y+altura,x+largura,y+altura, t);
     bresenham(x+largura,y+altura,x+largura,y, t);

     if(preenchido){

         for(int i=x; i<x+largura; i++){
             for(int j=y; j<y+altura; j++){

              t.setPixel(i,j);

             }
         }
     }
}

void bresenham(int x1, int y1, int x2, int y2, Screen &t){
       int slope;
       int dx, dy, incE, incNE, d, x, y;
       // Onde inverte a linha x1 > x2
       if (x1 > x2){
           bresenham(x2, y2, x1, y1, t);
            return;
       }
       if(x1==x2){
           if(y1<y2){
           for(int i=y1; i<y2; i++){
               t.setPixel(x1, i);
           }
           }
           else{
               for(int i=y2; i<y1; i++){
                   t.setPixel(x1, i);
               }
           }
           return;
       }
       dx = x2 - x1;
       dy = y2 - y1;

       if (dy < 0){
           slope = -1;
           dy = -dy;
       }
       else{
          slope = 1;
       }
       // Constante de Bresenham
       incE = 2 * dy;
       incNE = 2 * dy - 2 * dx;
       d = 2 * dy - dx;
       y = y1;
       for (x = x1; x <= x2; x++){
           t.setPixel(x, y);
           if (d <= 0){
             d += incE;
           }
           else{
             d += incNE;
             y += slope;
           }
       }
 }
