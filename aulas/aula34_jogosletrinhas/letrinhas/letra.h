#ifndef LETRA_H
#define LETRA_H

typedef struct{
    char c;
    float x, y;
    float vx, vy;
}Letra;

Letra letra_criar(float largura, float vx, float vy);

void letra_update(Letra * letra);

#endif // LETRA_H











