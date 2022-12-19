#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void tabuleiro(char casas2[3][3]){

  printf("\n %c | %c | %c",casas2[0][0],casas2[0][1],casas2[0][2]);
  printf("\n %c | %c | %c",casas2[1][0],casas2[1][1],casas2[1][2]);
  printf("\n %c | %c | %c",casas2[2][0],casas2[2][1],casas2[2][2]);
}
int main(void) {

  char casas[3][3];
  //aux
  char op;
  char tecla;
  int cont_jogadas,l,c,vez=0;
  do{
    cont_jogadas=1;
    for(int i=0;i<3;i++)
      {
        for(int c=0;c<3;c++)
          {
            casas[i][c]=' ';
          }
      }
    do{
      printf("rodada:%i\n", cont_jogadas);
      tabuleiro(casas);
      if(vez%2==0)
      {
        printf("\n\nvez do jogador 1(x)\n");
      }
      else
      {
        printf("\n\nvez do jogador 2(o)\n");
      }
      printf("\ndigite a linha:");
      scanf("%i",&l);
      getchar();
       
      printf("\ndigite a coluna:");
      scanf("%i",&c);
      getchar();

      
      if(l<1 || c<1 || l>3 || c>3)
      {
       l=0;
       c=0;
        if(l==0 || c==0);
        {
          printf("você digitou uma posição inválida!");
        }
      }
      else if(casas[l-1][c-1]!= ' ')//se estiver ocupado com x ou o
      {
       l=0;
       c=0;
      }
      else
      {
        if(vez%2==0)
        {
          casas[l-1][c-1]='x';//l-1 e c-1 porque o vetor começa no zero, ent se digitar l=1 ou c=1, na verdade ele vai ser guardado no vetor 0, ou seja l e c guadam oq foi digitado e guarda no numero original do vetor
        }
        else
        {
          casas[l-1][c-1]='o';
        }
        vez++;
        cont_jogadas++;
      }
      //parte ganhador 'x'
      if(casas[0][0]=='x' &&casas[0][1]=='x' && casas[0][2]=='x')
      {
        printf("parabens você ganhou a rodada jogador(x)");
        cont_jogadas=10; 
      }
      
      if(casas[1][0]=='x' &&casas[1][1]=='x' && casas[1][2]=='x')
      {
        printf("parabens você ganhou a rodada jogador(x)");
        cont_jogadas=10; 
      }

      if(casas[2][0]=='x' &&casas[2][1]=='x' && casas[2][2]=='x')
      {
        printf("parabens você ganhou a rodada jogador(x)");
        cont_jogadas=10; 
      }
      
      if(casas[0][0]=='x' &&casas[1][0]=='x' && casas[2][0]=='x')
      {
        printf("parabens você ganhou a rodada jogador(x)");
        cont_jogadas=10; 
      }

      if(casas[1][0]=='x' &&casas[1][1]=='x' && casas[1][2]=='x')
      {
        printf("parabens você ganhou a rodada jogador(x)");
        cont_jogadas=10; 
      }

      if(casas[2][0]=='x' &&casas[2][1]=='x' && casas[2][2]=='x')
      {
        printf("parabens você ganhou a rodada jogador(x)");
        cont_jogadas=10; 
      }

      if(casas[0][0]=='x' &&casas[1][1]=='x' && casas[2][2]=='x')
      {
        printf("parabens você ganhou a rodada jogador(x)");
        cont_jogadas=10; 
      }

      if(casas[0][2]=='x' &&casas[1][1]=='x' && casas[2][0]=='x')
      {
        printf("parabens você ganhou a rodada jogador(x)");
        cont_jogadas=10; 
      }

      

      //parte ganhador 'o'
      if(casas[0][0]=='o' &&casas[0][1]=='o' && casas[0][2]=='o')
      {
        printf("parabens você ganhou a rodada jogador(o)!");
        cont_jogadas=10; 
      }
      
      if(casas[1][0]=='o' &&casas[1][1]=='o' && casas[1][2]=='o')
      {
        printf("parabens você ganhou a rodada jogador(o)!");
        cont_jogadas=10; 
      }

      if(casas[2][0]=='o' &&casas[2][1]=='o' && casas[2][2]=='o')
      {
        printf("parabens você ganhou a rodada jogador(o)!");
        cont_jogadas=10; 
      }

      if(casas[0][0]=='o' &&casas[1][0]=='o' && casas[2][0]=='o')
      {
        printf("parabens você ganhou a rodada jogador(o)!");
        cont_jogadas=10; 
      }

      if(casas[1][0]=='o' &&casas[1][1]=='o' && casas[1][2]=='o')
      {
        printf("parabens você ganhou a rodada jogador(o)!");
        cont_jogadas=10; 
      }

      if(casas[2][0]=='o' &&casas[2][1]=='o' && casas[2][2]=='o')
      {
        printf("parabens você ganhou a rodada jogador(o)!");
        cont_jogadas=10; 
      }

      if(casas[0][0]=='o' &&casas[1][1]=='o' && casas[2][2]=='o')
      {
        printf("parabens você ganhou a rodada jogador(o)!");
        cont_jogadas=10; 
      }

      if(casas[0][2]=='o' &&casas[1][1]=='o' && casas[2][0]=='o')
      {
        printf("parabens você ganhou a rodada jogador(o)!");
        cont_jogadas=10; 
      }
    
      system("clear");


    }while(cont_jogadas<=9);
    
    tabuleiro(casas);
    if(cont_jogadas ==10)
    {
      printf("houve um empate");
    }
    
    printf("\ndeseja continuar?(s/n)");
    scanf("%c",&tecla);

    system("clear");
  }while(tecla=='s');
}