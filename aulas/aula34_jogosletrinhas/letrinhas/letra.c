#include "letra.h"
#include <stdlib.h>


Letra letra_criar(float largura, float vx, float vy){
    Letra letra;
    letra.c = rand() % ('z' - 'a' + 1) + 'a';
    letra.y = 0;
    letra.x = rand() % (int)largura;
    letra.vx = vx;
    letra.vy = vy;
    return letra;
}


void letra_update(Letra *letra){
    letra->x += letra->vx;
    letra->y += letra->vy;
}





















