#include <stdio.h>  
#include <locale.h>  
#include <stdlib.h> // Para malloc() e free()

// Declaração da Função  
int multiplicar(int* x, int y);  

void main(){  
    setlocale(LC_ALL, "Portuguese");  

    int* num1 = (int*) malloc(sizeof(int));  
    int* num2 = (int*) malloc(sizeof(int));  
    int resultado = 0;  

    if (num1 == NULL || num2 == NULL) {  
        printf("Erro na alocação de memória!\n");  
        return; 
    }

    *num1 = 3;  
    *num2 = 4;  

    printf("Antes de chamar a função:");  
    printf("\n Num 1 é: %d", *num1);  
    resultado = multiplicar(num1, *num2);  
    printf("\nO resultado da multiplicação é: %d", resultado);  

    printf("\n\nDepois de chamar a função:");  
    printf("\n Num 1 é: %d", *num1);  
    printf("\n Num 2 é: %d", *num2);  

    free(num1);  
    free(num2);  
}  

int multiplicar(int* x, int y) {  
    *x = 20; // Modificando o valor apontado por x para 20  
    return (*x) * y;  
}
