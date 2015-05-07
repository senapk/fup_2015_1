#include <stdio.h>

enum _DIR {UP, DOWN, LEFT, RIGHT};
typedef enum _DIR DIR;

struct _Pos{
    int x;
    int y;
};
typedef struct _Pos Pos;

void andar(Pos * pos, DIR direcao){
    if(direcao == UP)
        pos->y = pos->y - 1;
    else if(direcao == DOWN)
        pos->y = pos->y + 1;
    else if(direcao == RIGHT)
        pos->x = pos->x + 1;
    else if(direcao == LEFT)
        pos->x = pos->x - 1;
}


/*void andar(int * x, int * y, DIR direcao){*/
    /*if(direcao == UP)*/
        /**y = *y - 1;*/
    /*else if(direcao == DOWN)*/
        /**y = *y + 1;*/
    /*else if(direcao == RIGHT)*/
        /**x = *x + 1;*/
    /*else if(direcao == LEFT)*/
        /**x = *x - 1;*/
/*}*/


void mostrar(int x, int y){
    printf("x = %d, y = %d\n", x, y);
}

int main(){
    Pos alex;
    alex.x = 5;
    alex.y = 3;
    mostrar(alex.x, alex.y);
    andar(&alex, LEFT);
    mostrar(alex.x, alex.y);
    andar(&alex, DOWN);
    mostrar(alex.x, alex.y);
    andar(&alex, RIGHT);
    return 0;
}
