#include <stdio.h>

int count(int vet[], int qtd, int elem){
    int cont = 0;
    int i = 0;
    for (i = 0; i < qtd; i++)
        if (vet[i] == elem)
            cont++;
    return cont;
}

int main(){
    int qtd;
    int vet[50];
    int ocor[50];

    scanf("%d", &qtd);
    int i = 0;
    for(i = 0; i < qtd; i++)
        scanf("%d", &vet[i]);


    for(i = 0; i < qtd; i++)
        ocor[i] = count(vet, qtd, vet[i]);

    int maior = vet[0];
    for(i = 0; i < qtd; i++)
        if(vet[i] > maior)
            maior = vet[i];

    printf("%d", maior);
    return 0;
}
