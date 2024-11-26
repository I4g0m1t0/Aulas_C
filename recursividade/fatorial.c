#include <stdio.h>

int fatorial(int n) {
    if (n <= 1) // Caso base: fatorial de 0 ou 1 é 1
        return 1;
    else
        return n * fatorial(n - 1); // Chamada recursiva
}

int main() {
	system ("chcp 65001");
    int numero;
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &numero);
    
    if (numero < 0)
        printf("Fatorial não é definido para números negativos.\n");
    else
        printf("Fatorial de %d é %d\n", numero, fatorial(numero));

    return 0;
}
