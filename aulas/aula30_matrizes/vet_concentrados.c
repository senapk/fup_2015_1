#include <stdio.h>

enum{HOMEM = 0, MULHER = 1};

int existe_mulher(int * vet, int qtd, int ind){
    if(ind >= 0 && ind < qtd){
        if(vet[ind] == MULHER)
            return 1;
    }
    return 0;
}

int esta_concentrado(int * vet, int qtd, int ind){
    if(existe_mulher(vet, qtd, ind - 1) || existe_mulher(vet, qtd, ind + 1))
        return 0;
    return 1;
}


int main(){
    
    int vet[30];
    int qtd;
    scanf("%d", &qtd);
    int i = 0;
    for(i = 0; i < qtd; i++){
        scanf("%d", vet + i);
    }
    
    int cont = 0;
    for(i = 0; i < qtd; i++){
        if(vet[i] == HOMEM && esta_concentrado(vet, qtd, i))
            cont++;
    }
    printf("%d\n", cont);
    
    return 0;   
}
