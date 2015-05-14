#include "calc.h"
#include <math.h>

float soma (float a, float b){
    return a + b;
}

float sub (float a, float b){
    return a - b;
}

float mult (float a, float b){
    return a * b;
}

float div (float a, float b){
    return a / b;
}

float pot (float a, int b){
    int i = 0;
    float res = 1;
    for(; i < b; i++){
        res *= a;
    }
    return res;
}

