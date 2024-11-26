#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro {
    char titulo[200];
    char autor[200];
    int disponivel;
} Livro;


// Declarando as funções
void adicionarLivro(Livro **livros, int *quantidade);
void pesquisarLivro(Livro *livros, int quantidade);
void emprestarLivro(Livro *livros, int quantidade, int *emprestado);
void devolverLivro(Livro *livros, int quantidade, int *emprestado);


int main () {
    system("CHCP 65001");

    Livro *livros = NULL;

    int quantidade = 0; // Para poder armazenar mais de um livro
    int emprestado = 0; // Para contar a quantidade de livros emprestados
    int opcao;

    do {
        printf("\nMenu da biblioteca do Iaguinho:\n");
        printf("1. Adicionar novo livro\n");
        printf("2. Pesquisar livro por título\n");
        printf("3. Emprestar livro\n");
        printf("4. Devolver livro\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                adicionarLivro(&livros, &quantidade);
                break;
            case 2:
            	pesquisarLivro(livros, quantidade);
            	break;
            case 3:
            	emprestarLivro(livros, quantidade, &emprestado);
                break;
             case 4:
                devolverLivro(livros, quantidade, &emprestado);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    // Libera a memória alocada para os livros
    free(livros);
    return 0;
}

void adicionarLivro(Livro **livros, int *quantidade) {
    // Realocando memória para adicionar um novo livro
    *livros = realloc(*livros, (*quantidade + 1) * sizeof(Livro));
    if (*livros == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    // Entrada dos dados para o novo livro
    printf("\nLivro %d:\n", *quantidade + 1);

    printf("Título: ");
    fgets((*livros)[*quantidade].titulo, sizeof((*livros)[*quantidade].titulo), stdin); // Ler uma linha de texto e armazená-la no campo titulo de um struct Livro dentro de um array de structs.
    (*livros)[*quantidade].titulo[strcspn((*livros)[*quantidade].titulo, "\n")] = '\0'; // Remover o caractere de nova linha \n que fgets adiciona automaticamente ao final da string.

    printf("Autor: ");
    fgets((*livros)[*quantidade].autor, sizeof((*livros)[*quantidade].autor), stdin);
    (*livros)[*quantidade].autor[strcspn((*livros)[*quantidade].autor, "\n")] = '\0';

    (*livros)[*quantidade].disponivel = 1;  // Inicializa o status do livro como disponível

    // Incrementando a quantidade de livros
    (*quantidade)++;

    printf("Livro adicionado!\n");
}

void pesquisarLivro(Livro *livros, int quantidade) {
	if (quantidade == 0) {
        printf("Nenhum livro cadastrado para pesquisar.\n");
        return;
    }
    
    char titulo[200];
    printf("Digite o título do livro que deseja pesquisar: ");
    fgets(titulo, sizeof(titulo), stdin); // Scaneia o que o usuário digita
    titulo[strcspn(titulo, "\n")] = '\0';  // Remover o '\n'

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            printf("Livro encontrado: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Status: %s\n", livros[i].disponivel ? "Disponível" : "Emprestado");
            return;
        }
    }
    printf("Livro não encontrado!\n");
}

void emprestarLivro(Livro *livros, int quantidade, int *emprestado) {
    if (quantidade == 0) {
        printf("Nenhum livro cadastrado para emprestar.\n");
        return;
    }

    char titulo[200];
    printf("Digite o título do livro que deseja emprestar: ");
    fgets(titulo, sizeof(titulo), stdin); // Scaneia o que o usuário digita
    titulo[strcspn(titulo, "\n")] = '\0'; // Remover o '\n'

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) { // A função strcmp em C é usada para comparar duas strings
            if (livros[i].disponivel) { // Verifica se livros[i].disponivel é verdadeiro (diferente de zero)
                livros[i].disponivel = 0; // Modifica o status do livro para indisponível
                (*emprestado)++; // Para contar o número de livros que estão em situação de empréstimo
                printf("Livro emprestado com sucesso!\n");
            } else {
                printf("Livro já está emprestado!\n");
            }
            return;
        }
    }
    printf("Livro não encontrado!\n");
}

void devolverLivro(Livro *livros, int quantidade, int *emprestado) {
	if (*emprestado <= 0) {
        printf("Nenhum livro emprestado para devolver.\n");
        return;
    }
    
    char titulo[200];
    printf("Digite o título do livro que deseja devolver: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) { // A função strcmp em C é usada para comparar duas strings
            if (!livros[i].disponivel) { // Verifica se livros[i].disponivel é falso (diferente de um)
                livros[i].disponivel = 1; // Modifica o status do livro para disponível
                (*emprestado)--; // Para contar o número de livros que estão em situação de empréstimo
                printf("Livro devolvido com sucesso!\n");
            } else {
                printf("Livro já está disponível!\n");
            }
            return;
        }
    }
    printf("Livro não encontrado!\n");
}