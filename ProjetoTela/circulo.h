#ifndef CIRCULO_H
#define CIRCULO_H
#include "figurageometrica.h"
#include "screen.h"
/**
 * @brief The Circulo class é uma classe derivada da classe figura geometrica
 * @details A classe representa um circulo de raio R centrado no ponto (x,y) e pode ser preenchido ou não
 */

class Circulo : public FiguraGeometrica
{

    /**
     * @brief x Coordenada X do centro
     * @brief y Coordenada Y do centro
     * @brief r Raio do circulo
     */
    int x,y, r;

    /**
     * @brief preenchido Variavel booleana que informa se o circulo sera preenchido ou não.
     * 1 para preenchido, 0 para não preenchido.
     */

    bool preenchido;

public:

    /**
     * @brief Circulo Construtor padrão do circulo.
     * @details Define os parametros recebidos pelo usuario.
     */
    Circulo(int x_, int y_, int r_, bool preenchido_);

    /**
     * @brief draw Metodo da classe que desenha o circulo em uma tela Screen.
     * @param t Tela Screen na qual o circulo sera desenhado.
     */
    void draw(Screen &t);
};

#endif // CIRCULO_H
