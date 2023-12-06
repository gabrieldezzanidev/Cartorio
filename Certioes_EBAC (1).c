#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  // biblioteca de aloca��o de espa�o em memoria 
#include <locale.h>  // biblioteca de aloca��es de texto por regi�o
#include <string.h>  // biblioteca responsavel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usuarios no sistema
{
	//inicio da cria��o de vari�veis/strings
	char arquivo [40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings

	printf("Digite o CPF para cadastro: "); //coletando inform�a�es de usuario
	scanf("%s", cpf); //%s salva a string

	strcpy(arquivo, cpf); // copia os valores da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");  // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a"); // "a" atualizar a variavel
	fprintf(file,",");
	fclose(file);
	
	printf("Digite seu nome para cadastro: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite seu sobrenome para cadastro: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite seu cargo para cadastro: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo as linguagens
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL )
	{
	printf("Arquivo n�o localizado. \n" );
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser exclu�do: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("O Usu�rio n�o existe neste sistema. \n" );
		system ("pause");
	}
	else 
		printf ("O Usu�rio foi excluido deste sistema. \n");
		system ("pause");

		 
	

}


int main()
{
	int opcao=0;  //definindo as vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{

		setlocale(LC_ALL, "Portuguese"); //definindo as linguagens
	
		system("cls"); //limpa a tela
		
		printf("### Cartorio da EBAC ### \n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n  ");
		printf("\t1 - Registrar Nomes \n ");
		printf("\t2 - Consultar Nomes \n ");
		printf("\t3 - Deletar Nomes \n\n "); //fim do menu
		printf("Op��o: ");
	
		scanf("%d", &opcao); //armazenando as escolhas do usu�rio
	
		system("cls");
		
		switch(opcao) //inicio da sela��o do mennu
		{
			case 1: 
			registro(); //chamada de fun��es 
			break;
	
	
			case 2:	
			consulta();
			break;	
		
		
			case 3: 
			deletar();
			break;
			
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}//fim da sele��o
		
		
	}
}      
