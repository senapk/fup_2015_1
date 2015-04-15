#include <stdio.h>

int main(){
    int num = 0;

    scanf("%d", &num);

    if(num % 2 == 0)
        printf("eh par\n");
    else
        printf("eh impar\n");

    return 0;
}
