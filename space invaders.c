#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void start(char tecla){
  printf("S P A C E  I N V A D E R S");
  printf("\n\ndigite x para começar o jogo ");
  scanf("%c",&tecla);
  getchar();
}
int main(void) {
  srand(time(NULL));
  start('x');
  int tam=10;
  char matriz[tam][tam];
  
  for(int i=0;i<tam;i++)
    {
      for(int c=0;c<tam;c++)
        {
          matriz[i][c]='.';
        }
    }
  char nave_l= rand()%10;
  char nave_c= rand()%10;

  if(matriz[nave_l][nave_c]=='.')
  {
    matriz[nave_l][nave_c]='N';
  }
  
  for(int inim=0;inim<5;)
    {
     char inim_l=rand()%10;
     char inim_c=rand()%10;
     if(matriz[inim_l][inim_c]=='.')
     {
       matriz[inim_l][inim_c]='I';
       inim++;
     }
    }
  
    for(int obst=0;obst<5;)
    {
     char obst_l=rand()%10;
     char obst_c=rand()%10;
     if(matriz[obst_l][obst_c]=='.')
     {
       matriz[obst_l][obst_c]='O';
       obst++;
     }
    }

  char tecla='x';
  do{
 //imprimindo mapa
    
    system("clear");
    int balas=10;
    for(int i=0;i<tam;i++)
    {
      for(int c=0; c < tam; c++)
        {
          printf("%c ", matriz[i][c]);
        }
      printf("\n");
    }
    
  printf("\nMovimentação{w,a,s,d}");
  printf("\nbalas:%i", balas);  
  printf("\nDigite uma letra>");
    // movimentação
  char movimento;
  scanf("%c", &movimento);
  getchar();

  
    if(movimento=='w'){
    if(nave_l-1>=0&& matriz[nave_l-1][nave_c]!='O')
    {
      matriz[nave_l-1][nave_c]='N';
      matriz[nave_l][nave_c]='.';

      --nave_l;
    }
    }
       
    if(movimento=='a'){
      if(nave_c-1>=0&& matriz[nave_l][nave_c-1]!='O')
      {
        matriz[nave_l][nave_c-1]='N';
        matriz[nave_l][nave_c]='.';

        --nave_c;
      }
      }

    if(movimento=='s'){
      if(nave_l+1>=0&& matriz[nave_l+1][nave_c]!='O')
      {
       matriz[nave_l+1][nave_c]='N';
       matriz[nave_l][nave_c]='.';

       ++nave_l; 
      }
      }

    if(movimento=='d'){
      if(nave_c+1>=0&& matriz[nave_l][nave_c+1]!='O')
      {
        matriz[nave_l][nave_c+1]='N';
        matriz[nave_l][nave_c]='.';

        ++nave_c;
      }
      }

    for(int inim=0;inim<5;){  
    char inim_l=rand()%10;
    char inim_c=rand()%10;
    
    if(matriz[nave_l][nave_c]==matriz[inim_l][inim_c] && balas >10)
    {
      matriz[nave_l][nave_c]='N';
      matriz[inim_l][inim_c]='.';

      int auxiliar =1;
      
      if(auxiliar ==1){    
      balas--;
      inim--;
      printf("agora vc tem:%i balas", balas);
      }  
      
    }
      inim++;
      balas--;
    }
  
  }while(tecla =='x');  
  
}