#include <stdio.h>
#include "calc.h"

int main(){
    float a = 3.3, b = 2;
    printf("a=%f, b=%f\n", a, b);
    printf("soma %f\n", soma(a,b));
    printf("sub  %f\n", sub (a,b));
    printf("mult %f\n", mult(a,b));
    printf("div  %f\n", div(a,b));
    printf("pot  %f\n", pot(a,(int)b));
    return 0;
}

