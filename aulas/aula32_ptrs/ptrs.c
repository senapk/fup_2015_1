#include <stdio.h>

void pular(char ** nome){
    while(**nome != ' '){
        *nome += 1;
    }
    *nome += 1;
}

int main() {
    char nome[] = "Daniel Sun";
    char *p = &nome[0];
    printf("%s\n", p);
    pular(&p);
    printf("%s\n", p);
    return 0;
}

