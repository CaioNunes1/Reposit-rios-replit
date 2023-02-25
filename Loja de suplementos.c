#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct{
  char nome_despesa[30];
  float preco_despesa; 
  int cod_despesa[30];

}Despesas;

typedef struct{
  char nome_venda[30];
  float preco_venda;
  int data_vendas[30];
  int codigo_venda[11];
}Vendas;

int main(void) {
  int i=10;
  Despesas despesas[i];
  Vendas vendas[i];
  int op,op2;
  char tecla,tecla2,tecla3;
  int id_compra;
  float total_despesas=0;
  int ver_despesas=0;
  float soma_vendas;
  float soma_saldo=0;
  int quant=1,ver_vendas=0,n_valor=1;
  
  do{//MENU PRINCIPAL
  system("clear");
  printf("\n***** Hulk BCC Suplementos *****\n\n********************************");
  printf("\n\n Menu HULK BCC Suplementos\n\n");
  printf("1-Despesas\n2-Vendas\n3-Ver extrato\n4-Ver saldo\n5-Sair");
  printf("\n\nDigite aqui a sua opcao desejada: ");
  scanf("%i",&op);
  getchar();

  if(op==1) //OPCAO DESPESAS
  {
    //OPCAO DESPESAS
    char op3;
    do{
      
    system("clear");
    printf("\n***** MENU DE DESPESAS *****");  
    printf("\n\nDeseja adicionar quantas despesas?\n->");
    scanf("%i",&op2);
    getchar();
      
    system("clear");

    for(i=1;i<=op2;i++)
      {
      system("clear");
      printf("\nDigite o nome da despesa %i:\n->",i);
      scanf("%[^\n]s",despesas[i].nome_despesa);
      getchar();  
      
       
      system("clear");  
      printf("\nDigite o valor da despesa %s:\n-> ",despesas[i].nome_despesa);
      scanf("%f",&despesas[i].preco_despesa);
      getchar();

      total_despesas+=despesas[i].preco_despesa;
        
    }
      ver_despesas=1;//ABRE UM IF EM EXTRATO, PARA MOSTRAR AS DESPESAS FINAIS
    printf("\nO total das suas despesas é R$%0.2f ",total_despesas);  
    
    printf("\n\nDeseja continuar no Menu Despesas (s/n)?\n->");
    scanf("%c",&tecla);
    getchar();  
    system("clear");
    }while(tecla!='n');
  }
  if (op==2) //OPCAO VENDAS
  {
    do{
       //OPCAO VENDAS
      system("clear");
      printf("\n***** MENU DE PRODUTOS *****\n");
    
    for(int i=1;i<=n_valor;i++)
      {
        if(n_valor==1)
        {
        printf("\nQuantos produtos que voce deseja adicionar ao carrinho?\n->");
        scanf("%i",&n_valor);
        getchar();
        }
        system("clear");
        printf("\n***** MENU DE PRODUTOS *****\n");
        printf("\ncodigo 101 - Creatina 150g - R$  50,00");
        printf("\ncodigo 102 - Creatina 500g - R$  150,00");
        printf("\ncodigo 103 - Whey Protein 500g - R$  100,00");
        printf("\ncodigo 104 - Whey Protein 1KG  - R$  200,00");
        printf("\ncodigo 105 - BCAA 150g - R$  125,00");
        printf("\ncodigo 106 - BCAA 300g - R$  250,00");
        printf("\ncodigo 107 - Vitamina C 100mg (120 cápsulas) - R$  45,00");
        printf("\ncodigo 108 - Vitamina C 455mg (120 cápsulas) - R$  50,00");
        printf("\ncodigo 109 - Termogenico 60 capsulas - R$  40,00");
        printf("\ncodigo 110 - Termogenico lipo 60 capsulas - R$  120,00");
        
        printf("\n\nDigite aqui o codigo do seu produto(%i):  ",i); 
        scanf("%i",&vendas[i].codigo_venda[i]);
        getchar();

        printf("\nDigite nome o produto(%i): ",i);
        scanf("%[^\n]s",vendas[i].nome_venda);
        getchar();

        printf("\nDigite o valor do produto(%i): ",i);
        scanf("%f",&vendas[i].preco_venda);
        getchar();

        printf("\nQual a quantidade de %s que você deseja? ",vendas[i].nome_venda);
        scanf("%i",&quant);
        getchar();
        
        soma_vendas+= quant * vendas[i].preco_venda;
        system("clear");
        
       //PENSANDO SE PEÇO PARA O USUÁRIO COLOCAR O NOME E O PREÇO DO PRODUTO 
      
      }  
      printf("O total da compra é de:%0.2f",soma_vendas);
      
      ver_vendas=1;
      printf("\n\nDeseja continuar(s/n)? ");
      scanf("%c",&tecla);
      getchar();
    }while(tecla!='n');
  }
    
  if(op==3)//OPCAO EXTRATO
  {
    do{
    system("clear");
    printf("\n***** Menu Extrato *****");
    if(ver_despesas==1)//VER EXTRATO DESPESAS
    {
      for(i=1;i<=op2;i++)
        {
          printf("\n\nA Despesa %s foi de R$%0.2f\n", despesas[i].nome_despesa,despesas[i].preco_despesa);
        }
    }

      if(ver_vendas==1)//VER EXTRATO VENDAS
      {
        for(i=1;i<=n_valor;i++)
        {
        printf("\n\nProduto %s de código %i tem valor total de R$%0.2f",vendas[i].nome_venda,vendas[i].codigo_venda[i],quant *vendas[i].preco_venda);
        }
      }

    printf("\n\nDeseja continuar no Menu Extrato?(s/n)\n->");
    scanf("%c",&tecla2);
    getchar();  
      
      }while(tecla2!='n');
  }

  if(op==4)//OPCAO SALDO
  {
    char tecla;
    system("clear");
  do{
    system("clear");
    printf("\n***** Menu Saldo *****");
    soma_saldo=(soma_vendas-total_despesas);
    
  if(soma_saldo >= 0)
    {
    printf("\n\nO seu saldo é positivo. Total de R$ %0.2f", soma_saldo);
    }
    
    else
    {
    printf("\n\nO seu saldo é negativo. Total de R$%0.2f",soma_saldo);
    }

    printf("\n\nDeseja continuar no Menu Saldo (s/n)?\n->");
    scanf("%c",&tecla);
    getchar();
    }while(tecla != 'n');
    
    }
    }while(op!=5);
 
}