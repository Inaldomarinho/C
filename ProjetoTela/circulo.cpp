#include "circulo.h"
#include <cmath>
#include <iostream>

Circulo::Circulo(int x_, int y_, int r_, bool preenchido_)
{

x=x_;
y=y_;
r=r_;
preenchido=preenchido_;

}

void Circulo::draw(Screen &t)
{
    int xdesenho, ydesenho, d;
     xdesenho = 0;
     ydesenho = r;
     d = 1 - r;

     t.setPixel(x+xdesenho, y+ydesenho);
     t.setPixel(x-xdesenho, y+ydesenho);
     t.setPixel(x-ydesenho, y+xdesenho);
     t.setPixel(x-ydesenho, y-xdesenho);
     t.setPixel(x-xdesenho, y-ydesenho);
     t.setPixel(x+xdesenho, y-ydesenho);
     t.setPixel(x+ydesenho, y-xdesenho);
     t.setPixel(x+ydesenho, y+xdesenho);



     while(ydesenho > xdesenho){
       if(d < 0){
         d = d + 2*xdesenho  + 3;
         xdesenho = xdesenho + 1;
       }
       else{
         d = d + 2*(xdesenho-ydesenho) + 5;
         xdesenho = xdesenho + 1;
         ydesenho = ydesenho - 1;
       }

       t.setPixel(x+xdesenho, y+ydesenho);
       t.setPixel(x-xdesenho, y+ydesenho);
       t.setPixel(x-ydesenho, y+xdesenho);
       t.setPixel(x-ydesenho, y-xdesenho);
       t.setPixel(x-xdesenho, y-ydesenho);
       t.setPixel(x+xdesenho, y-ydesenho);
       t.setPixel(x+ydesenho, y-xdesenho);
       t.setPixel(x+ydesenho, y+xdesenho);


     }
     if(preenchido){

       for(int i=x-r; i<x+2*r;i++){
         for(int j=y-r;j<y+2*r;j++){

             if(sqrt(pow(i-x,2)+pow(j-y,2))<r){

                 t.setPixel(i,j);

             }

         }
       }
     }

}
