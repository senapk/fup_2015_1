

#include <stdio.h>
#include "bitmon.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

int randint(int x, int y){
	static int init = 1;
	if(init){
		init = 0;
		srand(time(NULL));
	}
	int dif = y - x + 1;
	return rand() % dif + x;
}

Bitmon bit_criar(const char * nome, int forca, int vida,
					int max_ataques, int raiva){
    Bitmon bit;
    strncpy(bit.nome, nome, name_len);
    bit.nome[name_len] = '\0';
    bit.forca = forca;
    bit.vida = vida;
    bit.max_ataques = max_ataques;
    bit.raiva = raiva;
    bit.ataques = max_ataques;
    return bit;
}

Bitmon bit_criar_random(){

	char nome[name_len + 1];
	int i = 0;
	for(; i < name_len; i++){
		nome[i] = randint('a', 'z');
	}
	nome[name_len] = '\0'; //atencao

    int forca = randint(MAX_FORCA/2, MAX_FORCA);
    int vida = randint(MAX_VIDA/2, MAX_VIDA);
    int max_ataques = randint(MAX_ATAQUES/2, MAX_ATAQUES);
    int raiva = randint(MAX_RAIVA/2, MAX_RAIVA);
    return bit_criar(nome, forca, vida, max_ataques, raiva);
}

void bit_lutar(Bitmon * atac, Bitmon * def){
    if ((atac->vida > 0) && (atac->ataques > 0) && (def->vida > 0)){
        def->vida -= atac->forca;
        atac->ataques -= 1;
        if (def->ataques == 0)
            def->forca += def->raiva;
        else{
            atac->vida -= def->forca;
            def->ataques -= 1;
        }
    }
}


void bit_mostrar(Bitmon bit){
	printf("%s", bit.nome);
    printf(", forca:%d, vida:%d, ataques:%d, raiva:%d\n",
            bit.forca, bit.vida, bit.ataques, bit.raiva);
}



