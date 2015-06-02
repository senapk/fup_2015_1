#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char * marmota_preencher(char * nome, int tam){
    char * vogais = "aeiou";
    nome[tam] = '\0';
    int i = 0;
    for(i = 0; i < tam; i++){
        if(i % 2 == 0)
            nome[i] = vogais[rand() % 5];
        else
            nome[i] = rand() % ('z' + 1 - 'a') + 'a';
    }
    return nome;
}

int main(){
    srand(time(NULL));
    int * qtd = malloc(sizeof(int));
    *qtd = 10;
    while((*qtd)--){
        int *min = malloc(sizeof(int));
        int *max = malloc(sizeof(int));
        *min = 4;
        *max = 10;
        int *tam = malloc(sizeof(int));
        *tam = rand() % (*max + 1 - *min) + *min;
        char * nome = calloc(*tam + 1, sizeof(char));
        marmota_preencher(nome, *tam);
        printf("%s\n", nome);
        free(nome);
        free(tam);
        free(min);
        free(max);
    }
    free(qtd);
    return 0;
}


int main2(){
    srand(time(NULL));
    float * vet; 
    int *tam = malloc(sizeof(int));
    *tam = 0;
    printf("Quantas notas voce tem?\n");
    scanf("%d", tam);
    vet = calloc(*tam, sizeof(float));
    printf("digite suas %d notas\n", *tam);
    int i = 0;
    for(i = 0; i < *tam; i++){
        scanf("%f", &vet[i]);
    }
    printf("Suas notas sao : ");
    for(i = 0; i < *tam; i++){
        printf("%3.2f ", vet[i]);
    }
    printf("\n");
    float * soma = malloc(sizeof(float));
    *soma = 0.0;
    for(i = 0; i < *tam; i++){
        *soma += vet[i]; 
    }
    *soma /= *tam;
    printf("Sua media foi %3.2f\n", *soma);
    free(vet); 
    free(tam);
    free(soma);
    return 0; 
}
