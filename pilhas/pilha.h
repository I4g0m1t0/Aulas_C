typedef struct ElementoLista { 
  char *dado; 
  struct ElementoLista *seguinte;
 } Elemento;
 
 typedef struct ListaDetectada { 
 Elemento *inicio; 
 int tamanho; 
 } Pilha; 

 
 // inicialização  
 void inicializacao (Pilha *monte); 
  //EMPILHAR ou Push 
 int empilhar (Pilha *monte, char *dado); 
 // DESEMPILHAR ou Pop 
 int desempilhar (Pilha *monte); 
// Exibição do elemento no topo da pilha (LastInFirstOut)  
 #define pilha_dado(monte) monte->início->dado 
 // Exibe a pilha  
 void exibe (Pilha *monte);
