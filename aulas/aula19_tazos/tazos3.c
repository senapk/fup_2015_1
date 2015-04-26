#include <stdio.h>

int main(){
    int qtd;
    int vet[50];
    int i = 0;

    //LEITURA DOS DADOS
    scanf("%d", &qtd);
    for(i = 0; i < qtd; i++)
        scanf("%d", &vet[i]);


    //ALGORITMO
    int ganhador = vet[0];
    int record = 1;

    int cont = 1;
    for(i = 1; i < qtd; i++){
        if(vet[i] == vet[i - 1]){
            cont++;
        }else{
            if(cont > record){
                ganhador = vet[i - 1];
                record = cont;
                cont = 1;
            }
        }
    }

    if(cont > record){
        ganhador = vet[qtd - 1];
        record = cont;
    }

    printf("%d", ganhador);
    return 0;
}
