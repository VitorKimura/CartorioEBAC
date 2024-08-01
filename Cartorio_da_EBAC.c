#include <stdio.h> //Biblioteca de comunica��o com o usuario
#include <stdlib.h> //Biblioteca de aloca��o de espaco em mem�ria  
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel pelas strings

int registro() //Registro de usu�rio
{
	setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
	
    char arquivo[40]; // Definindo variaveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
    printf("Digite o CPF a ser cadastrado: "); // in�cio da cria��o das variaveis do registro
	scanf("%s", cpf); //Salva a string
	
	strcpy(arquivo, cpf); //Respons�vel por igualar as variaveis cpf e aqruivo
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o aqruivo
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Coloca a virgula para separar as variaveis
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Cadrastro de nome
    scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,nome);
	fclose(file);
	
    file = fopen(arquivo, "a");// Coloca a virgula para separar as variaveis
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");// Cadastro de sobrenome
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");//Atualiza o arquivo
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");// Coloca a virgula para separar as variaveis
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //cadastro do cargo
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file); //Fim da cria��o das variveis 
	
	system("pause");
		
}

int consulta() //Consultar usu�rio
{
	setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
	
	char cpf[40];  // Definindo variaveis
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");//Coleta do cpf
	scanf("%s", cpf); //Salva na string
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) // condi��o caso o valor seja nulo
	{
		printf("Usu�rio n�o encontrado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Buscando os dados do usu�rio
	{
		setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
		
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar() //Deletar usu�rio
{
	setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
	
	char cpf[40]; //Defina��o da variavel
	
	printf("Digite o cpf do usu�rio a ser deletado: "); //coleta de cpf 
	scanf("%s", cpf);
	
	FILE *file; //ler o arquivo
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL) //Caso N�o tenha o cadastro
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	else
	{
		remove(cpf); //Se for deletado 
		printf("Usu�rio deletado com sucesso! \n");
		system("pause");
		
	}
	
}

int main() //fun��o principal(menu)
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	  system("cls");
	
	  setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
	
	  printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	  printf("Escolha a ap��o desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n"); 
	  printf("Op��o: "); //Fim do menu
	
	  scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	  system("cls");
	  
	  switch(opcao)// inicio da sele��o
	  {
	  	case 1:
	    registro();
		break; 
		
		case 2:
	    consulta();
		break;
		
		case 3:
	    deletar();
		break;
		
		default:
		printf("Essa op��o n�o esta dispon�vel!\n");
		system("pause");
		break;// Fim da sele��o
	 }
	  	  
   }
}
