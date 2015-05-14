#include <stdio.h>

struct _Snake{
    int x;
    int y;
    int dir;
    char cor; //rgb
    char face;
};

typedef struct _Snake Snake;

const int DIRE = 0;
const int BAIXO = 1;
const int ESQ = 2;
const int CIMA = 3;

/*int colidiu(int xc, int yc, int xm, int ym)*/

void andar(Snake * snake){
    if(snake->dir == DIRE)
        snake->x += 1;
    if(snake->dir == ESQ)
        snake->x += -1;
    if(snake->dir == CIMA)
        snake->y += -1;
    if(snake->dir == BAIXO)
        snake->y += 1;
}

//rot +1 para direita
//rot -1 para esquerda
void virar(Snake * snake, int rot){
    char faces[] = "<A>V";
    (*snake).dir = snake->dir + rot;
    if(snake->dir == 4)
        snake->dir = 0;
    if(snake->dir == -1)
        snake->dir = 3;
    (*snake).face = faces[snake->dir];
}


//direcoes
//d = direita
//e = esquerda
//c = cima
//b = baixo
void mostrar(Snake snake){
    printf("x = %d, y = %d, direcao = ", snake.x, snake.y);
    if(snake.dir == DIRE)
        printf("direita");
    else if(snake.dir == ESQ)
        printf("esquerda");
    else if(snake.dir == CIMA)
        printf("cima");
    else if(snake.dir == BAIXO)
        printf("baixo");
    printf("%c\n", snake.face);
}


int main(){
    Snake bia;
    bia.x = 5;
    bia.y = 7;
    bia.dir = DIRE;
    bia.face = '<';

    andar(&bia);
    mostrar(bia);
    virar(&bia, -1);
    mostrar(bia);
    return 0;
}





