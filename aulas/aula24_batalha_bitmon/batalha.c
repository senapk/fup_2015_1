#include "batalha.h"
#include "bitmon.h"

void arena_iniciar(Arena * ar){
    int i = 0;
    for(i = 0; i < max_bitmons; i++){
        ar->vet[i] = bit_criar_random();
    }
    ar->qtd_vivos = max_bitmons;
    ar->round = 0;
}

void arena_mostrar(const Arena * ar){
    int i = 0;
    for(i = 0; i < ar->qtd_vivos; i++){
        bit_mostrar(ar->vet[i]);
    }
}


void arena_retirar_mortos(Arena * ar){

}

int arena_acabou_combate(Arena * ar){
     return 1;
}

Bitmon arena_pegar_vencedor(Arena * ar){
     return ar->vet[0];
}
