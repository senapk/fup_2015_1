//robo.c
#include <stdio.h>
#include "ponto.h"

int main(){
    Ponto jiraia = {5, 8};
    andar(&jiraia, 'l');
    andar(&jiraia, 'u');
    printf("x:%d, y:%d\n", jiraia.x, jiraia.y);
    return 0;
}

