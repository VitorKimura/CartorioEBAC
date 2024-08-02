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
	char resp;
	
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
	
	system("cls"); //limpa a tela
	
	printf ("O usu�rio foi adicionado com sucesso!\n");				        	    		
	printf ("--------------------------------------\n");	
	printf ("Deseja adicionar mais usu�rios? [S/N] "); //Perguntando se o usu�rio quer continuar
	scanf (" %c", &resp); //Lendo a resposta do usu�rio
	resp = toupper(resp); //Formatando a resposta para letra mai�scula
	
	if (resp == 'S') //Estrutura de condi��o caso "S"
	{
		system ("cls"); //LimpaTela
		registro(); //Retornar a fun��o REGISTRO
	} //Fim da estrutura de condi��o caso "S"
	if (resp == 'N') //Estrutura de condi��o caso "N"													
	{																			
		system ("cls"); //LimpaTela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela	
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim da condi��o caso "N"
	if (resp != 'S' && resp != 'N') //Estrutura de condi��o caso a resposta seja diferente de "S" e de "N"										
	{
		system ("cls"); //LimpaTela
		printf ("Comando inv�lido!\n"); 
		printf ("Retornando ao menu...\n\n"); 
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim da condi��o caso resposta seja diferente de "S" e de "N"
	
}

int consulta() //Consultar usu�rio
{
	setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
	
	char cpf[40];  // Definindo variaveis
	char conteudo[200];
	char resp;
	
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

	fclose(file);
	
	printf ("\n");
	printf ("-------------------------------------\n");
	printf ("Deseja consultar outro usu�rio? [S/N] "); //Perguntando ao usu�rio
	scanf (" %c", &resp); //Lendo resposta
	resp = toupper(resp); //Formatando resposta do usu�rio para letra mai�cula
	
	if (resp == 'S') //Condi��o SE resposta = "S"
	{ //In�cio condi��o
		system ("cls"); //LimpaTela
		consulta(); //Retornar a fun��o CONSULTA
	} //Fim condi��o
	
	if (resp == 'N') //Condi��o SE resposta = "N"																		
	{ //In�cio condi��o
		system ("cls"); //LimpaTela						
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela do usu�rio
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim condi��o
	
	if (resp != 'S' && resp != 'N') //Condi��o SE resposta <> "S" e "N"
	{ //In�cio condi��o
		system ("cls"); //LimpaTela	
		printf ("Comando inv�lido!\n"); //Escrevendo na tela do usu�rio
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela do usu�rio
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim condi��o
		
}

int deletar() //Deletar usu�rio
{
	setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
	
	char cpf[40]; //Defina��o da variavel
	char resp;
	
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
	}
	
	printf ("----------------------------------\n");
	printf ("Deseja deletar outro usu�rio? [S/N] "); //Perguntando ao usu�rio
	scanf (" %c", &resp); //Lendo resposta
	resp = toupper(resp); //Formatando resposta para letra mai�scula
	
	if (resp == 'S') //Condi��o Se resp2 = "S"
	{ //In�cio condi��o
		system ("cls"); //LimpaTela
		deletar(); //Retornar fun��o DELETAR
	} //Fim condi��o
	
	if (resp == 'N') //Condi��o Se = "N"
	{ //In�cio condi��o
		system ("cls"); //LimpaTela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim condi��o
	
	if (resp != 'S' && resp != 'N') //Se diferente de "S" e de "N"
	{ //In�cio condi��o
		system ("cls"); //LimpaTela
		printf ("Comando Inv�lido!\n"); //Escrevendo na tela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela
		system ("pause"); //Pausando
		main(); //Retornando fun��o PRINCIPAL
	} //Fim condi��o
	
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
	  printf("\t3 - Deletar nomes\n"); 
	  printf("\t4 - Sair do sistema\n\n");
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
		
		case 4:
		printf("Obrigado por utilizar o sitema!\n");
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o esta dispon�vel!\n");
		system("pause");
		break;// Fim da sele��o
	 }
	  	  
   }
}
