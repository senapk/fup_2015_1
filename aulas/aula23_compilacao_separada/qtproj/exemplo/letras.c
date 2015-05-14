#include "letras.h"

int eh_minusculo(char c){
    if(c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int eh_maiusculo(char c){
    if(c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

int eh_digito(char c){
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}
