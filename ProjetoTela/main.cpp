#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include "screen.h"
#include "figurageometrica.h"
#include "reta.h"
#include "retangulo.h"
#include "circulo.h"


using namespace std;

int main()
{
   Screen tela;

  list <FiguraGeometrica*> figuras;

    ifstream fin;
    ofstream fout;

    string s;

    fin.open("/home/cicero/Área de Trabalho/FiguraGeometrica/figurain.txt");
    fout.open("/home/cicero/Área de Trabalho/FiguraGeometrica/figuraout.txt");

    if(!fin.is_open()||!fout.is_open()){

          cout<< "Erro na abertura do arquivo";

          exit(-1);

 }


    // le uma linha completa para o string s

    while(fin.good()){

      getline(fin, s);

      if(fin.good()){

        string cmd;

        stringstream sstream(s);

        sstream >> cmd;

        if(cmd.compare("dim")==0){

          int xtela, ytela;

          sstream >> xtela >> ytela;

          tela.setScreen(xtela,ytela);

        }
        if(cmd.compare("brush")==0){

          char brush;

          sstream >> brush;

          tela.setBrush(brush);

        }
        if(cmd.compare("line")==0){

          int x0, y0, x1, y1;

          sstream >> x0 >> y0 >> x1 >> y1;

          if(x0 == x1 && y0 == y1){
              cout<<"parametro invalido para a reta (x=x1 e y0=y1)"<<endl;
          } else {

           figuras.push_back(new Reta(x0,y0,x1,y1));

          }


        }

        if(cmd.compare("rectangle")==0){

            int x0, y0, altura, largura;

            bool fillmode;

            sstream >>x0>> y0>> largura>> altura>>fillmode;

            figuras.push_back(new Retangulo(x0,y0,largura,altura,fillmode));

          }

        if(cmd.compare("circle")==0){

            int x0, y0, raio;

            bool fillmode;

            sstream >>x0>> y0>>raio>>fillmode;

            figuras.push_back(new Circulo(x0,y0,raio,fillmode));

          }



      }

    }
   for(auto it:figuras){

        it->draw(tela);

    }
    cout<<tela;
    fout<<tela;


    fin.close();
    fout.close();

    return 0;
}
