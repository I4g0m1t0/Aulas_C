// metodo.h
#ifndef METODO_H
#define METODO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int disponivel; // simples true(1) or false (0)
} Livro;

void strToUpper(char *str) {
    while (*str) {
        *str = toupper((unsigned char) *str);
        str++;
    }
} // Função para converter uma string para maiúsculas



void adicionarLivro(Livro **biblioteca, int *numLivros, const char *titulo, const char *autor) {
    *biblioteca = realloc(*biblioteca, (*numLivros + 1) * sizeof(Livro)); //array dinamico para acomodar os livros
    strcpy((*biblioteca)[*numLivros].titulo, titulo); //copiar titulo e acessar
    strcpy((*biblioteca)[*numLivros].autor, autor); //copiar biblioteca e acessar
    (*biblioteca)[*numLivros].disponivel = 1;
    (*numLivros)++;
} // Função para adicionar um novo livro


Livro* pesquisarLivro(Livro *biblioteca, int numLivros, const char *titulo) {
    char tituloUpper[100];
    strcpy(tituloUpper, titulo);
    strToUpper(tituloUpper); //sistema de topper para conversão de letras maiusculas e minusculas EVITA ERROS

    for (int i = 0; i < numLivros; i++) {
        char tituloLivroUpper[100];
        strcpy(tituloLivroUpper, biblioteca[i].titulo);
        strToUpper(tituloLivroUpper);

        if (strcmp(tituloLivroUpper, tituloUpper) == 0) {
            return &biblioteca[i];
        }
    }
    return NULL;
} // Função para pesquisar um livro pelo título


int emprestarLivro(Livro *biblioteca, int numLivros, const char *titulo) {
    Livro *livro = pesquisarLivro(biblioteca, numLivros, titulo);//pesquisa o livro para ver se ele existe e sua disponibilidade
    if (livro != NULL && livro->disponivel) {
        livro->disponivel = 0;
        return 1; 
    }
    return 0; //sistema de alocação true e false (bollean)
} // Função para emprestar um livro


void listarLivros(Livro *biblioteca, int numLivros) {
    printf("Livros cadastrados:\n");
    for (int i = 0; i < numLivros; i++) {
        printf("Título: %s, Autor: %s, Disponível: %s\n", biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].disponivel ? "Sim" : "Não");
    }//loop que roda biblioteca e que para cada titulo imprime : titulo, autor e disponibilidade
}// Função para listar todos os livros cadastrados


void adicionarLivroUI(Livro **biblioteca, int *numLivros) {
    char titulo[100], autor[100];
    printf("Digite o título do livro: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0'; // Remover o newline

    printf("Digite o autor do livro: ");
    fgets(autor, sizeof(autor), stdin);
    autor[strcspn(autor, "\n")] = '\0'; // Remover o newline

    adicionarLivro(biblioteca, numLivros, titulo, autor);
    printf("Livro adicionado com sucesso!\n");
}// Função para adicionar um livro através da interface do usuário : opicional para deixar o main clean


void emprestarLivroUI(Livro *biblioteca, int numLivros) {
    char titulo[100];
    printf("Digite o título do livro a ser emprestado: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0'; // Remover o newline

    if (emprestarLivro(biblioteca, numLivros, titulo)) {
        printf("Livro emprestado com sucesso!\n");
    } else {
        printf("Falha ao emprestar o livro. Verifique se o título está correto e se o livro está disponível.\n");
    }
}// Função para emprestar um livro através da interface do usuário : opicional para deixar o main clean


void pesquisarLivroUI(Livro *biblioteca, int numLivros) {
    char titulo[100];
    printf("Digite o título do livro a ser pesquisado: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0'; // Remover o newline

    Livro *livro = pesquisarLivro(biblioteca, numLivros, titulo);
    if (livro != NULL) {
        printf("Livro encontrado: %s por %s, Disponível: %s\n", livro->titulo, livro->autor, livro->disponivel ? "Sim" : "Não");
    } else {
        printf("Livro não encontrado.\n");
    }
}// Função para pesquisar um livro através da interface do usuário : opicional para deixar o main clean


#endif // METODO_H
