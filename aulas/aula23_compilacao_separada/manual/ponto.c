//ponto.c
#include "ponto.h"

//char dir = u, d, l, r
void andar(Ponto * p, char d){
    if(d == 'u')
        p->y--;
    if(d == 'd')
        p->y++;
    if(d == 'l')
        p->x--;
    if(d == 'r')
        p->x++;
}
