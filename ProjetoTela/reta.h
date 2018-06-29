#ifndef RETA_H
#define RETA_H
#include "figurageometrica.h"
#include "screen.h"

/**
 * @brief A classe reta é classe filha da classe FiguraGeometrica.
 * @details Ela é capaz de desenhar uma reta.
 * A reta deverá ser especificada conforme a posição de dois pontos fornecidos.
 */

class Reta : public FiguraGeometrica
{
    /**
    * @brief O método reta constrói a reta
    * @details Ele define os paramêtros recebidos pelo usuário
    */

    int x1, x2, y1, y2;
public:
    /**
     * @brief Reta : Construtor da Classe Reta, em que são passados os dois pontos das extremidades
     *
     */
    Reta(int x1_,int y1_,int x2_,int y2_);
    /** @brief O método draw desenha a reta
    * @details Esse método é derivado método virtual de draw da classe figura
    */
    void draw(Screen &t);
};

#endif // RETA_H
