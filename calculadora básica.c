#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void exerciciocalculadora(){
  char tecla='s';
  do{
  float x,y;
  int op;
   
  printf("Digite um numero para sua conta:");
  scanf("%f",&x);
  getchar();
    
  printf("\ndigite o outro numero:");
  scanf("%f",&y);
  getchar();

  printf("\nDigite o tipo de operação que deseja fazer\n1 = +\n2 = - \n3 = * \n4 = /\n:");
  scanf("%i",&op);
  getchar();
    
  system("clear");  
  switch(op)
  {
    case 1:printf("o resultado de %f + %f é: %f",x,y,x+y);
    break;
    case 2: printf("o resultado de %f - %f é: %f",x,y,x-y);
    break;
    case 3: printf("o resultado de %f * %f é: %f",x,y,x*y);
    break;
    case 4: printf("o resultado de %f / %f é: %f",x,y,x/y);
    break;
  }

  printf("\nDeseja continuar?");
  scanf("%c",&tecla);
  system("clear");  
    
  }while(tecla!='n');  
}
int main(void) {//criando calculadora
  exerciciocalculadora();
}