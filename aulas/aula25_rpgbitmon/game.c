#include <stdio.h>
#include <string.h>
//####### bitmon.h

typedef enum{False = 0, True = 1} boolean;

static const int MAX_FORCA = 20;
static const int MAX_VIDA = 200;

typedef struct{
    char id;
    int forca;
    int vida;
}Bitmon;

Bitmon bit_criar(char id, int forca, int vida);

Bitmon bit_criar_random(char id);

//O Bitmon atac ataca o bitmon def
boolean bit_lutar(Bitmon * atac, Bitmon * def);

//Imprime um bitmon
void bit_mostrar(Bitmon bit);


//############ game.c

int main(){

    Bitmon heroi = bit_criar('D', 34, 2000);
    int vitorias = 0;

    char resposta[20];
    while(heroi.vida > 0){
        bit_mostrar(heroi);
        /*printf("Voce deseja lutar(sim/nao)?\n");*/
        /*fgets(resposta, 19, stdin); */
        /*if(strcmp(resposta, "nao\n"))*/
        /*break;*/
        Bitmon enemy = bit_criar_random('E');
        while(bit_lutar(&heroi, &enemy) == True);

        if(heroi.vida < 0){
            printf("Voce eh um patinho morto, chola mais!\n");
            break;
        }else{
            vitorias++;
        }
    }
    printf("Voce venceu %d vezes\n", vitorias);

    return 0;
}

//###### bitmon.c
#include <stdlib.h>//rand() e srand()
#include <time.h>//time()

Bitmon bit_criar(char id, int forca, int vida){
    Bitmon bit;
    bit.id = id;
    bit.forca = forca;
    bit.vida = vida;
    return bit;
}

Bitmon bit_criar_random(char id){
    static int init = 1;
    if(init == 1){
        init = 0;
        srand(time(NULL));
    }

    int forca = rand() % MAX_FORCA + 10;
    int vida = rand() % MAX_VIDA + 10;
    return bit_criar(id, forca, vida);
}

boolean bit_lutar(Bitmon * atac, Bitmon * def){
    if ((atac->vida > 0) && (def->vida > 0)){
        printf("%c ataca %c f%d, ", atac->id, def->id, atac->forca);
        def->vida -= atac->forca;
        printf("%c revida f%d", def->id, def->forca);
        atac->vida -= def->forca;
        printf("\n");
        bit_mostrar(*atac);
        bit_mostrar(*def);
        return True;
    }
    return False;
}


void bit_mostrar(Bitmon bit){
    printf("%c[", bit.id);
    printf("f%d,v%d] \n", bit.forca, bit.vida);
}




