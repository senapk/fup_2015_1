#include <stdio.h>
#include <string.h>

int main(){
    char str[100] = "25 4.5";
    int d;
    float f;
    sscanf(str, "%d %f", &d, &f);
    printf("%d %f\n", d, f);

    sprintf(str, "%d %f", 54, 5.63);
    puts(str);
    return 0;
}
