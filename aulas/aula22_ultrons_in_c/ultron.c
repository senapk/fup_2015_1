#include <stdio.h>
#include <string.h>

/*int len(char * texto){*/
    /*int i = 0;*/
    /*while(texto[i] != '\0')*/
        /*i++;*/
    /*return i;*/
/*}*/

/*int tam(char * texto){*/
    /*int cont = 0;*/
    /*while(*texto++ != '\0')*/
        /*cont++;*/
    /*return cont;*/
/*}*/

int contar(char * texto, char c){
    int cont = 0;
    int i = 0;
    while(texto[i] != '\0'){
        if(texto[i] == c)
            cont++;
        i++;
    }
    return cont;
}

int existe(char c, char * texto){
    int i = 0;
    for(i = 0;texto[i] != '\0'; i++)
        if(texto[i] == c)
            return 1;
    return 0;
}

char identificar(char * codigo, char * pessoa){
    int tamp = strlen(pessoa);
    int cont = 0;
    int p = 0;
    for(p = 0; p < tamp; p++)
        cont += existe(pessoa[p], codigo);
    if(cont == tamp)
        return 'c';
    if((float)cont/tamp > 0.5)
        return 'u';
    return 'p';
}

void append(char * texto, char c){
    int tam = strlen(texto);
    texto[tam] = c;
    texto[tam + 1] = '\0';
}

int main(){
    char codigo[11];
    char _frase[501];
    char pessoa[21] = "\0";

    fgets(codigo, sizeof(codigo), stdin);
    fgets(_frase, sizeof(_frase), stdin);
    char * frase = _frase;

    append(frase, ' ');
    while(*frase != '\0'){
        if(*frase == ' '){
            char r = identificar(codigo, pessoa);
            if(r == 'c')
                printf("chefe ");
            else if(r == 'u')
                printf("ultron ");
            if(r == 'p')
                printf("pessoa ");
            pessoa[0] = '\0';
        }else{
            append(pessoa, *frase);
        }
        frase++;
    }
    return 0;

}
