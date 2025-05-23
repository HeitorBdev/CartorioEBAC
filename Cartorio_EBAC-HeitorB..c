#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings(sequência de caracteres alfanuméricos)

int registro() //int é a variável utilizada para definir números inteiros
{
	//Função Registro, responsável por novos cadastros
	
	setlocale(LC_ALL, "Portuguese");
	
	//começo da criação das variáveis/strings
	char arquivo[40]; //char é a variável utilizada para armazenar caracteres
	char cpf[40];    //criação da variável char de nome "cpf" com carga de 40 caracteres
	char nome[40];	 //criação da variável char de nome "nome" com carga de 40 caracteres
	char sobrenome[40]; //criação da variável char de nome "sobrenome" com carga de 40 caracteres
	char cargo[40]; //criação da variável char de nome "cargo" com carga de 40 caracteres
	char telefone[40]; //criação da variável char de nome "telefone" com carga de 40 caracteres
	//final da criação de variáveis/strings
	

	

	printf("        Registro de Usuários      \n\n\n");
	
	printf("Para otimizar o uso do sistema, ao realizar o cadastro, solicitamos que não insira espaços\n e preencha o CPF seguindo o formato do exemplo abaixo, com pontos e traço:\n xxx.xxx.xxx-xx.\n\n");
	printf("\n\nDigite o CPF: "); // printf é a função responsável pela exibição na tela
	scanf("%s", cpf); //função que lê o valor/dado digitado pelo usuário
	
	strcpy(arquivo, cpf); //função Responsável por copiar o valor das strings
	
	FILE *file; //função que cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria um novo arquivo (w = write)
	fprintf(file,"\n   Essas são as Informações do Usuário:\n\n");
	fprintf(file,"\tCPF: ");
	fprintf(file,cpf); //fprintf salva o valor da variável (no caso, o cpf no arquivo)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //função para abrir o arquivo já salvo (a = atualizar)
	fprintf(file, "\n\tNome: "); //função que escreve adiciona algo dentro do arquivo 
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
	
	system("cls"); // reponsável por limpar a tela
	
	printf("\n");
	printf("    +---------------------- Registro de Usuário ----------------------+ \n"); 
	printf("    ¦                                                                 ¦\n"); 
	printf("    ¦                Deseja Realizar um Novo Registro?                ¦\n"); 
	printf("    ¦                                                                 ¦\n"); 
	printf("    ¦                     1 = SIM         2 = NÃO                     ¦\n"); 
	printf("    ¦                                                                 ¦\n"); 
	printf("    +-----------------------------------------------------------------+\n\n\n");
	printf("Opção: ");
		
	getchar(); //função que lê a entrada do usuário através de caracteres
	
	char opcao; //criando a variável de nome "opção"
	opcao = getchar(); //definindo que "opção" é a escolha o usuário
	
	system("cls");
	
	if (opcao == '1') //se a condição for verdadeira, faça isso
	{	
		registro(); //voltar ao menu "Registros"
	}
	
	else if (opcao == '2') // senão, faça isso
	{
		//apenas voltar ao menu principal
	}
	
	else //se não for nenhum dos dois, faça isso
	{
		printf("\n"); 
		printf("    +------------------- Registro de Usuário -------------------+ \n"); 
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦                      Opção Inválida.                      ¦\n"); 
		printf("    ¦                     Tente Novamente!!                     ¦\n"); 
		printf("    ¦                                                           ¦\n");
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦ Esse Software foi desenvolvido por Heitor B.®             ¦\n"); 
		printf("    +-----------------------------------------------------------+\n\n\n");
		system("pause");
	}

}

