#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include "pilha.h"
#include "pile_function.h" 
main () 
{ 
 Pilha *monte;
 char *nome;
 if ((monte = (Pilha *) malloc (sizeof (Pile))) == NULL) 
    return -1; 
 if ((nome = (char *) malloc (50 * sizeof (char))) == NULL) 
    return -1; 
	
 inicializacao (monte);
 printf ("Entre uma palavra:");
 scanf ("%s", nome);
 empilhar (monte, nome);
 printf ("A pilha (%de elementos): \n",monte->tamanho);
 printf("\n********** Topo da PILHA **********\n"); 
 exibe(monte); 
 printf("__________ Rodape da PILHA __________\n\n");
 printf ("Entre uma palavra:"); 
 scanf ("%s", nome); 
 empilhar (monte, nome); 
 printf ("A pilha (%de elementos): \n",monte->tamanho);
 printf("\n********** Topo da PILHA **********\n");
 exibe(monte); 
 printf("__________ Rodape da PILHA__________\n\n");
 printf ("Entre uma palavra:");
 scanf ("%s", nome); 
 empiler (monte, nome); 
 printf ("A pilha (%de elementos): \n",monte->tamanho); 
 printf("\n********** Topo da PILHA **********\n"); 
 exibe(monte); 
 printf("__________ Rodape da PILHA __________\n\n"); 
 //printf ("\n O ultimo entrado (LastInFirstOut) [ %s ] sera excluido", pilha_dado(monte)); 
 printf ("\n O ultimo entrado sera excluido\n"); 
 desempilhar (monte); /* remoção do último elemento entrado */ 
 printf ("A pilha (%d elementos): \n",monte->tamanho); 
 printf("\n********** Topo da PILHA **********\n"); 
 exibe(monte); printf("__________ Rodape da PILHA __________\n\n"); 
 return 0; 
 }

// FUNÇÕES






