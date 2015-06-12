#ifndef VISUAL_H
#define VISUAL_H
#include <SFML/Graphics.h>

typedef struct{
    sfRenderWindow * janela;
    sfFont * fonte;
    sfText * texto;
    sfClock * clock;
}Visual;

Visual * visual_criar(int largura, int altura);

void visual_desenhar_placar(Visual * vi, int acertos);

void visual_destruir(Visual * visual);

int visual_passou_tempo(Visual * visual, int tempo);


void visual_pegar_teclas(sfRenderWindow * _janela, char * teclas, int max);

#endif // VISUAL_H


















