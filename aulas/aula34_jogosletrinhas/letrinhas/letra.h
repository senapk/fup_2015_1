#ifndef LETRA_H
#define LETRA_H
#include <SFML/Graphics.h>

typedef struct{
    char c;
    float x, y;
    float vx, vy;
    float angulo;
    float vangular;//velocidade angular
    int tam;
}Letra;

Letra letra_criar(float largura, float vx, float vy, int tam);

void letra_desenhar(sfRenderWindow * janela, sfText * text, Letra letra);

void letra_update(Letra * letra);

#endif // LETRA_H