int consulta()// criando função de nome "consulta" para consultar registros
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("        Consulta de Registro      \n\n\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser Consultado: "); //recebendo dado a ser consultado
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r"); //função para abrir e ler o arquivo já salvo (r = read)
	
	
	if(file == NULL) // "if" -> funcção "se" = "if" se sim / "while" se não.. "file == NULL" -> se o arquivo não for localizado
	{
		printf("\n"); 
		printf("    +------------------ Consulta de Registros  ------------------+ \n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                    CPF: ");
		printf("%s                     ¦\n", cpf);
		printf("    ¦                                                            ¦\n");
		printf("    ¦                     Não Localizado.                        ¦\n");
		printf("    ¦                    Tente Novamente!!                       ¦\n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                                                            ¦\n");
		printf("    ¦                                                            ¦\n");
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦ Esse Software foi desenvolvido por Heitor B.®              ¦\n"); 
		printf("    +------------------------------------------------------------+\n\n\n"); 
	}
	
	
	while(fgets(conteudo, 200, file) != NULL) // "fgets" = buscar no banco de dados todos os dados do arquivo "!= NULL" até o final do arquivo
	{
		printf("%s", conteudo); //imprimir na tela informações do arquivo em questão
	}

	printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.®\n\n\n");
	system("pause");
	system("cls");
	
	printf("\n");
	printf("    +--------------------- Consulta de Registros  ---------------------+ \n"); 
	printf("    ¦                                                                  ¦\n"); 
	printf("    ¦                Deseja Consultar um Novo Registro?                ¦\n"); 
	printf("    ¦                                                                  ¦\n"); 
	printf("    ¦                      1 = SIM         2 = NÃO                     ¦\n"); 
	printf("    ¦                                                                  ¦\n"); 
	printf("    +------------------------------------------------------------------+\n\n\n");
	printf("Opção: ");
	
	
	getchar(); //função que lê a entrada do usuário através de caracteres
	
	char opcao; //criando a variável de nome "opção"
	opcao = getchar(); //definindo que "opção" é a escolha o usuário
	
	system("cls");
	
	if (opcao == '1') //se a condição for verdadeira, faça isso
	{	
		consulta(); //voltar ao menu "Consulta"
	}
	
	else if (opcao == '2') // senão, faça isso
	{
		//apenas voltar ao menu principal
	}
	
	else //se não for nenhum dos dois, faça isso
	{
		printf("\n"); 
		printf("    +------------------ Consulta de Registros  ------------------+ \n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                      Opção Inválida.                       ¦\n"); 
		printf("    ¦                     Tente Novamente!!                      ¦\n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                                                            ¦\n");
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦ Esse Software foi desenvolvido por Heitor B.®              ¦\n"); 
		printf("    +------------------------------------------------------------+\n\n\n"); 
		
		system("pause");
	}
	
	fclose(file);

}

