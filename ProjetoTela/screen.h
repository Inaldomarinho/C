#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief The Screen class é uma classe criada que representa a tela para desenho
 */
class Screen
{

    /**
       * @brief nlin Numero de Linhas
       * @brief ncol Numero de Colunas
       * @details Armazenam o tamanho da tela de desenho
       */
      int nlin, ncol;


      /**
       * @brief brush Guarda o caractere usado para desenhar
       */
      char brush;


      /**
       * @brief mat Armazena a matriz da tela
       */
      vector< vector<char> > mat;

public:
    // construtor da classe
      /**
       * @brief Screen Construtor da Classe que recebe como parametro o tamanho da tela.
       * @param _nlin Numero de linhas da matriz da tela.
       * @param _ncol Numero de colunas da matriz da tela.
       */
      Screen(int _nlin, int _ncol);

      /**
       * @brief Screen Construtor padrão da classe, onde todos os parametros são inicializados de forma padrão pre-definida.
       * @details O numero de linhas e de colunas são inicializados com 0 e é definido como Brush padrão o char '*'.
       */
      Screen();
      /**
       * @brief setScreen Redefini o tamanho da tela, modificando o tamanho da matriz.
       * @param x Numero de linhas da matriz da tela.
       * @param y Numero de colunas da matriz da tela.
       */
      void setScreen(int x, int y);

      /**
       * @brief setPixel Desenha um pixel da matriz usando o caratere guardado no Brush.
       * @param x Linha em que o caractere sera desenhado.
       * @param y Coluna em que o caractere sera desenhado.
       */
      void setPixel(int x, int y);

      /**
       * @brief clear Reseta a tela, colocando o char espaço em todos os lugares.
       */
      void clear();

      /**
       * @brief setBrush Muda o caractere de desenho Brush.
       * @param _brush Recebe como parametro o novo caractere Brush.
       */
      void setBrush(char _brush);


      /**
       * @brief O método serve para enviar a tela para um stream de saida.
       * @details Ele é uma sobrecarga do operador << para realizar a impressão.
       */
      friend ostream& operator<<(ostream &os, Screen &t);

};

#endif // SCREEN_H
