#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <math.h>

sfRenderWindow * criar_janela(int largura, int altura){
    sfVideoMode mode = {largura, altura, 32};
    sfRenderWindow * _janela = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(_janela, 20);
    return _janela;
}

typedef struct{
    int largura;
    int altura;
}Jogo;

typedef struct{
    float raio;
    sfVector2f cpos;
    sfVector2f vel;
    float angulo;
    float vangular;
}Bola;

Bola bola_criar(float raio, int largura){
    Bola b;
    b.raio = raio;
    int min = raio;
    int max = largura - raio;
    b.cpos = (sfVector2f){rand() % (max - min + 1) + min, raio};
    b.vel = (sfVector2f){0.0, 0.0};
    b.angulo = 0.0;
    b.vangular = 0.0;
    return b;
}

void bola_update(Bola * bola, float altura, float largura){
    bola->cpos.x += bola->vel.x;
    bola->cpos.y += bola->vel.y;
    bola->angulo += bola->vangular;

    if(bola->cpos.y + bola->raio > altura){
        //bola->vel.y *= -0.7;
        bola->vel.y = -fabs(bola->vel.y) * 0.7;
    }
    if(bola->cpos.y - bola->raio < 0){
        bola->vel.y *= -1;
    }
    if(bola->cpos.x - bola->raio < 0){
        bola->vel.x *= -1;
    }
    if(bola->cpos.x + bola->raio > largura){
        bola->vel.x *= -1;
    }
}

void bola_desenhar(Bola * b, sfRenderWindow * janela){
    sfCircleShape * obj = sfCircleShape_create();
    sfCircleShape_setPosition(obj, b->cpos);
    sfCircleShape_setFillColor(obj, sfBlack);
    sfCircleShape_setOutlineColor(obj, sfWhite);
    sfCircleShape_setOutlineThickness(obj, 2);

    sfCircleShape_setRadius(obj, b->raio);
    sfCircleShape_setOrigin(obj, (sfVector2f){b->raio, b->raio});
    sfRenderWindow_drawCircleShape(janela, obj, NULL);
    sfCircleShape_destroy(obj);
}

void bola_desenhar_sprite(Bola * b, sfSprite * sbola, sfRenderWindow * janela){

    sfFloatRect rect = sfSprite_getLocalBounds(sbola);


    sfSprite_setScale(sbola,
                      (sfVector2f){2 * b->raio / rect.width,
                                   2 * b->raio / rect.height});

    sfSprite_setOrigin(sbola, (sfVector2f){rect.width/2, rect.height/2});

    sfSprite_setRotation(sbola, b->angulo);
    sfSprite_setPosition(sbola, b->cpos);
    sfRenderWindow_drawSprite(janela, sbola, NULL);
}

int bola_clicar(Bola * pbola, sfVector2f pos){
    Bola bola = *pbola;
    if(pos.x >= bola.cpos.x - bola.raio){
        if(pos.x <= bola.cpos.x + bola.raio)
            if(pos.y > bola.cpos.y)
                if(pos.y < bola.cpos.y + bola.raio){
                    bola.vel.y = -15;
                    if(pos.x < bola.cpos.x){
                        bola.vel.x += 2;
                        bola.vangular += 2;
                    }else{
                        bola.vel.x -= 2;
                        bola.vangular -= 2;
                    }
                    *pbola = bola;
                    return 1;
                }

    }

    *pbola = bola;
    return 0;
}

int bola_clicou_dentro(Bola bola, sfVector2f pos){
    if(pos.x >= bola.cpos.x - bola.raio)
        if(pos.x <= bola.cpos.x + bola.raio)
            if(pos.y > bola.cpos.y - bola.raio)
                if(pos.y < bola.cpos.y + bola.raio)
                    return 1;
    return 0;
}

float distancia(sfVector2f a, sfVector2f b){
    return (float)sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

void bola_interagir(Bola * a, Bola * b){
    if(distancia(a->cpos, b->cpos) < 2 * a->raio){
        sfVector2f temp = a->vel;
        a->vel = b->vel;
        b->vel = temp;
    }
}

void bola_interagir_todos(Bola * vet, int tam){
    int i, j = 0;
    for(i = 0; i < tam - 1; i++){
        for(j = i + 1; j < tam; j++){
            bola_interagir(&vet[i], &vet[j]);
        }
    }
}




int main(void)
{
    Jogo jogo = {800, 600};

    sfRenderWindow * janela;
    sfMusic * music =
            sfMusic_createFromFile("../embaixadinhas/chute.ogg");

    janela = criar_janela(jogo.largura, jogo.altura);

    sfTexture * tbola = sfTexture_createFromFile("../embaixadinhas/bola.png", NULL);

    sfSprite * sbola = sfSprite_create();
    sfSprite_setTexture(sbola, tbola, sfTrue);


    int tam = 5;
    Bola vet[tam];
    int i = 0;
    for(i = 0; i < tam; i++){
        vet[i] = bola_criar(30.0, jogo.largura);
    }


    Bola * marcada = NULL;
    sfColor color = {50, 50, 30, 255};
    while(sfRenderWindow_isOpen(janela)){
        //tratamento dos eventos
        sfEvent evento;
        while(sfRenderWindow_pollEvent(janela, &evento)){
            if(evento.type == sfEvtClosed){
                sfRenderWindow_close(janela);
            }

            if(evento.type == sfEvtMouseButtonPressed){
                if(evento.mouseButton.button == sfMouseLeft){
                    sfVector2f pos = {evento.mouseButton.x,
                                      evento.mouseButton.y};

                    for(i = 0; i < tam; i++){
                        if(bola_clicar(&vet[i], pos)){
                            sfMusic_stop(music);
                            sfMusic_play(music);
                        }
                    }

                }
            }

            if(evento.type == sfEvtMouseButtonPressed){
                if(evento.mouseButton.button == sfMouseRight){
                    sfVector2f pos = {evento.mouseButton.x,
                                      evento.mouseButton.y};

                    for(i = 0; i < tam; i++){
                        if(bola_clicou_dentro(vet[i], pos))
                            marcada = &vet[i];
                    }
                }
            }
            if(evento.type == sfEvtMouseButtonReleased){
                if(evento.mouseButton.button == sfMouseRight){
                    marcada = NULL;
                }
            }

        }
        //tratamento dos estados
        if(sfMouse_isButtonPressed(sfMouseRight)){
            sfVector2i tmp = sfMouse_getPositionRenderWindow(janela);
            sfVector2f pos = {tmp.x, tmp.y};
            if(marcada != NULL){
                marcada->cpos = pos;
                marcada->vel = (sfVector2f){0, 0};
            }
        }
        //logica do jogo
        for(i = 0; i < tam; i++){
            vet[i].vel.y += 0.4;
            bola_update(&vet[i], jogo.altura, jogo.largura);
        }
        bola_interagir_todos(vet, tam);



        //limpar
        sfRenderWindow_clear(janela,  color);
        //desenhar
        for(i = 0; i < tam; i++)
            bola_desenhar_sprite(&vet[i], sbola, janela);
            //bola_desenhar(&vet[i], janela);

        //mostrar
        sfRenderWindow_display(janela);
    }
    sfSprite_destroy(sbola);
    sfTexture_destroy(tbola);
    sfMusic_destroy(music);
    sfRenderWindow_destroy(janela);
    return 0;
}














