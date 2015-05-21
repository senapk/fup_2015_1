

#ifndef BITMON_H
#define BITMON_H

static const int MAX_FORCA = 20;
static const int MAX_VIDA = 200;
static const int MAX_RAIVA = 10;
static const int MAX_ATAQUES = 5;



enum{name_len = 4}; //atencao

typedef struct{
	char nome[name_len + 1]; //atencao
    int forca;
    int vida;
    int ataques;
    int raiva;
    int max_ataques;
}Bitmon;

Bitmon bit_criar(const char *nome, int forca, int vida, int max_ataques, int raiva);

Bitmon bit_criar_random();

//O Bitmon atac ataca o bitmon def
void bit_lutar(Bitmon * atac, Bitmon * def);

//Imprime um bitmon
void bit_mostrar(Bitmon bit);


#endif






