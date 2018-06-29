#ifndef RETANGULO_H
#define RETANGULO_H
#include "figurageometrica.h"
#include "screen.h"
/**
 * @brief A classe retângulo é derivada da classe Figura Geométrica
 * @details Um retângulo deverá ser especificado conforme a posição do canto superior esquerdo,
 *  bem como largura e altura em pixels.
 */

class Retangulo : public FiguraGeometrica
{
    int x,y;
    int altura, largura;
    bool preenchido;
public:

    Retangulo(int x_,int y_,int largura_, int altura_, bool preenchido_);

    /**
     * @brief Método da classe que desenha o Retângulo em uma tela Screen.
     * @param t é a Tela Screen na qual o circulo será desenhado.
     */

    void draw(Screen &t);
};

#endif // RETANGULO_H
