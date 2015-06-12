#include "visual.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

sfRenderWindow *criar_janela(int largura, int altura){
    sfVideoMode mode = {largura, altura, 32};
    sfRenderWindow * _janela = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(_janela, 20);
    return _janela;
}


Visual *visual_criar(int largura, int altura){
    Visual * visual = malloc(sizeof(Visual));

    visual->janela = criar_janela(largura, altura);
    visual->fonte = sfFont_createFromFile("/usr/share/fonts/truetype/droid/DroidSansMono.ttf");
    visual->texto = sfText_create();
    visual->clock = sfClock_create();
    sfText_setFont(visual->texto, visual->fonte);

    return visual;
}


void visual_desenhar_placar(Visual *vi, int acertos){
    char texto[10];
    sprintf(texto, "%d", acertos);
    sfText_setString(vi->texto, texto);
    sfText_setColor(vi->texto, sfGreen);
    sfText_setPosition(vi->texto, (sfVector2f){0, 0});
    sfText_setCharacterSize(vi->texto, 50);
    sfRenderWindow_drawText(vi->janela, vi->texto, NULL);
}


void visual_destruir(Visual *visual){
    sfText_destroy(visual->texto);
    sfFont_destroy(visual->fonte);
    sfClock_destroy(visual->clock);
    sfRenderWindow_destroy(visual->janela);
    free(visual);
}


int visual_passou_tempo(Visual *visual, int tempo){
    if(sfClock_getElapsedTime(visual->clock).microseconds >
            sfMilliseconds(tempo).microseconds){
        sfClock_restart(visual->clock);
        return 1;
    }
    return 0;
}


void visual_pegar_teclas(sfRenderWindow *_janela, char *teclas, int max){
    sfEvent event;
    int code = 0;
    int i = 0;
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
            if(code != 0){
                if(i < max){
                    teclas[i] = code;
                    i++;
                }
            }

        }
    }//while
    teclas[i] = '\0';
}