int exclusao()// variável "int" de nome "exclusão" = Função responsável pela exclusão de registros
{
	setlocale(LC_ALL, "Portuguese"); //definindo biblioteca de linguagem 
	
	char cpf[40];
	
	printf("        Exclusão de Registro      \n\n\n");
	printf("Digite o CPF a ser Exlcuído: "); //recebendo dados a serem excluídos
	scanf("%s", cpf);
		
	FILE *file; //abrindo pasta onde se localiza o arquivo 
	file = fopen(cpf,"r"); //lendo banco de dados para validar dados inseridos pelo usuário
	fclose(file);
	
	system("cls");
	
	if (file == NULL) //se não for encontrado
	{
		printf("\n"); 
		printf("    +------------------- Exclusão de Registro -------------------+ \n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                    CPF: ");
		printf("%s                     ¦\n", cpf);
		printf("    ¦                                                            ¦\n");
		printf("    ¦                      Não Localizado.                       ¦\n");
		printf("    ¦                     Tente Novamente!!                      ¦\n"); 
		printf("    ¦                                                            ¦\n");
		printf("    ¦                                                            ¦\n");
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦Esse Software foi desenvolvido por Heitor B.®               ¦\n"); 
		printf("    +------------------------------------------------------------+\n\n\n");
		system("pause");
		return 0; //comando para fazer o usuário retornar ao menu principal
	}
	
	printf("\n"); 
	printf("    +------------------- Exclusão de Registro -------------------+ \n"); 
	printf("    ¦                                                            ¦\n"); 
	printf("    ¦                                                            ¦\n"); 
	printf("    ¦                Deseja Excluir Este Registro?               ¦\n"); 
	printf("    ¦                    CPF: ");
	printf("%s                     ¦\n", cpf);
	printf("    ¦                                                            ¦\n");
	printf("    ¦                                                            ¦\n"); 
	printf("    ¦                   1 = SIM       2 = NÃO                    ¦\n"); //valudação da escolha do usuário para exclusão dos dados
	printf("    ¦                                                            ¦\n"); 
	printf("    ¦                                                            ¦\n"); 
	printf("    +------------------------------------------------------------+\n\n\n"); 
	printf("Opção: ");
	
	
	getchar(); //função que lê a entrada do usuário através de caracteres
	
	char opcao; //criando a variável opção
	opcao = getchar(); //definindo que "opção" = entrada de dados do usuário

	system("cls");
	
	if (opcao == '1') //se a "opção" for igual à 1, fazer isso
	{
	if (remove(cpf) == 0){ //excluir dados do registro solicitado, no caso "cpf"
	
		printf("\n"); 
		printf("    +------------------- Exclusão de Registro -------------------+ \n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                    CPF: ");
		printf("%s                     ¦\n", cpf);
		printf("    ¦                                                            ¦\n");
		printf("    ¦                   Deletado com Sucesso!!                   ¦\n"); 
		printf("    ¦                                                            ¦\n");
		printf("    ¦                                                            ¦\n");
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦                                                            ¦\n"); 
		printf("    ¦Esse Software foi desenvolvido por Heitor B.®               ¦\n"); 
		printf("    +------------------------------------------------------------+\n\n\n");
	
		system("pause");
	}
	}
	
	else if (opcao == '2') //se a opção for igual à 2
	{
		printf("\n"); 
		printf("    +------------------ Exclusão de Registro  ------------------+ \n"); 
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦                    Operação Cancelada!                    ¦\n"); 
		printf("    ¦         Pressione Qualquer Tecla para Continuar           ¦\n"); 
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦                                                           ¦\n");
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦ Esse Software foi desenvolvido por Heitor B.®             ¦\n"); 
		printf("    +-----------------------------------------------------------+\n\n\n"); 
		
		system("pause");
	}
	
	else //se for diferente das opções acima
	{
		printf("\n"); 
		printf("    +------------------ Exclusão de Registro  ------------------+ \n"); 
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦                     Opção Inválida.                       ¦\n"); 
		printf("    ¦                    Tente Novamente!!                      ¦\n"); 
		printf("    ¦                                                           ¦\n");
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦                                                           ¦\n"); 
		printf("    ¦ Esse Software foi desenvolvido por Heitor B.®             ¦\n"); 
		printf("    +-----------------------------------------------------------+\n\n\n"); 

		system("pause");
	}
	
}

int sobre()
{
	printf("\n");
    printf("    *================================ SOBRE ================================*\n");
    printf("    |                                                                       |\n");
    printf("    |                                                                       |\n");
    printf("    |                                                                       |\n");
    printf("    |                                                                       |\n");
    printf("    |                                                                       |\n");
    printf("    |                                                                       |\n");
    printf("    |                          IDENTIFICACAO                                |\n");
    printf("    |                                                                       |\n");
    printf("    |                                                                       |\n");
    printf("    |                                                                       |\n");
    printf("    |CURSO:                                                                 |\n");
    printf("    |PROFESSOR:                                                             |\n");
    printf("    |                                                                       |\n");
    printf("    |                                                                       |\n");
    printf("    =========================================================================\n");
    system("pause");
}

