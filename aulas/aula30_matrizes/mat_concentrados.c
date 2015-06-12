#include <stdio.h>

enum{HOMEM = 0, MULHER = 1};

int existe_mulher(int mat[30][30], int lin, int col, int x, int y){
    if(x >= 0 && x < col){
        if(y >= 0 && y < lin)
            if(mat[y][x] == MULHER)
                return 1;
    }
    return 0;
}

int esta_concentrado(int mat[30][30], int lin, int col, int x, int y){
    //dir esq cima baixo
    int dx[] = {1, -1,  0, 0, -1,  1, 1, -1};
    int dy[] = {0,  0, -1, 1, -1, -1, 1,  1};
    int i = 0;
    for(i = 0; i < 8; i++){
        if(existe_mulher(mat, lin, col, x + dx[i], y + dy[i]))
            return 0;
    }
    return 1;
}


int main(){
    
    int mat[30][30];
    int lin, col;
    scanf("%d %d", &lin, &col);

    int x, y;
    for(y = 0; y < lin; y++){
        for(x = 0; x < col; x++)
        scanf("%d", &mat[y][x]);
    }
    
    
    int cont = 0;
    for(y = 0; y < lin; y++){
        for(x = 0; x < col; x++)
            if(mat[y][x] == HOMEM && esta_concentrado(mat, lin, col, x, y))
                cont++;
    }
    printf("%d\n", cont);
    
    return 0;   
}
