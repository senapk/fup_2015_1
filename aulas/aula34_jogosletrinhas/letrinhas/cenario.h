#ifndef CENARIO_H
#define CENARIO_H
#include "letra.h"

typedef enum{FALSE = 0, TRUE = 1} boolean;

typedef struct{
    int qtd; //
    int max;
    Letra *vet;

    float largura;
    float altura;
}Cenario;

Cenario * cenario_create(int max, float largura, float altura);

void cenario_add_letra(Cenario * c, float vx, float vy);



void cenario_update(Cenario * c);

boolean cenario_jogo_continua(Cenario * c);

boolean cenario_del_letra(Cenario * c, char letra);

void cenario_destruir(Cenario * cenario);






#endif // CENARIO_H












