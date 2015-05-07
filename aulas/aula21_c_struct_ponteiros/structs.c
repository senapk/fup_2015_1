
#include <stdio.h>

struct _Mm{
    int maior;
    int menor;
};

typedef struct _Mm Mm;

Mm maior_e_menor(int a, int b){
    Mm resp;
    if (b > a){
        resp.maior = b;
        resp.menor = a;
    }else{
        resp.maior = a;
        resp.menor = b;
    }
    return resp;
}

int main(){
    int x = 0;
    int y = 0;
    printf("Digite dois inteiros\n");
    scanf("%d%d",&x, &y);
    Mm res = maior_e_menor(x, y);
    printf("O maior eh %d e o menor eh %d\n",
            res.maior, res.menor);

    return 0;
}











