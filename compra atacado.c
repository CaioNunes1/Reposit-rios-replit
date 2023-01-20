#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char tecla;
  do{
  int prod,quant,val_prod;  
  float total,unid;  
  printf("Digite o número do produto que deseja comprar:\n1-Tênis\n2-Bolsa\n3-Camisa\n");
  scanf("%i",&prod);
  getchar();  
  printf("digite a quantidade que deseja comprar :");
  scanf("%i",&quant);
  getchar();  

  system("clear");  
  if(prod==1)
  { 
   total=quant*80; 
  }

  else if(prod==2)
  {
    total=quant*150;
  }

  else if(prod==3)
  {
    total=quant*50;
  }  

  printf("\nO custo total do produto é:%0.2f",total);
  if(quant<10)
  {
    printf("\nO produto não tem desconto");
  }
  else if(quant>=10)
  {
    total= total*0.9;
    printf("\n\nA quantidade de produto é %i, o desconto será de 10 por cento\ntotal:%0.2f",quant,total);
  }
  else if(quant >=20)
  {
    total=total*0.8;
    printf("\n\nA quantidade de produto é %i, o desconto será de 20 por cento\ntotal:%0.2f",quant,total);
  }

  unid=total/quant;
  printf("\n\nO preço unitário por produto será de %0.2f:",unid);

  printf("\nDigite por quanto você irá vender o produto:");
  scanf("%i",&val_prod);
  getchar();

  if(val_prod==unid)
  {
    printf("\nSem lucro!!");
  }
  else if(val_prod>=unid)
  {
    val_prod-=unid;
    printf("\nO seu lucro é de :%0.2i",val_prod);
  }
  else
  {
    val_prod-=unid;
    printf("\nO seu prejuízo é de :%0.2i",val_prod);
  }
    
  printf("\ndeseja continuar?");
  scanf("%c",&tecla);
  system("clear");  
  }while(tecla!='n');
}