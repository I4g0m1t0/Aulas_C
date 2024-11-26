typedef struct ElementoLista { 
  char *dado; 
  struct ElementoLista *seguinte;
 } Elemento;
 
 typedef struct ListaDetectada { 
 Elemento *inicio; 
 int tamanho; 
 } Pilha; 

 
 // inicializa��o  
 void inicializacao (Pilha *monte); 
  //EMPILHAR ou Push 
 int empilhar (Pilha *monte, char *dado); 
 // DESEMPILHAR ou Pop 
 int desempilhar (Pilha *monte); 
// Exibi��o do elemento no topo da pilha (LastInFirstOut)  
 #define pilha_dado(monte) monte->in�cio->dado 
 // Exibe a pilha  
 void exibe (Pilha *monte);
