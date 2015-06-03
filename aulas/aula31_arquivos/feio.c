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
    fgets(texto, sizeof(texto), stdin);
    puts(texto);
    Produto um;
    int i = 0;
    for(i = 0; texto[i] != ';'; i++){
		um.nome[i] = texto[i];
    }
	um.nome[i] = '\0';
	char temp [50];
	int j = 0;
	for(i++; texto[i] != ';'; i++, j++){
		temp[j] = texto[i];
	}
	temp[j] = '\0';
	sscanf(temp, "%d", &um.qtd);
	
	for(i++, j = 0; texto[i] != ';'; i++, j++){
		temp[j] = texto[i];
	}
	temp[j] = '\0';
	sscanf(temp, "%f", &um.valor);
	
	printf("Nome:%s,  qtd:%d, valor:%.2f\n", um.nome, um.qtd, um.valor);
    return 0;
}













