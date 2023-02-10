#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  char nome[50];
  int notas[4];
  int ativo;
  int status; 
}Aluno;
    
void remover(int tam,Aluno a[tam],int num){
  system("clear");
  char tecla;
  int i;
  int escolha=0;
  do{
    
    for(i=1;i<=tam;i++)
      {
        printf("\n%i-Aluno:%s",i,a[i].nome);
      }
  printf("\nQual aluno você deseja remover?");
  scanf("%i",&escolha);
  getchar();

  for(int i=1;i<=tam;i++)
    {
    if(escolha==i)
     {
     strcpy(a[i].nome,"Nome removido");
     printf("%s",a[i].nome); 
     }
    }
    
  printf("\ndeseja continuar?(s/n)");
  scanf("%c",&tecla);  
  getchar();
  system("clear");
  }while(tecla!='n');
  
}
void aprovados(int tam,Aluno a[tam],int num,int i,int aprovado[tam],int aprovado2){
  char tecla;
  system("clear");
  do{
    for(i=1;i<=tam;)
    {
     if(aprovado[i]==0){
     printf("Aluno: %s-Reprovado %i %i\n",a[i].nome,aprovado[i],aprovado2);
       }
      else
     {
       printf("Aluno:%s-Aprovado %i %i\n",a[i].nome,aprovado[i],aprovado2);
     }
      i++;
    }
    printf("\nDeseja continuar(s/n)");
    scanf("%c",&tecla);
    getchar();
   
  }while(tecla!='n');
  system("clear");
    
}
void pesquisar(int tam,Aluno a[tam],int num,int i){
  char tecla;
  char nome[30];
  int comp;
  do{
  system("clear");
  printf("digite o nome do aluno:");
  scanf("%s",nome);
  getchar();
  

//for(i=1;i<=tam;i++)
  {
    comp=strcmp(nome,a[i].nome);
    if(comp==0)
    {
      printf("\nAluno:%s",a[i].nome);
      printf("\nNota do 1 bimestre:%i",a[i].notas[0]);
      printf("\nNota do 2 bimestre:%i",a[i].notas[1]);
      printf("\nNota do 3 bimestre:%i",a[i].notas[2]);
      printf("\nNota do 4 bimestre:%i",a[i].notas[3]);
    }
    if(comp!=0)
    {
      printf("Nome removido ou não existente!");
    }
  }

  printf("\ndeseja continuar(s/n)?");
  scanf("%c",&tecla);
  getchar();
  system("clear");
  }while(tecla!='n');  
}
void listar(int tam,Aluno a[tam],int i){
  char tecla;
  do{
  system("clear");
  
  printf("LISTA DE ALUNOS\n");
  for(i=1; i <=tam;i++)
    {
     printf("\nNome:%s",a[i].nome);
     printf("\nNota do 1 bimestre:%i",a[i].notas[0]);
     printf("\nNota do 2 bimestre:%i",a[i].notas[1]);
     printf("\nNota do 3 bimestre:%i",a[i].notas[2]);
     printf("\nNota do 4 bimestre:%i",a[i].notas[3]);
     printf("\n"); 
    }

    printf("deseja continuar?\n");
    scanf("%c",&tecla);
    getchar();
    }while(tecla!='n');
}
void menu(){
  int num_alunos,tam;
  Aluno a[tam];
  int i,aprovado[tam];
  int soma;
  system("clear");
  char tecla;
  int op;
  int num=1;
  int aprovado2;
  if(num==1){
  do{
  printf("\n1-Cadastrar aluno \n2-Remover aluno \n3-Alunos aprovados \n4-Pesquisar aluno \n5-lista alunos \n0-Sair\n");
  scanf("%i", &op);
    getchar();
    
    if(op==1){
      
    do{
      system("clear");
      printf("Digite quantos alunos irá cadastrar:");
      scanf("%i",&num_alunos);
      getchar();
      system("clear");
      tam=num_alunos;
      aprovado[tam]=aprovado[num_alunos];
     
      
      for(i=1;i<=tam;){
      printf("Digite o nome do aluno:");
  scanf("%s",a[i].nome);
  getchar();
    
  printf("Digite a nota do 1 bimestre do aluno %s:",a[i].nome);
  scanf("%i",&a[i].notas[0]);
  getchar();
    
  printf("Digite a nota do 2 bimestre do aluno %s:",a[i].nome);
  scanf("%i",&a[i].notas[1]);
  getchar();
    
  printf("Digite a nota do 3 bimestre do aluno %s:",a[i].nome);
  scanf("%i",&a[i].notas[2]);
  getchar();
    
  printf("Digite a nota do 4 bimestre do aluno %s:",a[i].nome);
  scanf("%i",&a[i].notas[3]);  
  getchar();

  soma=a[i].notas[0]+a[i].notas[1]+a[i].notas[2]+ a[i].notas[3]; 
  printf("A nota total do aluno %s é %i\n",a[i].nome,soma);

  if(soma<60)
    {
    aprovado[i]=0;
    aprovado2=0;
    }
  else if(soma>=60)
  {
    aprovado[i]=1;
    aprovado2=1;
  }
  i++;      
        
  }

  printf("\nDeseja continuar?");
  scanf("%c",&tecla);
  getchar();    
  system("clear");
      
  }while(tecla!='n');
  }
    switch(op)
      {
        case 2:remover(tam,a,num);
        break;
        case 3:aprovados(tam,a,num,i,&aprovado[tam],aprovado2);
        break;
        case 4:pesquisar(tam,a,num,i);
        break;
        case 5:listar(tam,a,i);
      }
    }while(op!=0);
}
}
int main(void) {

  menu();
}