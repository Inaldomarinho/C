#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "screen.h"

/**
 * @brief A classe Figura geométrica é uma classe abstrata.
 * @details Ela servirá de base para as classes que serão desenhadas na tela.
 */
class FiguraGeometrica
{
public:
    FiguraGeometrica();
    /**
     * @brief draw: Método Virtual que toda classe filha irá implementar.
     * @details As classes filhas terão que implementar um método "draw" para
     * desenhar na tela.
     * @param t : Tela que será desenhada a figura
     */
    virtual void draw(Screen &t)=0;

};

#endif // FIGURAGEOMETRICA_H
