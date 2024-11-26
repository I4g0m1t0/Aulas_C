#include <stdio.h>
#include <stdlib.h> // Para malloc() e free()

const int TAMANHO = 5; // Tamanho pré-definido do vetor

int main() {
    // Alocando memória dinamicamente para o vetor
    int* vetor = (int*)malloc(TAMANHO * sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1; // Encerra o programa se a alocação falhar
    }

    // Preenchendo o vetor
    for (int i = 0; i < TAMANHO; i++) {
        printf("Digite o valor para o vetor[%d]: ", i+1);
        scanf("%d", &vetor[i]);
    }

    // Exibindo os valores do vetor
    printf("Os valores do vetor são: ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Liberando a memória
    free(vetor);

    return 0;
}
