#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int main (){
	int *p = (int *) malloc(5*sizeof(int));
	
	if (p == NULL){
		printf("Memória insuficiente");
		exit(1);
	}
	
	int i;
	for(i=0; i<5; i++){
		p[i] = i+1;
	}
	
	for(i=0; i<5; i++){
		printf("%d\n", p[i]);
	}
	
	p = realloc(p, 6*sizeof(int));
	
	p[5] = 10;
	
	for(i=0; i<6; i++){
		printf("%d\n", p[i]);
	}
}