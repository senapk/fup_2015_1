#include <stdio.h>

void main(){

    int a = 0;
    int b = 0;
    char op;
    printf("digite dois valores\n");
    scanf("%d%d", &a, &b);
    printf("digite a operacao\n");
    scanf("\n%c", &op);
    int c = 0;
    if(op == '+')
        c = a + b;
    else if(op == '-')
        c = a - b;
    else if(op == '*')
        c = a * b;
    else if(op == '/')
        c = a / b;
    else
        printf("op invalida\n");
    printf("%d", c);
}
