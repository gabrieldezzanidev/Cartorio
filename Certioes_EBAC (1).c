#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h>  // biblioteca de alocação de espaço em memoria 
#include <locale.h>  // biblioteca de alocações de texto por região
#include <string.h>  // biblioteca responsavel por cuidar das strings

int registro() //função responsável por cadastrar os usuarios no sistema
{
	//inicio da criação de variáveis/strings
	char arquivo [40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings

	printf("Digite o CPF para cadastro: "); //coletando informçaões de usuario
	scanf("%s", cpf); //%s salva a string

	strcpy(arquivo, cpf); // copia os valores da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");  // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); // salva o valor da variável
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
	printf("Arquivo não localizado. \n" );
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser excluído: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("O Usuário não existe neste sistema. \n" );
		system ("pause");
	}
	else 
		printf ("O Usuário foi excluido deste sistema. \n");
		system ("pause");

		 
	

}


int main()
{
	int opcao=0;  //definindo as variáveis
	int x=1;
	
	for(x=1;x=1;)
	{

		setlocale(LC_ALL, "Portuguese"); //definindo as linguagens
	
		system("cls"); //limpa a tela
		
		printf("### Cartorio da EBAC ### \n\n"); //início do menu
		printf("Escolha a opção desejada do menu: \n\n  ");
		printf("\t1 - Registrar Nomes \n ");
		printf("\t2 - Consultar Nomes \n ");
		printf("\t3 - Deletar Nomes \n\n "); //fim do menu
		printf("Opção: ");
	
		scanf("%d", &opcao); //armazenando as escolhas do usuário
	
		system("cls");
		
		switch(opcao) //inicio da selação do mennu
		{
			case 1: 
			registro(); //chamada de funções 
			break;
	
	
			case 2:	
			consulta();
			break;	
		
		
			case 3: 
			deletar();
			break;
			
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}//fim da seleção
		
		
	}
}      
