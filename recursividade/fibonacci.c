#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) // Caso base: Fibonacci(0) = 0 e Fibonacci(1) = 1
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2); // Chamada recursiva
}

int main() {
	system ("CHCP 65001");
    int numero;
    printf("Digite a posição para calcular o termo de Fibonacci: ");
    scanf("%d", &numero);
    
    if (numero < 0)
        printf("A posição não pode ser negativa.\n");
    else
        printf("O termo de Fibonacci na posição %d é %d\n", numero, fibonacci(numero));

    return 0;
}
