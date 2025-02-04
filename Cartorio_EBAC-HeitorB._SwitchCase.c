#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings(sequ�ncia de caracteres alfanum�ricos)

int registro() //int � a vari�vel utilizada para definir n�meros inteiros
{
	//Fun��o Registro, respons�vel por novos cadastros
	
	setlocale(LC_ALL, "Portuguese");
	
	//come�o da cria��o das vari�veis/strings
	char arquivo[40]; //char � a vari�vel utilizada para armazenar caracteres
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char telefone[40];
	//final da cria��o de vari�veis/strings
	

	

	printf("        Registro de Usu�rios      \n\n\n");
	
	printf("Digite o CPF: "); // printf � a fun��o respons�vel pela exibi��o na tela
	scanf("%s", cpf); //fun��o que l� o dado digitado pelo usu�rio
	
	strcpy(arquivo, cpf); //fun��o Respons�vel por copiar o valor das strings
	
	FILE *file; //fun��o que cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria um novo arquivo (w = write)
	fprintf(file,"\nEssas s�o as Informa��es do Usu�rio:\n\n");
	fprintf(file,"\tCPF: ");
	fprintf(file,cpf); //fprintf salva o valor da vari�vel (no caso, o cpf no arquivo)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //fun��o para abrir o arquivo j� salvo (a = atualizar)
	fprintf(file, "\n\tNome: "); //fun��o que escreve adiciona algo dentro do arquivo 
	fclose(file);
		
	printf("Digite o Nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o Sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n\tCargo: ");
	fclose(file);
	
	printf("Digite o Cargo Desejado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n\tTelefone: ");
	fclose(file);
	
	printf("Telefone: ");
	scanf("%s", telefone);
	
	file = fopen(arquivo, "a");
	fprintf(file, telefone);
	fclose(file);
	
	system("cls"); // repons�vel por limpar a tela
	
	printf("        Registro de Usu�rios      \n\n\n");	
	printf("Deseja Realizar um Novo Registro? \n");
	printf("\n\n    1 = SIM      2 = N�O\n\n");
	printf("Op��o: ");
	
	
	getchar(); //fun��o que l� a entrada do usu�rio atrav�s de caracteres
	
	char opcao; //criando a vari�vel op��o
	opcao = getchar();
	
	system("cls");
	
	if (opcao == '1') //se a condi��o for verdadeira, fa�a isso
	{	
		registro();
	}
	
	else if (opcao == '2') // sen�o, fa�a isso
	{
		//apenas voltar ao menu principal
	}
	
	else //se n�o for nenhum dos dois, fa�a isso
	{
		printf("        Registro de Usu�rios      \n\n\n");
		printf("           Op��o Inv�lida.\n");
		printf("          Tente Novamente!");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
		
		system("pause");
	}

}

int consulta()//fun��o para consultar registros
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("        Consulta de Registro      \n\n\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser Consultado: ");
	scanf("%s", cpf);
	
	system("cls");

	printf("        Consulta de Registro      \n\n");
	
	FILE *file;
	file = fopen(cpf,"r"); //fun��o para abrir o arquivo j� salvo (r = read)
	
	
	if(file == NULL) // se o arquivo n�o for localizado
	{
		printf("\n\tCPF N�o Localizado!  \n");
		printf("          Tente Novamente!");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL) //imprimir na tela todos os dados do arquivo
	{
		printf("%s", conteudo);
	}
	
	printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");

	fclose(file);
	system("pause");
}

int exclusao()//Fun��o respons�vel pela exclus�o de registros
{
	char cpf[40];
	
	printf("        Exclus�o de Registro      \n\n\n");
	printf("Digite o CPF a ser Exlcu�do: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	system("cls");
	
	if (file == NULL)
	{
		printf("        Exclus�o de Registro      \n\n\n");
		printf("\tCPF: ");
		printf("%s",cpf);
		printf("\n\nN�o Encontrado. Tente Novamente!!");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
		system("pause");
		return 0; //comando para fazer o usu�rio retornar ao menu principal
	}
		
	printf("        Exclus�o de Registro      \n\n\n");	
	printf("Deseja Excluir este Registro? \n");
	printf("\tCPF: ");
	printf("%s", cpf);
	printf("\n\n    1 = SIM      2 = N�O\n\n");
	printf("Op��o: ");
	
	
	getchar(); //fun��o que l� a entrada do usu�rio atrav�s de caracteres
	
	char opcao; //criando a vari�vel op��o
	opcao = getchar();
	
	system("cls");
	
	if (opcao == '1')
	{
	if (remove(cpf) == 0){
	
		printf("        Exclus�o de Registro      \n\n\n");	
		printf("\tCPF: ");
		printf("%s", cpf);
		printf("\n  Deletado com Sucesso!");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
	}
		system("pause");
	}
	
	else if (opcao == '2')
	{
		printf("        Exclus�o de Registro      \n\n\n");
		printf("         Opera��o Cancelada!");
		printf("\nPressione Qualquer Tecla para Continuar.");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
		
		system("pause");
	}
	
	else
	{
		printf("        Exclus�o de Registro      \n\n\n");
		printf("           Op��o Inv�lida.\n");
		printf("          Tente Novamente!");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
		
		system("pause");
	}
	
}

int main() //Fun��o do men�, come�o do programa
{
	int opcao=0; //Definindo Vari�veis
	int repeticao=1;
	
	for(repeticao=1;repeticao=1;)
	{
		
		system("cls"); //comando de limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo biblioteca de linguagem 

		printf("            Cart�rio da EBAC \n"); //in�cio do menu
		printf("           Seja Bem-Vinda (o)!\n\n\n");
		printf("Escolha a op��o desejada no menu abaixo:\n\n");
		printf("\t1 - Registrar Alunos\n");
		printf("\t2 - Consultar Registros de Alunos\n");
		printf("\t3 - Deletar Registro de Aluno\n");
		printf("\t4 - Encerrar Programa\n\n\n");
		printf("Op��o: "); //fim do menu
		
				
		scanf("%d", &opcao); //armazenamento da escolha do usu�rio
		
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada para a fun��o registro
			break;
			
			case 2:
			consulta(); //chamada para a fun��o consulta
			break;
			
			case 3:
			exclusao(); //chamada para a fun��o exclusao
			break;
					
			case 4:
			printf("Obrigado por utilizar o sistema!!");
			printf("\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
			return 0; //chamada para quebrar o loopoing e encerrar
			break;
				
						
			default:
			printf("            Cart�rio da EBAC \n\n\n");
			printf("\tOp��o Indispon�vel,");
			printf("\nEscolha apenas entre as op��es 1, 2 ou 3!");
			printf("\n\n         Tente Novamente!!");
			printf("\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
			system("pause");
			break;
		}
		
		
		
		} //fim da sele��o
	
	
	}
