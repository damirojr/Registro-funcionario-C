#include <stdio.h>
#include <conio.h>
#include <string.h>
 
typedef struct{
   int matricula;
   char nome[50];
   char cargo[50];
   float salario;
}func;

FILE * fp;   
func registro;  

// Desenvolver
void inserir ()
{
	if((fp = fopen("C:\\temp\\funcionario.txt","a"))==NULL)
	{
		printf("Arquivo nao pode ser aberto! \n");
	}
	else
	{
		printf("Entre com os dados do funcionario: \n");
		
		do
		{
			printf("Insira a matricula: ");
			scanf("%i", &registro.matricula);
			
			if(registro.matricula <= 0)
			{
				printf ("Valor invalido, digite o codigo novamente!\n");
                fflush(stdin);
			}
			
		}while(registro.matricula <= 0 );
		fflush(stdin);
		
		printf("Digite o nome: ");
		gets(registro.nome);
		
		printf("Digite o cargo: ");
		gets(registro.cargo);
		
		do
		{
			printf("Informe o salario: ");
			scanf("%f", &registro.salario);
			
			if(registro.salario <= 0)
			{
				printf ("Valor invalido, digite o codigo novamente!\n");
                fflush(stdin);
			}
		}while(registro.salario <= 0);
		
		fwrite (&registro, sizeof(func), 1, fp);
		fclose (fp);
		
		printf("Funcionario inserido com sucesso!\n");	
	}
	
}

// Desenvolver
void listarcargo () 
{
	int achou;
	char cargosearch [50];
		
	if((fp = fopen("c:\\temp\\funcionario.txt","r"))==NULL)
    {
       printf("Arquivo nao pode ser aberto! \n");
    }
    else 
    { 
    	fflush(stdin);
		printf("Informar o cargo a ser localizado: ");
   		scanf("%s", &cargosearch);		
		achou=0;
			 
		while(fread(&registro, sizeof(func), 1, fp)==1)
		{	
			strupr(cargosearch);
         	strupr(registro.cargo);
         	
   	        if(strcmp(registro.cargo,cargosearch)==0)
			{
				printf ("\nMatricula: %i\n", registro.matricula);
   		       	printf ("Nome: %s\n", registro.nome);
        	   	printf ("Cargo: %s\n", registro.cargo);
           		printf ("Salario: %.2f\n", registro.salario);
           		achou=1;
			}
		}
		if (achou==0)
		{
			printf ("Cargo nao localizado!\n");
         	fclose (fp);
		}
	}
}
void listar () 
{
    int achou;
    
    if((fp = fopen("c:\\temp\\funcionario.txt","r"))==NULL)
    {
       printf("Arquivo nao pode ser aberto! \n");
    }
    else 
    {
         achou=0;
         while (fread(&registro, sizeof(func), 1, fp)==1) 
         {
   	           printf ("\nMatricula: %i\n", registro.matricula);
   	           printf ("Nome: %s\n", registro.nome);
               printf ("Cargo: %s\n", registro.cargo);
               printf ("Salario: %.2f\n", registro.salario);
               achou=1;
         }
         if (achou==0)
		{
			printf ("Arquivo vazio!\n");
        	fclose (fp);
    	}
	}
} 




int main()
{
       int opcao;
       do 
       {
         system("cls");
             
         printf("Selecione a opcao desejada:\n");
         printf(" 1- Inserir Funcionario\n 2- Listar Cadastro Funcionario\n 3- Listar Funcionario por Cargo\n 0- Sair\n");
           
         scanf("%i", &opcao);
                    
         switch (opcao) 
          {
                 case 1:
                      inserir();	
                      break;
                 case 2:
                      listar();
                      break;
                 case 3:
                      listarcargo();
                      break;
                 default:
                 {                        
                    if (opcao != 0)
                    {
                       printf("%d Opcao Invalida \n", opcao);
                    }
                 }
          } 
          
          system("pause");     
       } while (opcao != 0);
	        
}
