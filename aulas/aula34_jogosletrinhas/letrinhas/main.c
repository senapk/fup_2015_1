#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "cenario.h"
#include <stdlib.h>
#include <time.h>
#include "visual.h"
#include <string.h>

void mensagem_final(Visual * visual, int acertos);

int main(void)
{
    int largura = 800;
    int altura = 600;
    int max = 5;
    int tempo = 1000;
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

    mensagem_final(visual, acertos);


    cenario_destruir(cenario);
    visual_destruir(visual);
    return 0;
}



void mensagem_final(Visual * visual, int acertos){
    while(sfRenderWindow_isOpen(visual->janela)){

        sfEvent event;
        while(sfRenderWindow_pollEvent(visual->janela, &event)){
            if(event.type == sfEvtClosed)
                sfRenderWindow_close(visual->janela);
            if(event.type == sfEvtMouseButtonPressed)
                if(event.mouseButton.button == sfMouseLeft)
                    printf("%d %d left\n", event.mouseButton.x, event.mouseButton.y);
        }

        sfRenderWindow_clear(visual->janela, sfBlack);

        char texto[100];
        sprintf(texto, "Voce teve %d acertos, feche a tela", acertos);
        sfText_setRotation(visual->texto, 0);
        sfText_setString(visual->texto, texto);
        sfText_setColor(visual->texto, sfRed);
        sfText_setPosition(visual->texto, (sfVector2f){0, 100});
        sfText_setCharacterSize(visual->texto, 30);
        sfRenderWindow_drawText(visual->janela, visual->texto, NULL);

        sfRenderWindow_display(visual->janela);
    }
}









