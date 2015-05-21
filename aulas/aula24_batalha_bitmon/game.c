#include <stdio.h>
#include "bitmon.h"
#include "batalha.h"
int main(){
    Arena arena;
    arena_iniciar(&arena);
    arena_mostrar(&arena);
    while(!arena_acabou_combate(&arena)){
        /*arena_round(&arena);*/
        arena_retirar_mortos(&arena);
        arena_mostrar(&arena);
    }
    return 0;
}
