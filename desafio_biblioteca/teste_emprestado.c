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
void emprestarLivro(Livro *livros, int quantidade, int *emprestados);
void devolverLivro(Livro *livros, int quantidade, int *emprestados);

int main() {
    system("CHCP 65001");

    Livro *livros = NULL;
    int quantidade = 0;
    int emprestados = 0;
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
                emprestarLivro(livros, quantidade, &emprestados);
                break;
            case 4:
                devolverLivro(livros, quantidade, &emprestados);
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
    fgets((*livros)[*quantidade].titulo, sizeof((*livros)[*quantidade].titulo), stdin);
    (*livros)[*quantidade].titulo[strcspn((*livros)[*quantidade].titulo, "\n")] = '\0';

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
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

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

void emprestarLivro(Livro *livros, int quantidade, int *emprestados) {
    if (quantidade == 0) {
        printf("Nenhum livro cadastrado para emprestar.\n");
        return;
    }

    char titulo[200];
    printf("Digite o título do livro que deseja emprestar: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            if (livros[i].disponivel) {
                livros[i].disponivel = 0;
                (*emprestados)++;
                printf("Livro emprestado com sucesso!\n");
            } else {
                printf("Livro já está emprestado!\n");
            }
            return;
        }
    }
    printf("Livro não encontrado!\n");
}

void devolverLivro(Livro *livros, int quantidade, int *emprestados) {
    if (emprestados == 0) {
        printf("Nenhum livro emprestado para devolver.\n");
        return;
    }

    char titulo[200];
    printf("Digite o título do livro que deseja devolver: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            if (!livros[i].disponivel) {
                livros[i].disponivel = 1;
                (*emprestados)--;
                printf("Livro devolvido com sucesso!\n");
            } else {
                printf("Livro já está disponível!\n");
            }
            return;
        }
    }
    printf("Livro não encontrado!\n");
}
