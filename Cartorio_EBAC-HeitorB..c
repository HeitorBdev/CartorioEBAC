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
	char cpf[40];    //cria��o da vari�vel char de nome "cpf" com carga de 40 caracteres
	char nome[40];	 //cria��o da vari�vel char de nome "nome" com carga de 40 caracteres
	char sobrenome[40]; //cria��o da vari�vel char de nome "sobrenome" com carga de 40 caracteres
	char cargo[40]; //cria��o da vari�vel char de nome "cargo" com carga de 40 caracteres
	char telefone[40]; //cria��o da vari�vel char de nome "telefone" com carga de 40 caracteres
	//final da cria��o de vari�veis/strings
	

	

	printf("        Registro de Usu�rios      \n\n\n");
	
	printf("Digite o CPF: "); // printf � a fun��o respons�vel pela exibi��o na tela
	scanf("%s", cpf); //fun��o que l� o valor/dado digitado pelo usu�rio
	
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
	
	char opcao; //criando a vari�vel de nome "op��o"
	opcao = getchar(); //definindo que "op��o" � a escolha o usu�rio
	
	system("cls");
	
	if (opcao == '1') //se a condi��o for verdadeira, fa�a isso
	{	
		registro(); //voltar ao menu "Registros"
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

int consulta()// criando fun��o de nome "consulta" para consultar registros
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
	file = fopen(cpf,"r"); //fun��o para abrir e ler o arquivo j� salvo (r = read)
	
	
	if(file == NULL) // "if" -> func��o "se" = "if" se sim / "while" se n�o.. "file == NULL" -> se o arquivo n�o for localizado
	{
		printf("\n\tCPF N�o Localizado!  \n");
		printf("          Tente Novamente!");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL) // "fgets" = buscar no banco de dados todos os dados do arquivo "!= NULL" at� o final do arquivo
	{
		printf("%s", conteudo); //imprimir na tela informa��es do arquivo em quest�o
	}

	printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
	system("pause");
	system("cls");
	
	printf("        Consulta de Registros      \n\n\n");	
	printf("Deseja Consultar um Novo Registro? \n");
	printf("\n\n    1 = SIM      2 = N�O\n\n");
	printf("Op��o: ");
	
	
	getchar(); //fun��o que l� a entrada do usu�rio atrav�s de caracteres
	
	char opcao; //criando a vari�vel de nome "op��o"
	opcao = getchar(); //definindo que "op��o" � a escolha o usu�rio
	
	system("cls");
	
	if (opcao == '1') //se a condi��o for verdadeira, fa�a isso
	{	
		consulta(); //voltar ao menu "Consulta"
	}
	
	else if (opcao == '2') // sen�o, fa�a isso
	{
		//apenas voltar ao menu principal
	}
	
	else //se n�o for nenhum dos dois, fa�a isso
	{
		printf("        Consulta de Registros      \n\n\n");
		printf("           Op��o Inv�lida.\n");
		printf("          Tente Novamente!");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
		
		system("pause");
	}
	
	fclose(file);

}

int exclusao()// vari�vel "int" de nome "exclus�o" = Fun��o respons�vel pela exclus�o de registros
{
	setlocale(LC_ALL, "Portuguese"); //definindo biblioteca de linguagem 
	
	char cpf[40];
	
	printf("        Exclus�o de Registro      \n\n\n");
	printf("Digite o CPF a ser Exlcu�do: ");
	scanf("%s", cpf);
		
	FILE *file; //abrindo pasta onde se localiza o arquivo 
	file = fopen(cpf,"r"); //lendo banco de dados para validar dados inseridos pelo usu�rio
	fclose(file);
	
	system("cls");
	
	if (file == NULL) //se n�o for encontrado
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
	printf("\n\n    1 = SIM      2 = N�O\n\n"); //valida��o para exclus�o de dados
	printf("Op��o: ");
	
	
	getchar(); //fun��o que l� a entrada do usu�rio atrav�s de caracteres
	
	char opcao; //criando a vari�vel op��o
	opcao = getchar(); //definindo que "op��o" = entrada de dados do usu�rio

	system("cls");
	
	if (opcao == '1') //se a "op��o" for igual � 1, fazer isso
	{
	if (remove(cpf) == 0){ //excluir dados do registro solicitado, no caso "cpf"
	
		printf("        Exclus�o de Registro      \n\n\n");	
		printf("\tCPF: ");
		printf("%s", cpf);
		printf("\n  Deletado com Sucesso!"); //confirma��o de exclus�o de registro
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
		system("pause");
	}
	}
	
	else if (opcao == '2') //se a op��o for igual � 2
	{
		printf("        Exclus�o de Registro      \n\n\n");
		printf("         Opera��o Cancelada!");
		printf("\nPressione Qualquer Tecla para Continuar.");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
		
		system("pause");
		
	}
	
	else //se for diferente das op��es acima
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
	setlocale(LC_ALL, "Portuguese"); //definindo biblioteca de linguagem 

	//Definindo vari�veis
	int opcao=0; //vari�vel "int" de nome "op��o" com valor = 0
	int repeticao=1; //vari�vel "int" de nome "repeticao" com valor =1
	char senhadigitada[]="a";
	int comparacao;
	
	printf("            Cart�rio da EBAC \n");
	printf("\n\n Login de Administrador \n\n Digite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	
	
	if(comparacao == 0)
	{
	
		for(repeticao=1;repeticao=1;) //criando la�o de repeti��o - enquanto "repeticao" = 1, manter o processo
		{
		
			system("cls"); //comando de limpar a tela
	
			setlocale(LC_ALL, "Portuguese"); //definindo biblioteca de linguagem 

			printf("            Cart�rio da EBAC \n"); //in�cio do menu
			printf("           Seja Bem-Vinda (o)!\n\n\n");
			printf("Escolha a op��o desejada no menu abaixo:\n\n");
			printf("\t1 - Registro de Usu�rios \n");
			printf("\t2 - Consultar Registros\n");
			printf("\t3 - Excluir Registro\n");
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
				printf("\tObrigado por utilizar esse sistema!!");
				printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
				return 0; //chamada para quebrar o loopoing e encerrar	
						
				default: //se o usu�rio digitar uma op��o inv�lida
				printf("            Cart�rio da EBAC \n\n\n");
				printf("\tOp��o Indispon�vel,");
				printf("\nEscolha apenas entre as op��es 1, 2, 3 ou 4!");
				printf("\n\n         Tente Novamente!!");
				printf("\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
				system("pause");
				break;
			}//fim da sele��o	
		}
	} 
	
	else
	{
		system("cls");
		printf("\t Senha Inv�lida\n\tTente Novamente!");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.�\n\n\n");
		system("pause");
		system("cls");
		main();
	}
}
