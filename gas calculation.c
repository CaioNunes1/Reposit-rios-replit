#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int calculo(float Vgas, float VEtanol){
  //preço gasolina * 0,70= max do alcool
  if(Vgas*0.7 < VEtanol)
  {//compensa abastecer com gasolina
   return 0;
  }
  else if(Vgas*0.7 >VEtanol)
  {//compensa abastecer com gasolina
    return 1;
  }
  else
  {//valores são equivalentes
    return 2;
  }
}
int main(void) {
  printf("****CPosto Nunes****");

  float gas;
  float  etanol;

  printf("\nQual o preço da gasolina:");
  scanf("%f", &gas);
  printf("Qual o preço do Etanol:");
  scanf("%f", &etanol);

  int resultado=calculo(gas, etanol);

  if(resultado==0)
  {
    printf("Compensa abastecer com gasolina");
  }
  if(resultado==1)
  {
    printf("Compensa abastecer com etanol");
  }
  
  else if(resultado==2)
  {
    printf("Compensa abastecer com ambos");
  }
}