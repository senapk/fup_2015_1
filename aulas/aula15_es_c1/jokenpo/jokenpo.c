#include <stdio.h>

int main(){
    char op1 = '\0';
    char op2 = '\0';
    printf("Digite a opcao 1 e a opcao 2 sem espaco\n");
    scanf("%c%c", &op1, &op2);

    if(op1 == op2)
    {
        printf("empate");
    }
    else if((op1 == 'r' && op2 == 's') ||
            (op1 == 's' && op2 == 'p') ||
            (op1 == 'p' && op2 == 'r'))
        printf("op1\n");
    else
    {
        printf("op2\n");
    }

    printf("voce escolheu %c e %c\n", op1, op2);

    return 0;
}
