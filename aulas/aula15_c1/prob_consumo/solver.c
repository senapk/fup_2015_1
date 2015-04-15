#include <stdio.h>

int main(){
    float vel = 0.0, tempo = 0.0, consumo = 0.0;

    printf("Digite vel, tempo, consumo\n");
    scanf("%f %f %f", &vel, &tempo, &consumo);

    tempo /= 60; //convertendo de minuto para hora

    float desemp = vel * tempo / consumo;
    printf ("O desempenho eh %.2f km/l", desemp);

    return 0;
}
