#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	int data;
	struct node* next;
};

struct node* initialize(){
	return NULL;
}

struct node* push(struct node* top, int value){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	if (newNode == NULL){
		printf("Falha na alocação de memória.\n");
		printf("Não é possível adicionar mais elementos.\n");
		return top;
	}
	newNode->data = value;
	newNode->next = top;
	return newNode;
}

int size(struct node* top){
	int count = 0;
	struct node* temp = top;
	while(temp !=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

int main(){
	system("CHCP 65001 > null");
	struct node* stack = initialize();
	int value, choice;
	
	while(1){
		printf("Menu: \n");
		printf("1. Empilhar(Push) \n");
		printf("2. Desemplihar(Pop)\n");
		printf("3. Ver topo(Peek)\n");
		printf("4. Ver tamanho da Pilha\n");
		printf("5. Sair\n");
		printf("Escolha uma opcao: \n");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				printf("Digite um valor a ser empilhado: ");
				scanf("%d", &value);
				stack = push(stack, value);
				break;
			case 4:
				printf("Tamanho da pilha: %d\n", size(stack));
				break;
		}
	}
}