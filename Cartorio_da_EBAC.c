#include <stdio.h> //Biblioteca de comunicação com o usuario
#include <stdlib.h> //Biblioteca de alocação de espaco em memória  
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável pelas strings

int registro() //Registro de usuário
{
	setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
	
    char arquivo[40]; // Definindo variaveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char resp;
	
    printf("Digite o CPF a ser cadastrado: "); // início da criação das variaveis do registro
	scanf("%s", cpf); //Salva a string
	
	strcpy(arquivo, cpf); //Responsável por igualar as variaveis cpf e aqruivo
	
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
	fclose(file); //Fim da criação das variveis 
	
	system("cls"); //limpa a tela
	
	printf ("O usuário foi adicionado com sucesso!\n");				        	    		
	printf ("--------------------------------------\n");	
	printf ("Deseja adicionar mais usuários? [S/N] "); //Perguntando se o usuário quer continuar
	scanf (" %c", &resp); //Lendo a resposta do usuário
	resp = toupper(resp); //Formatando a resposta para letra maiúscula
	
	if (resp == 'S') //Estrutura de condição caso "S"
	{
		system ("cls"); //LimpaTela
		registro(); //Retornar a função REGISTRO
	} //Fim da estrutura de condição caso "S"
	if (resp == 'N') //Estrutura de condição caso "N"													
	{																			
		system ("cls"); //LimpaTela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela	
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim da condição caso "N"
	if (resp != 'S' && resp != 'N') //Estrutura de condição caso a resposta seja diferente de "S" e de "N"										
	{
		system ("cls"); //LimpaTela
		printf ("Comando inválido!\n"); 
		printf ("Retornando ao menu...\n\n"); 
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim da condição caso resposta seja diferente de "S" e de "N"
	
}

int consulta() //Consultar usuário
{
	setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
	
	char cpf[40];  // Definindo variaveis
	char conteudo[200];
	char resp;
	
	printf("Digite o cpf a ser consultado: ");//Coleta do cpf
	scanf("%s", cpf); //Salva na string
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) // condição caso o valor seja nulo
	{
		printf("Usuário não encontrado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Buscando os dados do usuário
	{
		setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
		
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	fclose(file);
	
	printf ("\n");
	printf ("-------------------------------------\n");
	printf ("Deseja consultar outro usuário? [S/N] "); //Perguntando ao usuário
	scanf (" %c", &resp); //Lendo resposta
	resp = toupper(resp); //Formatando resposta do usuário para letra maiúcula
	
	if (resp == 'S') //Condição SE resposta = "S"
	{ //Início condição
		system ("cls"); //LimpaTela
		consulta(); //Retornar a função CONSULTA
	} //Fim condição
	
	if (resp == 'N') //Condição SE resposta = "N"																		
	{ //Início condição
		system ("cls"); //LimpaTela						
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela do usuário
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim condição
	
	if (resp != 'S' && resp != 'N') //Condição SE resposta <> "S" e "N"
	{ //Início condição
		system ("cls"); //LimpaTela	
		printf ("Comando inválido!\n"); //Escrevendo na tela do usuário
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela do usuário
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim condição
		
}

int deletar() //Deletar usuário
{
	setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
	
	char cpf[40]; //Definação da variavel
	char resp;
	
	printf("Digite o cpf do usuário a ser deletado: "); //coleta de cpf 
	scanf("%s", cpf);
	
	FILE *file; //ler o arquivo
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL) //Caso Não tenha o cadastro
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	else
	{
		remove(cpf); //Se for deletado 
		printf("Usuário deletado com sucesso! \n");
	}
	
	printf ("----------------------------------\n");
	printf ("Deseja deletar outro usuário? [S/N] "); //Perguntando ao usuário
	scanf (" %c", &resp); //Lendo resposta
	resp = toupper(resp); //Formatando resposta para letra maiúscula
	
	if (resp == 'S') //Condição Se resp2 = "S"
	{ //Início condição
		system ("cls"); //LimpaTela
		deletar(); //Retornar função DELETAR
	} //Fim condição
	
	if (resp == 'N') //Condição Se = "N"
	{ //Início condição
		system ("cls"); //LimpaTela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim condição
	
	if (resp != 'S' && resp != 'N') //Se diferente de "S" e de "N"
	{ //Início condição
		system ("cls"); //LimpaTela
		printf ("Comando Inválido!\n"); //Escrevendo na tela
		printf ("Retornando ao menu...\n\n"); //Escrevendo na tela
		system ("pause"); //Pausando
		main(); //Retornando função PRINCIPAL
	} //Fim condição
	
}

int main() //função principal(menu)
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	  system("cls");
	
	  setlocale(LC_ALL,"portuguese"); //Definindo a Linguagem
	
	  printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	  printf("Escolha a apção desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n"); 
	  printf("\t4 - Sair do sistema\n\n");
	  printf("Opção: "); //Fim do menu
	
	  scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	  system("cls");
	  
	  switch(opcao)// inicio da seleção
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
		printf("Essa opção não esta disponível!\n");
		system("pause");
		break;// Fim da seleção
	 }
	  	  
   }
}
