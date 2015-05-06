#include <string.h>
#include <stdio.h>

void mostrar_vetor(int vetor[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void somar_um(int x){
    x = x + 1;
}

void andar_um(int * pos){
    pos = pos + 1;
}

void somar_de_verdade(int * pos){
    *pos = *pos + 1;
}

int main(){

    int Z = 4;
    printf("%d\n", Z);
    somar_um(Z);
    printf("%d\n", Z);

    andar_um(&Z);

    somar_de_verdade(&Z);
    printf("%d\n", Z);

    int idade;
    float peso;
    char inicial;

    long qtd_estrelas = 12345412239804;
    unsigned int valor = 15;

    char * pos;
    pos = &inicial;

    idade = 5;
    peso = 15.68;
    inicial = 'S';

    int idades_filhos[3]; //alocacao estatica
    idades_filhos[0] = 4;
    idades_filhos[1] = 2;
    idades_filhos[2] = 0;
    //idades_filhos[5] = 0; //permitido, mas inadequado
    mostrar_vetor(idades_filhos, 3);

    float salarios[4] = {5.4, 6, 30.35, 70.123};
    printf("%.1f\n", salarios[3]);//70.1

    printf("%d\n", 'a');//

    char texto[] = "hoje eu aprendi ce";
    printf("%s\n", texto);
    texto[0] = 'H';
    texto[18] = ' ';
    printf("%s\n", texto);

    char nome[50];
    strcpy(nome, "David Sena");

    printf("%s\n", nome);


    return 0;
}
