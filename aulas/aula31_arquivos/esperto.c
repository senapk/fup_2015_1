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
    char *t = &texto[0];
    char *n = &um.nome[0];
    for(; *t != ';'; t++, n++){
		*n = *t;
    }
	*n = '\0';
    char lixo;
    sscanf(t, "%c%d%c%f%c",
            &lixo, &um.qtd, &lixo, &um.valor, &lixo);
	printf("Nome:%s,  qtd:%d, valor:%.2f\n", um.nome, um.qtd, um.valor);
    return 0;
}













