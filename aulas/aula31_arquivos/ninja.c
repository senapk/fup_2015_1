#include <stdio.h>
#include <string.h>

enum{MAX_NOME = 50};
typedef struct{
    char nome[MAX_NOME + 1];
    int qtd;
    float valor;
}Produto;

int main(){
    char texto[100];
    FILE * arq = fopen("entrada.txt", "r");
    FILE * saida = fopen("saida.txt", "a");
    fgets(texto, sizeof(texto), arq);
    fputs(texto, saida);
    Produto um;
    char *t = &texto[0];
    char *n;
    n =  strtok(texto, ";");
    strncpy(um.nome, n, MAX_NOME);
    n = strtok(NULL, ";");
    sscanf(n, "%d", &um.qtd);
    n = strtok(NULL, ";");
    sscanf(n, "%f", &um.valor);
	fprintf(saida, "Nome:%s,  qtd:%d, valor:%.2f\n", um.nome, um.qtd, um.valor);
    fclose(arq);
    fclose(saida);
    return 0;
}













