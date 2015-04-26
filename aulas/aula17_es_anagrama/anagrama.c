#include <stdio.h>
#include <stdlib.h>

/*
1, 2, 2
2, 2, 1

abcddddb
abcbdddd
*/

int contar(int num, int vetor[], int tam){
    int cont = 0;
    int i;
    for (i = 0; i < tam; i++){
        int elem = vetor[i];

        if(elem == num)
            cont++;
    }
    return cont;
}

int * carregar_vetor(int tam){
    int *vetor;
    vetor = malloc( tam * sizeof(int));

    int i;
    for(i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }
    return vetor;
}


int main(){
//carregamento das informacoes
    int tam1;
    scanf("%d", &tam1);
    int * vetor1 = carregar_vetor(tam1);

    int tam2;
    scanf("%d", &tam2);
    int * vetor2 = carregar_vetor(tam2);

//algoritmo
    int iguais = 1;
    int i = 0;
    for(i = 0; i < tam1; i++){
        int x = vetor1[i];
        if (contar(x, vetor1, tam1) != contar(x, vetor2, tam2)) {
            iguais = 0;
            break;
        }
    }
    if (iguais)
        printf("sim\n");
    else
        printf("nao\n");
    return 0;
}




