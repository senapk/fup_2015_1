#include <stdio.h>

int main(){
    int a = 0, b = 0;

    scanf("%d %d", &a, &b);

    int total = 1;

    int i = 0;
    for(i = 0; i < b; i++)
        total = total * a;

    printf("%d\n", total);
    return 0;
}
