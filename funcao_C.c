#include <stdio.h>  
#include <locale.h>  

//Declaração da Função  
int multiplicar(int x, int y);  

void main(){  
    setlocale(LC_ALL, "Portuguese");  

    int num1=3;  
    int num2=4;  
    int resultado=0;  

    printf("Antes de chamar a função:");  
    printf("\n Num 1 é: %d", num1);  
    resultado = multiplicar(num1, num2);  
    printf("\nO resultado da multiplicação é: %d", resultado);  

    printf("\n\nDepois de chamar a função:");  
    printf("\n Num 1 é: %d", num1);  
    printf("\n Num 2 é: %d", num2);  
}  

int multiplicar(int x, int y) {  
    x = 20; //Modificando o X para 20  
    return x * y;  
}