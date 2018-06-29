#include "reta.h"
#include <iostream>

using namespace std;

void bresenham1(int x1, int y1, int x2, int y2, Screen &t);


Reta::Reta(int x1_,int y1_,int x2_,int y2_)
{
    x1=x1_;
    y1=y1_;
    x2=x2_;
    y2=y2_;
}

void Reta::draw(Screen &t)
{

    float dx , dy, step;

        float x,y,x0,y0;

        float xin,yin;



        x = x1;

        y = y1;

        x0 =x2;

        y0 = y2;



        if (y0<y) {

            dx = x - x0;

            dy = y - y0;

        }

        else {

            dx = x0 - x;

            dy = y0 - y;

        }



        if(dx>=dy) step=dx;

        else       step=dy;



        xin = dx / (float)step;

        yin = dy / (float)step;



        for(int k = 0; k < step; k++){

            if (y0<y) {

                t.setPixel((int)x0,(int)y0);

                x0 -= xin;

                y0 -= yin;

            } else {

                t.setPixel((int)x,(int)y);

                x += xin;

                y += yin;

            }

        }



}

