#include <stdio.h>
#include <stdlib.h>

#define NUM_PESSOAS 5 // Número de pessoas a serem cadastradas

// Definindo a estrutura Pessoa
struct Pessoa {
    char nome[20]; // Vetor char para o nome
    char cpf[11];  // Vetor char para o CPF
    int idade;     // Inteiro para a idade
};

// Função para preencher os dados das pessoas
void preencherDados(struct Pessoa* pessoas) {
    for (int i = 0; i < NUM_PESSOAS; i++) {
        printf("Cadastro da pessoa %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", pessoas[i].nome); // Lê até a nova linha

        printf("CPF: ");
        scanf("%s", pessoas[i].cpf); // Lê o CPF

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade); // Lê a idade

        printf("\n"); // Linha em branco para melhor visualização
    }
}

// Função para imprimir os dados das pessoas
void imprimirDados(struct Pessoa* pessoas) {
    printf("Dados cadastrados:\n");
    for (int i = 0; i < NUM_PESSOAS; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("CPF: %s\n", pessoas[i].cpf);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("\n"); // Linha em branco para melhor visualização
    }
}

int main() {
    // Criando um ponteiro para a estrutura Pessoa
    struct Pessoa* pessoas = (struct Pessoa*)malloc(NUM_PESSOAS * sizeof(struct Pessoa));

    if (pessoas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1; // Encerra o programa se a alocação falhar
    }

    // Preenchendo os dados das pessoas
    preencherDados(pessoas);

    // Imprimindo os dados das pessoas
    imprimirDados(pessoas);

    // Liberando a memória
    free(pessoas);

    return 0;
}
