#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  char ID[5];
  char nome[30];
  int tipo;
  float valor;
  char descricao[30];
  int status;
}Produto;

typedef struct{
  char nome[30];
  char ID[5];
  char endereco[30];
}Cliente;

typedef struct{
  char ID[5];
  char ID_cliente;
  char ID_produto;
}Compra;
int inserirProduto(int tam,Produto produto[tam],int* i){
  char tecla; // auxiliar;
  tam =10;//auxiliar
  int opc_inserprod;
  printf("1- Inserir produto   2-Remover produto   3-Buscar produto");
  scanf("%i",&opc_inserprod);
  getchar();
  
  if(opc_inserprod ==1){
    do
      {
      printf("digite o nome do produto:");
      scanf("%s", produto[*i].nome);
      getchar();
        
      printf("digite o id do produto:");
      scanf("%s", produto[*i].ID);
      getchar();
        
      printf("digite o tipo do produto:");
      scanf("%i", &produto[*i].tipo);
      getchar();
        
      printf("digite o valor do produto:");
      scanf("%f", &produto[*i].valor);
      getchar();
        
      printf("digite o status do produto:");
      scanf("%i", &produto[*i].status);
      getchar();  
      
      printf("produto:%s| id:%s| tipo:%i| valor:%f| status:%i ", produto[*i].nome, produto[*i].ID,produto[*i].tipo,produto[*i].valor,produto[*i].status);
      printf("Deseja continuar?");
      scanf("%c", &tecla); 
      getchar();  
      i++;
      system("clear"); 
      }while(tecla=='s');
  }
  else if(opc_inserprod==2)
  {
    do{
    char op_RemProd;
    printf("Produtos adicionados:%s,", produto[*i].nome);
    printf("Deseja remove-lo?(s/n)");
    scanf("%c", &op_RemProd);
    getchar();

    if(op_RemProd=='s')
    {
      produto[*i].status=0;
    }
    if(op_RemProd=='n')
    {
      produto[*i].status=1;
    }
  char tecla;
  printf("deseja continuar?");
  scanf("%c", &tecla);
  return 0;
  }while(tecla!='n');
  }

    
  else if(opc_inserprod==3){
    do{
    if(produto[*i].status==0)
    {
      printf("Não há produtos cadastrados!");
    }
    else if(produto[*i].status==1)
    {
     printf("%i",produto[*i].status);
    }
  
  char tecla;
  printf("\ndeseja continuar?");
  scanf("%c", &tecla);
  }while(tecla!='n');
  }
  return 0;
}


void Inserir_Cliente(int tam, Cliente cliente[tam], int* i){
  char tecla;
  do{
  tam=10;
  int op_cliente;
  printf("1-Inserir Cliente  2-Buscar cliente");
  scanf("%i", &op_cliente);

  if(op_cliente==1)
  {
    printf("Nome do cliente:");
    scanf("%s", cliente[*i].nome);

    printf("ID do cliente:");
    scanf("%s", cliente[*i].ID);

    printf("Endereço do cliente:");
    scanf("%s", cliente[*i].endereco);

    printf("Cliente:%s ID:%s Endereço:%s",cliente[*i].nome,cliente[*i].ID,cliente[*i].endereco);

    (*i)++;  
  }
  //buscar cliente
  if(op_cliente==2){
    printf("digite o nome do cliente:");
    scanf("%s",cliente[*i].nome);
    getchar();
    
    printf("%s %s %s",cliente[*i].nome,cliente[*i].endereco,cliente[*i].ID);
  }
    
  printf("\ndeseja continuar?");
  scanf("%c",&tecla);
  getchar();
    
  }while(tecla!='n');
}

void Inserir_compra(int tam, Compra compra[tam], int* i){
  Compra a[tam];
  char tecla;
  int op;
  int comp_feita;
  char aux,aux2;
  printf("1-Fializar compra  2-Buscar compra");
  scanf("%i",&op);
  getchar();

  if(op==1)
  {
    do{
    printf("digite o id do produto:");
    scanf("%c",&compra[*i].ID_produto);
    getchar();

    printf("\ndigite o id do cliente:");
    scanf("%c",&compra[*i].ID_cliente);
    getchar();

    printf("COMPRA FINALIZADA: cliente :%c\n produto:%c ",compra[*i].ID_produto,compra[*i].ID_cliente);

    comp_feita=1;
    aux = compra[*i].ID_produto;
    aux2=compra[*i].ID_cliente;  
    }while(tecla!='n');  
  }
  
  if(op==2)
  {
    if(comp_feita==1)
    {
      do{
     printf("COMPRA REGISTRADA: produto-%c \ncliente-%c ",aux,aux2);

     printf("\n\ndeseja continuar?");
     scanf("%c",&tecla);
        }while(tecla!='n');  
    }
  }
}


int main(void) {
  int opcao;
  int tam_c=50;
  Produto produto[tam_c];
  Cliente cliente[tam_c];
  Compra compra[tam_c];
  int* i=0;
  do{
  printf("***Bem-vindo ao menu***");
  printf("\nOPÇÕES: 1-Inserir produto   2-Inserir cliente   3-Inserir compra\n");
  scanf("%i", &opcao);
  getchar();
  system("clear");

  if(opcao==1){
    inserirProduto(tam_c, produto, i);
    }
  if(opcao==2)
  {
    Inserir_Cliente(tam_c, cliente, i);
  }
  if(opcao==3)
  {
    Inserir_compra(tam_c, compra, i);
  }  
    }while(1);
}