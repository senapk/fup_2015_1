#include <stdio.h>
#include <SFML/Graphics.h>

int main(void)
{
    sfRenderWindow * janela;
    sfVideoMode mode = {800, 600, 32};
    janela = sfRenderWindow_create(mode, "Janelinha", sfResize | sfClose, NULL);
    sfColor fundo = sfBlack;

    sfTexture * tpikachu;
    tpikachu = sfTexture_createFromFile("../imagens/pikachu.png", NULL);

    sfSprite * spikachu;
    spikachu = sfSprite_create();
    sfSprite_setTexture(spikachu, tpikachu, 0);
    //sfVector2f fator = {0.1, 0.1};
    sfSprite_setScale(spikachu, (sfVector2f){0.1, 0.1});

    float x = 0.0, y = 0.0;
    float vx = 0.0, vy = 0.0;
    while(sfRenderWindow_isOpen(janela)){
        sfEvent evento;
        while(sfRenderWindow_pollEvent(janela, &evento)){
            if(evento.type == sfEvtClosed){
                sfRenderWindow_close(janela);
            }
//            if(evento.type == sfEvtKeyPressed){
//                if(evento.key.code == sfKeyLeft)
//                    x--;
//            }
        }

        if(sfKeyboard_isKeyPressed(sfKeyLeft)){
            vx -= 0.1;
        }
        if(sfKeyboard_isKeyPressed(sfKeyRight)){
            vx += 0.1;
        }
        if(sfKeyboard_isKeyPressed(sfKeyUp)){
            vy -= 0.1;
        }
        if(sfKeyboard_isKeyPressed(sfKeyDown)){
            vy += 0.1;
        }

        //atualizacao da posicao pela velocidade
        x += vx;
        y += vy;

        //gravidade
        vy += 0.5;

        sfVector2u sizeJanela = sfRenderWindow_getSize(janela);
        sfFloatRect rectPik = sfSprite_getLocalBounds(spikachu);
        if(y + rectPik.height * 0.1 > sizeJanela.y){
            y = sizeJanela.y - rectPik.height * 0.1;
            vy = -vy * 0.7;
        }

        //tamanho.y

        sfRenderWindow_clear(janela, fundo);
        sfSprite_setPosition(spikachu, (sfVector2f){x, y});


        sfRenderWindow_drawSprite(janela, spikachu, NULL);
        sfRenderWindow_display(janela);
    }
    sfTexture_destroy(tpikachu);
    sfSprite_destroy(spikachu);
    sfRenderWindow_destroy(janela);
    return 0;
}

