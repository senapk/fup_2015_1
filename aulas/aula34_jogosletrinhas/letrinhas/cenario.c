#include "cenario.h"
#include <stdio.h>
#include <stdlib.h>

//declaracao funcoes do modulo
void swap(Letra * a, Letra * b);
void remover_letra(Letra * vet, int * tam, int ind);

//implementacao funcoes do modulo

Cenario *cenario_create(int max, float largura, float altura){
    Cenario * cenario = malloc(sizeof(Cenario));
    cenario->qtd = 0;
    cenario->max = max;
    cenario->vet = malloc(sizeof(Letra) * max);
    cenario->largura = largura;
    cenario->altura = altura;

    return cenario;
}

void cenario_desenhar(Cenario * cenario, sfRenderWindow * janela, sfText * text){
    int i;
    for(i = 0; i < cenario->qtd; i++)
        letra_desenhar(janela, text, cenario->vet[i]);
}

void cenario_add_letra(Cenario *c, float vx, float vy, int tam){
    if(c->qtd < c->max){
        c->vet[c->qtd] = letra_criar(c->largura, vx, vy, tam);
        c->qtd++;
    }
}

void cenario_update(Cenario *c){
    int i = 0;
    for(i = 0; i < c->qtd; i++)
        letra_update(&c->vet[i]);
}


boolean cenario_jogo_continua(Cenario *c){
    int i = 0;
    for(i = 0; i < c->qtd; i++)
        if(c->vet[i].y + 30 > c->altura )
            return FALSE;
    return TRUE;
}


boolean cenario_del_letra(Cenario *c, char letra){
    int i = 0;
    for(i = 0; i < c->qtd; i++){
        if(c->vet[i].c == letra){
            remover_letra(c->vet, &c->qtd, i);
            return TRUE;
        }
    }
    return FALSE;
}


void cenario_destruir(Cenario *cenario){
    free(cenario->vet);
    free(cenario);
}






//FUNCOES AUXILIARES
void swap(Letra *a, Letra *b){
    Letra aux = *a;
    *a = *b;
    *b = aux;
}


void remover_letra(Letra *vet, int *tam, int ind){
    swap(&vet[*tam - 1], &vet[ind]);
    (*tam)--;
}














