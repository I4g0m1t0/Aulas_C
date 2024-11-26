#include <stdio.h>  
#include <stdlib.h>  

int main () {  
 int *p;  
 int i=10, j =20, k=30;  
 p = &j;  
 printf("Valor de *p = %d\n", *p);  
 printf("Endereco de p = %d\n", p);  
 p++;  

 printf("Valor de *p = %d\n", *p);  
 printf("Endereco de p = %d\n", p);  

 //printf("Endereco de p =%d\n", p++);  
 printf("Endereco de p = %d\n", ++p);  

 printf("Endereco de i = %d\n", &i);  
 printf("Endereco de j = %d\n", &j);  
 printf("Endereco de k = %d\n", &k);  

 return 0;  
}