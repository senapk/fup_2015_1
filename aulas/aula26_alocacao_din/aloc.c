#include <stdio.h>
#include <stdlib.h>

int main(){
    int * vet;
    printf("Digite o tam do vetor no maximo da sua vontade\n");
    int tam = 0;
    scanf("%d", &tam); 
    vet = calloc(sizeof(int), tam);
    

    int i = 0;
    for(; i < tam; i++){
        scanf("%d", &vet[i]);
    }

    printf("Os elementos foram \n");
    for(i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
    free(vet);
    return 0;
}
