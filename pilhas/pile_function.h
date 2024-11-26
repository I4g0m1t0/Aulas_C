void inicializacao (Pilha *monte)
{ 
 monte->inicio = NULL; 
 monte->tamanho = 0;
 return 0;
 } 
/* empilhar (adicionar) um elemento na pilha */ 

int empilhar (Pilha * monte, char *dado)
{ 
  Elemento *novo_elemento; 
  if ((novo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL) 
     return -1; 
  if ((novo_elemento-> dado = (char *) malloc (50 * sizeof (char))) == NULL) 
    return -1; 
  strcpy (novo_elemento->dado, dado); // Copia a palavra para dado 
  novo_elemento->seguinte = monte->inicio;
  monte-> inicio = novo_elemento; 
  monte->tamanho++; 
} 
/* desempilhar (excluir um elemento da pilhe */ 
int desempilhar (Pilha * monte)
{ 
 Elemento *remov_elemento;
 if (tas->tamanho == 0) 
 return -1; 
 remov_elemento = monte->inicio; 
 monte-> inicio = monte->inicio->seguinte; 
 free (remov_elemento->dado); 
 free (remov_elemento); 
 monte->tamanho--; 
 return 0;
 } 
/* exibição da pilha */ 
void exibe (Pilha * monte)
{ 
  Elemento *em curso; 
  int i; em curso = monte->inicio; 
  for(i=0;i<monte->tamanho;++i)
  { 
    printf("\t\t%s\n", em curso->dado); 
	em curso = em curso->seguinte; 
	} 
}

