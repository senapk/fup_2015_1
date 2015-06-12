#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "cenario.h"
#include <stdlib.h>
#include <time.h>

sfRenderWindow * criar_janela(int largura, int altura){
    sfVideoMode mode = {largura, altura, 32};
    sfRenderWindow * _janela = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(_janela, 20);
    return _janela;
}

int tk_peek(sfRenderWindow * _janela){
    sfEvent event;
    int code = 0;
    while(sfRenderWindow_pollEvent(_janela, &event)){
        if(event.type == sfEvtResized){
            sfFloatRect frect = {0, 0, event.size.width, event.size.height};
            sfView * view = sfView_createFromRect(frect);
            sfRenderWindow_setView(_janela, view);
            sfView_destroy(view);
        }
        if(event.type == sfEvtClosed)
            sfRenderWindow_close(_janela);
        if(event.type == sfEvtKeyPressed){
            int keycode = event.key.code;
            if(keycode >= sfKeyA && keycode <= sfKeyZ)
                code = 'a' - sfKeyA + keycode;
            if(keycode >= sfKeyNum0 && keycode <= sfKeyNum9)
                code = '0' - sfKeyNum0 + keycode;

            switch (keycode) {
                case sfKeyLBracket:     code = '['; break;
                case sfKeyRBracket:     code = ']'; break;
                case sfKeySemiColon:    code = ';'; break;
                case sfKeyComma:        code = ','; break;
                case sfKeyPeriod:       code = '.'; break;
                case sfKeyQuote:        code = '\''; break;
                case sfKeySlash:        code = '/'; break;
                case sfKeyBackSlash:    code = '\\'; break;
                case sfKeyTilde:        code = '~'; break;
                case sfKeyEqual:        code = '='; break;
                case sfKeyDash:         code = '-'; break;
                case sfKeySpace:        code = ' '; break;
                case sfKeyAdd:          code = '+'; break;
                case sfKeySubtract:     code = '-'; break;
                case sfKeyMultiply:     code = '*'; break;
                case sfKeyDivide:       code = '/'; break;
            }
        }
        /*case sfKeyLeft: sprintf(keyStr, "Left"); break;*/
        /*case sfKeyRight: sprintf(keyStr, "Right"); break;*/
        /*case sfKeyUp: sprintf(keyStr, "UP"); break;*/
        /*case sfKeyDown: sprintf(keyStr, "Down"); break;*/
    }//while

    return code;
}

static int angle = 0;

void desenhar_letra(sfRenderWindow * janela, sfText * text, Letra letra){
    char texto[2];
    texto[0] = letra.c;
    texto[1] = '\0';
    sfText_setColor(text, sfWhite);
    sfText_setString(text, texto);
    sfText_setPosition(text, (sfVector2f){letra.x, letra.y});
    sfText_setRotation(text, angle);
    sfText_setCharacterSize(text, 30);
    sfRenderWindow_drawText(janela, text, NULL);
}

void cenario_desenhar(Cenario * cenario, sfRenderWindow * janela, sfText * text){
    angle++;
    int i;
    for(i = 0; i < cenario->qtd; i++)
        desenhar_letra(janela, text, cenario->vet[i]);
}
void desenhar_placar(sfRenderWindow * janela, sfText * text, int acertos){
    char texto[10];
    sprintf(texto, "%d", acertos);
    sfText_setString(text, texto);
    sfText_setColor(text, sfGreen);
    sfText_setPosition(text, (sfVector2f){0, 0});
    sfText_setCharacterSize(text, 50);
    sfRenderWindow_drawText(janela, text, NULL);
}

int main(void)
{
    int largura = 800;
    int altura = 600;
    int max = 30;
    int tempo = 500;
    float vy = 3;
    int acertos = 0;
    sfRenderWindow * janela = criar_janela(largura, altura);
    sfFont * fonte = sfFont_createFromFile("/usr/share/fonts/truetype/droid/DroidSansMono.ttf");
    sfText * texto = sfText_create();
    sfClock * clock = sfClock_create();
    sfText_setFont(texto, fonte);
    Cenario * cenario = cenario_create(max, largura, altura);

    while(cenario_jogo_continua(cenario)){
        char tecla = tk_peek(janela);
        if(tecla != 0)
            if(cenario_del_letra(cenario, tecla)){
                vy *= 1.05;
                tempo *= 0.95;
                acertos++;
            }
        if(sfClock_getElapsedTime(clock).microseconds >
                sfMilliseconds(tempo).microseconds){
            cenario_add_letra(cenario, 0, vy);
            sfClock_restart(clock);
        }
        cenario_update(cenario);

        sfRenderWindow_clear(janela, sfBlack);

        cenario_desenhar(cenario, janela, texto);
        desenhar_placar(janela, texto, acertos);

        sfRenderWindow_display(janela);

    }
    cenario_destruir(cenario);
    sfFont_destroy(fonte);
    sfText_destroy(texto);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(janela);
    return 0;
}













