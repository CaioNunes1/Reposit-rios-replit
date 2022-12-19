#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  
  char palavra[20]="terra";
  //printf("digite uma palavra para começar o jogo da forca:");
  //scanf("%s", palavra);
  //system("clear");

  int chances=10;
  int n_caracteres=strlen(palavra);//recebe o tamanho de espaços da palavra, para nao imprimir lixo
  
  char acertadas[n_caracteres];// vetor com a quantidade de letras certa
  int letras_acertadas;
  
  int acertou=0;
  
  do{  
  for(int linha=0;linha<n_caracteres;linha++)
    {
      acertadas[linha]='_';
    }

    
    printf("\nDigite uma letra:");
    printf("\nVocê tem %i chances\n", chances);

    
//imprimindo linha das letras
  for(int linha=0;linha<n_caracteres;linha++)
    {
      printf("%c ",acertadas[linha]);
    }

    
    //aauxiliares
    
    char letra;
    scanf("%c",&letra);
    getchar();

    for(int linha=0;linha< n_caracteres;linha++)
      {
        if(letra==palavra[linha])
        {
          acertadas[linha]=letra;
          acertou=1;
          
        }
        
      }
        if(acertou==0)
        {
          printf("você errou uma letra ");
          chances--;
          printf("você tem %i chances",chances);
        }
        else
        {
          printf("PARABENS!!você acertou a letra %c",letra);
          letras_acertadas++;
        }  

    
      }while(letras_acertadas<n_caracteres && chances>0);
}