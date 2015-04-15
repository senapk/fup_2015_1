#include <stdio.h>

int main(){ char op1 = 0; char op2 = 0;
    printf("Digite as duas opcoes\n");
    scanf("%c %c", &op1, &op2);

    if (op1 == op2)
    {
        printf("empate\n");
    }
    else
    {
        if((op1 == 'r' && op2 == 's') ||
             (op1 == 's' && op2 == 'p') ||
             (op1 == 'p' && op2 == 'r'))
        {
            printf("jog1\n"); } else {
            printf("jog2\n");
        }
    }

    return 0;
}
