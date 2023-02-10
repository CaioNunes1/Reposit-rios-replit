#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char tecla;
  float vm=0,t=0,s=0;
  int op;
  do{
    printf("\n 1-Velocidade média \n 2-Espaço \n ");
    scanf("%i",&op);
    getchar();

    if(op==1)
    {
      printf("Digite o espaço: ");
      scanf("%f",&s);
      getchar();
      
      printf("Digite o tempo: ");
      scanf("%f",&t);
      getchar();

      printf("A sua velocidade media é %f",s/t);
    }

    if(op==2)
    {
      printf("Digite a velocidade média:");
      scanf("%f",&vm);
      getchar();

      printf("Digite o tempo:");
      scanf("%f",&t);
      getchar();
      
      printf("O espaco é de %f metros",vm*t);
    }
    
    printf("\nDeseja continuar?");
    scanf("%c",&tecla);
    system("clear");
  }while(tecla!='n');
}