#include <stdio.h>

int potencia(int base, int exp) {
    if (exp == 0) // Caso base: qualquer número elevado a 0 é 1
        return 1;
    else
        return base * potencia(base, exp - 1); // Chamada recursiva
}

int main() {
	system ("chcp 65001");
    int base, expoente;
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);
    
    printf("%d elevado a %d é %d\n", base, expoente, potencia(base, expoente));

    return 0;
}
