#include <stdio.h>>
#include <strings.h>
#include <stdlib.h>

int main (){
	int *ptr_a;
	int *ptr_b;
	
	ptr_a = malloc(sizeof(int));
	ptr_b = calloc(3, sizeof(int));
	
	if (ptr_a == NULL){
		printf("Memória insuficiente A");
		exit(1);
	}
	
	if (ptr_b == NULL){
		printf("Memória insuficiente B");
		exit(1);
	}
	
	printf("Endereço de ptr_a: %d\n", ptr_a);
	printf("Conteúdo do endereço de ptr_a: %d\n", *ptr_a);	
	*ptr_a = 45;
	printf("Endereço de ptr_a: %d\n", ptr_a);
	printf("Depois conteúdo do endereço de ptr_a: %d\n", *ptr_a);
	free(ptr_a);
	
	ptr_b[0] = 5;	
	ptr_b[1] = 10;	
	ptr_b[2] = 15;	
	
	int i;
	for (i=0; i<3; i++){
		printf("B[%d]: %d\n", i, ptr_b[i]);
	}
}