#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void inicio(char tecla,char tecla2)
{
  do{
  printf(" G A M E  O F  T H R O N E S");
  printf("\nAperte 'x' começar o jogo");
  printf("\n->");  
  scanf("%c",&tecla);
  getchar();
    
  }while(tecla!='x');
  system("clear");
  
  do{
    printf("\nVocê controla-rá Jon Snow('J'), que está em guerra contra o Rei da noite,para derrota-lo Jon precisará da ajuda de Cersei('C') e convence-lo de ir a batalha, Boa Sorte!!");
    printf("\n\nO símbolo 'V' são vidas no mapa, recupera 1 ponto de vida de Jon.");
    printf("\n\nO símbolo 'V' são inimigos no mapa, retiram um ponto de vida de Jon, e 'O' são obstaculos no caminho.");
    printf("\n\ndigite 'x' para continuar:");
    printf("\n->");
    scanf("%c",&tecla2);
    getchar();
  }while(tecla2!='x');
  system("clear");
}
int main(void) {
  srand(time(NULL));
  int tam=20;
  char mapa[tam][tam];
  int jon_vida=100;
  int batt_enemy,aumt_vida;
  int inim,obst,batt_rei_noite,enc_rei_noite=0,achar_cersei=1,achar_rei_noite=0;
  int game_over=0,Continue,vida,enc_cersei=0,tentativas=5,cersei_vida=100;
  int rei_noite_vida=100;
  int acc_cersei=0,vez_tent=rand()%10;
  int acc_cersei2=0;
  char tec_rei,att_rei;
  int cont_bat2=0,turno2=0,vitoria=0;
  char tecla_inicio,tecla_inicio2;
  //criação do mapa
  for(int i=0;i<tam;i++)
    {
      for(int c=0;c<tam;c++)
        {
          mapa[i][c]='.';
        }
    }
  //cirando Jon no mapa
  char jon_l=rand()%20;
  char jon_c=rand()%20;
  
  //imprimindo jon no mapa
  if(mapa[jon_l][jon_c]=='.')
  {
    mapa[jon_l][jon_c]='J';
  }

  //colocando cersei no mapa
  char cersei_l=rand()%20;
  char cersei_c=rand()%20;

  //imprimindo cersei no mapa
  if(mapa[cersei_l][cersei_c]=='.')
  {
    mapa[cersei_l][cersei_c]='C';
  }
  //criando rei da noite no mapa
  char rei_noite_l=rand()%20;
  char rei_noite_c=rand()%20;
  
  //imprimindo rei da noite
  if(mapa[rei_noite_l][rei_noite_c]=='.')
  {
    mapa[rei_noite_l][rei_noite_c]='R';
  }
  
  //colocando e imprimindo inimigos
  for(inim=0;inim<=20;)
    {
      char inim_l=rand()%20;
      char inim_c=rand()%20;
      if(mapa[inim_l][inim_c]=='.')
      {
        mapa[inim_l][inim_c]='E';
      }
      inim++;
    }

  //colocando e imprimindo obstáculos
  for(obst=0;obst<=10;)
    {
      char obst_l=rand()%20;
      char obst_c=rand()%20;
      if(mapa[obst_l][obst_c]=='.')
      {
        mapa[obst_l][obst_c]='O';
      }
      obst++;
    }
   //colocando e imprimindo vidas
  for(vida=0;vida<=5;)
    {
      char vida_l=rand()%20;
      char vida_c=rand()%20;
      if(mapa[vida_l][vida_c]=='.')
      {
        mapa[vida_l][vida_c]='V';
      }
      vida++;
    }
  inicio(tecla_inicio,tecla_inicio2);
do{//imprimindo mapa
  system("clear");
  for(int i=0;i<tam;i++)
    {
      for(int c=0;c<tam;c++)
        {
          printf(" %c",mapa[i][c]);
        }
      printf("\n");
    }
  //movimentação
  char movimento;
  
  if(achar_cersei==1){
  printf("\nVocê deve encontrar Cersei('C') no mapa.");
    }
  
  if(acc_cersei==1)
  {
    printf("\nParabens!! Cersei aceitou ir para a guerra com você, sua negociação foi de :%i por cento.",vez_tent*10);
    printf(" \nTentativas:%i",tentativas);
    acc_cersei=0;
    achar_rei_noite=1;
  }
  
  if(acc_cersei2==1)
  {
    printf("\nParabens!! Você derrotou Cersei e agora ele irá para a guerra com você. ");
  }
  
  if(achar_rei_noite==1)
  {
    printf("\nAgora você deve encontrar o rei da noite('R')");
  }
  if(vitoria==1)
  {
    printf("Parabéns!! Você venceu o Rei da Noite, vida restante de Jon:%i",jon_vida);
  }
  
  printf("\nw,a,s,d para movimentar:");
  printf("\nvida:%i",jon_vida);
  printf("\n->");
  scanf("%c",&movimento);
  getchar();
  

  if(movimento=='w')
  {
    if(jon_l-1>=0 && mapa[jon_l-1][jon_c] != 'O')
    { 
      //caso Jon se encontre com o inimigo
      if(mapa[jon_l-1][jon_c]=='E')
      {
        batt_enemy=1;
      }
      //caso Jon se encontre com uma vida
      if(mapa[jon_l-1][jon_c]=='V')
      {
        aumt_vida=1;
      }
      //caso Jon se encontre com cersei
      if(mapa[jon_l-1][jon_c]=='C')
      {
        enc_cersei=1;
      }
      if(batt_rei_noite==1){
      //caso encontre o rei da noite
      if(mapa[jon_l-1][jon_c]=='R')
      {
        enc_rei_noite=1;
      }
      }
     mapa[jon_l-1][jon_c]='J';
     mapa[jon_l][jon_c]='.';
    }
    jon_l--;
  }

  if(movimento=='a')
  {
   if(jon_c-1 >= 0 && mapa[jon_l][jon_c-1]!='O' )
   {
     //caso Jon se encontre com o inimigo
     if(mapa[jon_l][jon_c-1]=='E')
     {
       batt_enemy=1;
     }//caso Jon se encontre com uma vida
     if(mapa[jon_l][jon_c-1]=='V')
     {
       aumt_vida=1;
     }//caso Jon se encontre com cersei
     if(mapa[jon_l][jon_c-1]=='C')
     {
       enc_cersei=1;
     }
     
     if(batt_rei_noite==1){
      //caso encontre o rei da noite
     if(mapa[jon_l][jon_c-1]=='R')
      {
        enc_rei_noite=1;
      }
      }
    mapa[jon_l][jon_c-1]='J';
    mapa[jon_l][jon_c]='.';
   }
    jon_c--;
  }

  if(movimento=='s')
  {
   if(jon_l+1 <= 19 && mapa[jon_l+1][jon_c]!='O')
   {
     //caso Jon se encontre com o inimigo
     if(mapa[jon_l+1][jon_c]=='E')
     {  
      batt_enemy=1;
     }
     //caso Jon se encontre com uma vida
     if(mapa[jon_l+1][jon_c]=='V')
     {  
      aumt_vida=1;
     }
     //caso Jon se encontre com cersei
     if(mapa[jon_l+1][jon_c]=='C')
     {  
      enc_cersei=1;
     }
     
     if(batt_rei_noite==1){
     if(mapa[jon_l+1][jon_c]=='R')
      {
        enc_rei_noite=1;
      }
      }
     
    mapa[jon_l+1][jon_c]='J';
    mapa[jon_l][jon_c]='.';
   }
    jon_l++;
  }

  if(movimento=='d')
  {
   if(jon_c+1 <= 19 && mapa[jon_l][jon_c+1]!='O')
   {
     //caso Jon se encontre com o inimigo
     if(mapa[jon_l][jon_c+1]=='E')
     {
       batt_enemy=1;
     }
     //caso Jon se encontre com uma vida
     if(mapa[jon_l][jon_c+1]=='V')
     {
       aumt_vida=1;
     }
     //caso Jon se encontre com cersei
     if(mapa[jon_l][jon_c+1]=='C')
     {
       enc_cersei=1;
     }
     if(batt_rei_noite==1){
     //caso se encontre com o rei da morte
     if(mapa[jon_l][jon_c+1]=='R')
      {
        enc_rei_noite=1;
      }
      }
     
    mapa[jon_l][jon_c+1]='J';
    mapa[jon_l][jon_c]='.';
   }
    jon_c++;
  }
//encontra inimigo ,diminui 1 vida
  if(batt_enemy==1)
  {
   if(jon_vida>0)
   {
     jon_vida--;
   } else{
    
      game_over=1;
      
    }
    inim--;
    batt_enemy=0;      
  }
  //encontra vida ,aumenta 1 vida
  if(aumt_vida==1)
  {
    if(jon_vida>0)
      {
      jon_vida++;
      }
    vida--;
    aumt_vida=0;
  }
  char tec_cersei;
  int concluiu;
  int cont;
  
  //se encontra com cersei
  if(enc_cersei==1)
  {
    do{
      int vez_tent2=rand()%10;
      vez_tent=vez_tent2;
      system("clear");
      printf("\nVocê tem %i tentativas para convencer cersei de ir para a guerra, digite 'x' para tentar: ",tentativas);
      scanf("%c",&tec_cersei);
       getchar();
      if(tec_cersei=='x')
       {
         if(vez_tent>=6)
         { 
           acc_cersei=1;
           concluiu=1;
           tentativas--;
           jon_vida+=100;
           achar_cersei=0;
         }
         else
         {
           printf("\nSua negociação não foi o suficiente :%i por cento.",vez_tent*10);
           tentativas--;
           printf(" Tentativas:%i",tentativas);
           concluiu=0;
         }
       }
    }while(tentativas!=0 && concluiu!=1 );
    
    enc_cersei=0;
    int turno=0;
    int cont_bat=0;
    if(tentativas==0)
    {
      system("clear");
      printf("\n\nVocê entrou em guerra contra Cersei!!");
      do
      {
        int ataque_jon=rand()%100;
        int ataque_cersei=rand()%100;
        printf("\nJon:vida %i x Cersei:vida %i",jon_vida,cersei_vida);
        printf("\ndigite 'x' para atacar.");
        scanf("%c",&tec_cersei);
        getchar();

        if(tec_cersei=='x')
        {
          system("clear");
          if(turno%2==0)
          {
            if(ataque_jon>=50)
            {
            cersei_vida-=10;
            printf("Jon atacou!! Vida de Cersei:%i",cersei_vida);
            }
            else
            {
              cersei_vida-=0;
              printf("Jon errou o ataque!! Vida de Cersei:%i",cersei_vida);
            }
            
          }
          if(turno%2==1)
          {
            if(ataque_cersei>=50)
            {
            jon_vida-=10;
            printf("Cersei atacou!! Vida de Jon:%i",jon_vida);
            }
            else
            {
            jon_vida-=0;
            printf("Cersei errou o ataque!! Vida de Jon:%i",jon_vida);
            }
    
          }
          turno++;
        }
        if(cersei_vida<1)
        {
          cont_bat=1;
        }
        
        if(jon_vida<1)
        {
          cont_bat=1;
        }
      }while(cont_bat!=1);
      
      
      if(cersei_vida<1)
        {
          jon_vida+=200;
          batt_rei_noite=1;
          achar_cersei=0;
          achar_rei_noite=1;
          acc_cersei2=1;
        }
      if(jon_vida<1)
      {
        game_over=1;
      }
        
    }
  }

  if(enc_rei_noite==1)
  {
      system("clear");
      printf("Você encontrou o rei da noite!! E agora vão disputar uma batalha");
      printf("\nAperte 'x' para começar:");
      printf("\n->");
      scanf("%c",&tec_rei);
      getchar();

      if(tec_rei=='x')
      {
        do{
          system("clear");
          int ataque_jon=rand()%100;
          int ataque_rei=rand()%100;

          printf("\nVida Jon: %i x Vida Rei da Noite: %i",jon_vida,rei_noite_vida);
          printf("\nAperte 'x' para atacar");
          printf("\n->");
          scanf("%c",&att_rei);
          getchar();

          if(att_rei=='x')
          {
            system("clear");
            if(turno2 %2==0)
            {
              if(ataque_jon>=50)
              {
                rei_noite_vida-=10;
                printf("\nJon atacou!! Vida Rei da Noite:%i",rei_noite_vida);
              }
              else
              {
                rei_noite_vida-=0;
                printf("\nJon errou o ataque!! Vida rei da Noite:%i",rei_noite_vida);
              }
            }
            if(turno2 %2==1)
            {
              if(ataque_rei>=50)
              {
                jon_vida-=5;
                rei_noite_vida+=5;
                printf("\nRei da noite atacou!! Vida de Jon:%i",jon_vida);
              }
              else
              {
                jon_vida-=0;
                printf("\nRei da noite errou o ataque!! Vida de Jon:%i",jon_vida);
              }
            }
            turno2++;
          }
          if(rei_noite_vida<1)
          {
            cont_bat2=1;
          }
          if(jon_vida<1)
          {
            cont_bat2=1;
          }
          
        }while(cont_bat2!=1);
      }
      if(jon_vida<1)
      {
        game_over=1;
        printf("Vida de Jon:%i",jon_vida);
      }
      if(rei_noite_vida<1)
      {
        printf("\nParabéns!! Você venceu o Rei da Noite, vida restante de Jon:%i ",jon_vida);
        vitoria=1;
        game_over=1;
      }
      
  }
  }while(game_over!=1);

  if(jon_vida<1)
  {
    printf("\nGame_over!! Você perdeu!!");
  }
  if(rei_noite_vida<1)
  {
    printf("\nGame_over!! Você Ganhou!!");
  }
  
}