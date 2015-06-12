#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "cenario.h"
#include <stdlib.h>
#include <time.h>
#include "visual.h"
#include <string.h>

int main(void)
{
    int largura = 800;
    int altura = 600;
    int max = 10;
    int tempo = 500;
    float vy = 3;
    int acertos = 0;
    Visual * visual = visual_criar(largura, altura);
    Cenario * cenario = cenario_create(max, largura, altura);

    while(cenario_jogo_continua(cenario)){
        char teclas[101];

        visual_pegar_teclas(visual->janela, teclas, 100);
        int qtd = strlen(teclas);
        int i = 0;
        for(i = 0; i < qtd; i++){
            if(cenario_del_letra(cenario, teclas[i])){
                vy *= 1.05;
                tempo *= 0.95;
                acertos++;
            }
        }

        if(visual_passou_tempo(visual, tempo)){
            cenario_add_letra(cenario, 0, vy, 30);
        }

        cenario_update(cenario);
        sfRenderWindow_clear(visual->janela, sfBlack);
        cenario_desenhar(cenario, visual->janela, visual->texto);
        visual_desenhar_placar(visual, acertos);

        sfRenderWindow_display(visual->janela);

    }
    cenario_destruir(cenario);
    visual_destruir(visual);
    return 0;
}













