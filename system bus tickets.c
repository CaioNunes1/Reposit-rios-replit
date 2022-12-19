#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  float credito;
  printf("digite quanto de crédito você tem:\n");
  scanf("%f", &credito);
  system("clear");
  
  int dias= credito/4.10;
  int cont;// 22 dias uteis
  float mes=22;
  
  printf("com %f de crédito você consegue pegar o ônibus por\n %i dias ", credito, dias);
  if(dias>=mes)
  {
    mes= dias/mes;
    printf("\n\n%i dias é equivalente a %f mês de transporte",dias,mes);
  }
  
}