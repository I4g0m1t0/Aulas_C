// menu.c
#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"

int main() {
    int tamanho, opcao;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    // Aloca dinamicamente o vetor
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    
    // Preenche o vetor com números de 0 a tamanho - 1
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    // Embaralha o vetor
    embaralhar(vetor, tamanho);
    
    // Exibe o vetor embaralhado
    printf("Vetor embaralhado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    // Menu interativo
    printf("\nEscolha o método de ordenação:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Shell Sort\n");
    printf("5. Heap Sort\n");
    printf("6. Radix Sort\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);
    
    switch (opcao) {
        case 1:
            selection(vetor, tamanho);
            break;
        case 2:
            insertion(vetor, tamanho);
            break;
        case 3:
            bolha(vetor, tamanho);
            break;
        case 4:
            shell(vetor, tamanho);
            break;
        case 5:
            heapSort(vetor, tamanho);
            break;
        case 6:
            radixSort(vetor, tamanho);
            break;
        default:
            printf("Opção inválida.\n");
            free(vetor);
            return 1;
    }
    
    // Exibe o vetor ordenado
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    // Libera a memória alocada
    free(vetor);
    
    return 0;
}
