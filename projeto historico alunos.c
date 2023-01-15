#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  char nome[50];
  float notas[4];
  int ativo;
  int status; 
}Aluno;
void cadastrar(int tam,Aluno a[tam],int *i){
  system("clear");
  char nome[50];
  float notas[4];
  char tecla;
  do{
  printf("digite o nome do aluno:");
  scanf("%s",a[*i].nome);
  getchar();
    
  printf("Digite a nota do 1 bimestre do aluno %s:",a[*i].nome);
  scanf("%f",&a[*i].notas[0]);
  getchar();
    
  printf("Digite a nota do 2 bimestre do aluno %s:",a[*i].nome);
  scanf("%f",&a[*i].notas[1]);
  getchar();
    
  printf("Digite a nota do 3 bimestre do aluno %s:",a[*i].nome);
  scanf("%f",&a[*i].notas[2]);
  getchar();
    
  printf("Digite a nota do 4 bimestre do aluno %s:",a[*i].nome);
  scanf("%f",&a[*i].notas[3]);  
  getchar();

  float soma=a[*i].notas[0]+a[*i].notas[1]+a[*i].notas[2]+ a[*i].notas[3]; 
  printf("A nota total do aluno %s é %f\n",a[*i].nome,soma);  
  
  printf("\nDeseja continuar?");
  scanf("%c",&tecla);  
  system("clear");  
  }while(tecla!='n');
}
void remover(int tam,Aluno a[tam],int num){
  char tecla;
  
  do{
  printf("Digite o número do aluno que deseja remover:");
  scanf("%i",&tam);
  getchar();

  num=0;
  printf("\ndeseja continuar?");
  scanf("%c",&tecla);  
  }while(tecla!='n');
  
}
void aprovados(int tam,Aluno a[tam],int num,int* i){
  char tecla;
  do{
    for(i=0;*i<tam;i++)
    {
     printf("%s",a[*i].nome);
    }
  }while(tecla!='n');
    
}
void pesquisar(int tam,Aluno a[tam],int num){
  char tecla;
  do{
  printf("digite o número do aluno:");
  scanf("%i",&tam);

  if(num==1)
  {
    printf("Aluno:%s",a[tam].nome);
  }
  else{
    printf("Aluno removido!");
  }

  printf("\ndeseja continuar?");
  scanf("%c",&tecla);
  }while(tecla!='n');  
}
void listar(int tam,Aluno a[tam],int *i){
  char tecla;
  do{
  system("clear");
  printf("Digite o nome do aluno:");
  scanf("%s",a[*i].nome);
  
  printf("LISTA DE ALUNOS");
  for(*i=0; *i < 50;i++)
    {
     printf("Nome:%s",a[*i].nome);
     printf("Nota do 1 bimestre:%f",a[*i].notas[0]);
     printf("Nota do 2 bimestre:%f",a[*i].notas[1]);
     printf("Nota do 3 bimestre:%f",a[*i].notas[2]);
     printf("Nota do 4 bimestre:%f",a[*i].notas[3]);
    }

    printf("deseja continuar?\n");
    scanf("%c",&tecla);
    }while(tecla!='n');
}
void menu(Aluno a){
  
  system("clear");
  char tecla;
  int op;
  int tam=50;
  int* i=&tam;
  int num=1;
  if(num==1){
  do{
  printf("\n1-Cadastrar aluno \n2-Remover aluno \n3-Alunos aprovados \n4-Pesquisar aluno \n5-lista alunos \n0-Sair\n");
  scanf("%i", &op);

    switch(op)
      {
        case 1:cadastrar(tam,&a,i);
        break;
        case 2:remover(tam,&a,num);
        break;
        case 3:aprovados(tam,&a,num,i);
        case 4:pesquisar(tam,&a,num);
        break;
        case 5:listar(tam,&a,i);
      }
    }while(op!=0);
}
}
int main(void) {
  Aluno a;
  menu(a);
}