int main() //Função do menú, começo do programa
{
	setlocale(LC_ALL, "Portuguese"); //definindo biblioteca de linguagem 

	//Definindo variáveis
	int opcao=0; //variável "int" de nome "opção" com valor = 0
	int repeticao=1; //variável "int" de nome "repeticao" com valor =1
	char senhadigitada[]="a";
	int comparacao;
	
	printf("            Cartório da EBAC \n");
	printf("\n\n Login de Administrador \n\n Digite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	
	
	if(comparacao == 0)
	{
	
		for(repeticao=1;repeticao=1;) //criando laço de repetição - enquanto "repeticao" = 1, manter o processo
		{
		
			system("cls"); //comando de limpar a tela
	
			setlocale(LC_ALL, "Portuguese"); //definindo biblioteca de linguagem 

			printf("\n"); 
			printf("    +-------------------------- Cartório da EBAC  --------------------------+ \n"); //início do menu
			printf("    ¦                          Seja Bem-Vinda (o)!                          ¦\n"); 
			printf("    ¦                                                                       ¦\n"); 
			printf("    ¦                                                                       ¦\n"); 
			printf("    ¦                  Escolha a opção desejada no menu abaixo:             ¦\n"); 
			printf("    ¦                                                                       ¦\n"); 
			printf("    ¦                                                                       ¦\n"); 
			printf("    ¦\t1 - Registro de Usuários                                            ¦\n"); 
			printf("    ¦\t2 - Consultar Registros                                             ¦\n"); 
			printf("    ¦\t3 - Excluir Registro                                                ¦\n"); 
			printf("    ¦\t4 - Sobre                                                           ¦\n"); 
			printf("    ¦\t5 - Encerrar Programa                                               ¦\n"); 
			printf("    ¦                                                                       ¦\n"); 
			printf("    ¦                                                                       ¦\n");
			printf("    +-----------------------------------------------------------------------+\n\n"); 
			printf("Opção: "); //fim do menu
		
			scanf("%d", &opcao); //armazenamento da escolha do usuário
		
			system("cls");
		
			switch(opcao)
			{
				case 1:
				registro(); //chamada para a função registro
				break;
				
				case 2:
				consulta(); //chamada para a função consulta
				break;
			
				case 3:
				exclusao(); //chamada para a função exclusao
				break;
					
				case 4:
				sobre();
				break;
				
				case 5:
				printf("\n"); 
				printf("    +--------------------- Cartório da EBAC  ---------------------+ \n"); 
				printf("    ¦                                                             ¦\n"); 
				printf("    ¦                                                             ¦\n"); 
				printf("    ¦            Obrigado por utilizar esse sistema!!             ¦\n"); 
				printf("    ¦                                                             ¦\n");
				printf("    ¦                                                             ¦\n"); 
				printf("    ¦                                                             ¦\n"); 
				printf("    ¦                                                             ¦\n");
				printf("    ¦ Esse Software foi desenvolvido por Heitor B.®               ¦\n"); 
				printf("    +-------------------------------------------------------------+\n\n\n"); 
 	
				return 0; //chamada para quebrar o loopoing e encerrar	
						
				default: //se o usuário digitar uma opção inválida
				printf("\n"); 
				printf("    +------------------------- Cartório da EBAC  -------------------------+ \n"); 
				printf("    ¦                                                                     ¦\n"); 
				printf("    ¦                         Opção Inválida,                             ¦\n"); 
				printf("    ¦             Escolha apenas entre as opções disponíveis!             ¦\n"); 
				printf("    ¦                                                                     ¦\n"); 
				printf("    ¦                         Tente Novamente!!                           ¦\n"); 
				printf("    ¦                                                                     ¦\n"); 
				printf("    ¦                                                                     ¦\n"); 
				printf("    ¦                                                                     ¦\n");
				printf("    ¦                                                                     ¦\n");  
				printf("    ¦ Esse Software foi desenvolvido por Heitor B.®                       ¦\n"); 
				printf("    +---------------------------------------------------------------------+\n\n\n"); 
 				system("pause");
				break;
			}//fim da seleção	
		}
	} 
	
	else
	{
		system("cls");
		printf("\n"); 
		printf("    +--------------------- Cartório da EBAC  ---------------------+ \n"); 
		printf("    ¦                                                             ¦\n"); 
		printf("    ¦                       Senha Inválida                        ¦\n"); 
		printf("    ¦                      Tente Novamente!!                      ¦\n"); 
		printf("    ¦                                                             ¦\n"); 
		printf("    ¦                                                             ¦\n"); 
		printf("    ¦                                                             ¦\n"); 
		printf("    ¦                                                             ¦\n"); 
		printf("    ¦ Esse Software foi desenvolvido por Heitor B.®               ¦\n"); 
		printf("    +-------------------------------------------------------------+\n\n\n"); 
 		system("pause");
		system("cls");
		main();
	}
}
