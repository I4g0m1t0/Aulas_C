#include <stdio.h>  
#include <stdlib.h>  

int main () {  
 int *p, *p1;  
 int i =10;  
 p = &i;  
 p1 = p; //equivale a p1 = &i;  
 printf("%d\n", *p1); //10 
 
 int j =20;  
 p1 = &j;  
 printf("%d\n", *p1); //20 
 *p1 = *p; //equivale a j=i 
 printf("%d\n", *p1); //10 
 return 0;  
}