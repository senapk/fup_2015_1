#include <stdio.h>

void next_word(char ** f, char * palavra){
    char * p = &palavra[0]; 

    while((**f != ' ') && (**f != '\0')){
        *p = **f;
        p++;
        *f += 1;
    }
    if(**f == ' ')
        *f += 1;
    *p = '\0';
}

int main(){
    char * frase = "batata foi frita na banha do porco";
    char palavra[30];
    char *f = frase;
    while(*f != '\0'){
        next_word(&f, palavra);
        printf("%s\n", palavra);
    }
    return 0;
}
