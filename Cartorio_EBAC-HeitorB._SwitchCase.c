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
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char telefone[40];
	//final da criação de variáveis/strings
	

	

	printf("        Registro de Usuários      \n\n\n");
	
	printf("Digite o CPF: "); // printf é a função responsável pela exibição na tela
	scanf("%s", cpf); //função que lê o dado digitado pelo usuário
	
	strcpy(arquivo, cpf); //função Responsável por copiar o valor das strings
	
	FILE *file; //função que cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria um novo arquivo (w = write)
	fprintf(file,"\nEssas são as Informações do Usuário:\n\n");
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
	
	printf("        Registro de Usuários      \n\n\n");	
	printf("Deseja Realizar um Novo Registro? \n");
	printf("\n\n    1 = SIM      2 = NÃO\n\n");
	printf("Opção: ");
	
	
	getchar(); //função que lê a entrada do usuário através de caracteres
	
	char opcao; //criando a variável opção
	opcao = getchar();
	
	system("cls");
	
	if (opcao == '1') //se a condição for verdadeira, faça isso
	{	
		registro();
	}
	
	else if (opcao == '2') // senão, faça isso
	{
		//apenas voltar ao menu principal
	}
	
	else //se não for nenhum dos dois, faça isso
	{
		printf("        Registro de Usuários      \n\n\n");
		printf("           Opção Inválida.\n");
		printf("          Tente Novamente!");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.®\n\n\n");
		
		system("pause");
	}

}

int consulta()//função para consultar registros
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
	file = fopen(cpf,"r"); //função para abrir o arquivo já salvo (r = read)
	
	
	if(file == NULL) // se o arquivo não for localizado
	{
		printf("\n\tCPF Não Localizado!  \n");
		printf("          Tente Novamente!");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL) //imprimir na tela todos os dados do arquivo
	{
		printf("%s", conteudo);
	}
	
	printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.®\n\n\n");

	fclose(file);
	system("pause");
}

int exclusao()//Função responsável pela exclusão de registros
{
	char cpf[40];
	
	printf("        Exclusão de Registro      \n\n\n");
	printf("Digite o CPF a ser Exlcuído: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	system("cls");
	
	if (file == NULL)
	{
		printf("        Exclusão de Registro      \n\n\n");
		printf("\tCPF: ");
		printf("%s",cpf);
		printf("\n\nNão Encontrado. Tente Novamente!!");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.®\n\n\n");
		system("pause");
		return 0; //comando para fazer o usuário retornar ao menu principal
	}
		
	printf("        Exclusão de Registro      \n\n\n");	
	printf("Deseja Excluir este Registro? \n");
	printf("\tCPF: ");
	printf("%s", cpf);
	printf("\n\n    1 = SIM      2 = NÃO\n\n");
	printf("Opção: ");
	
	
	getchar(); //função que lê a entrada do usuário através de caracteres
	
	char opcao; //criando a variável opção
	opcao = getchar();
	
	system("cls");
	
	if (opcao == '1')
	{
	if (remove(cpf) == 0){
	
		printf("        Exclusão de Registro      \n\n\n");	
		printf("\tCPF: ");
		printf("%s", cpf);
		printf("\n  Deletado com Sucesso!");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.®\n\n\n");
	}
		system("pause");
	}
	
	else if (opcao == '2')
	{
		printf("        Exclusão de Registro      \n\n\n");
		printf("         Operação Cancelada!");
		printf("\nPressione Qualquer Tecla para Continuar.");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.®\n\n\n");
		
		system("pause");
	}
	
	else
	{
		printf("        Exclusão de Registro      \n\n\n");
		printf("           Opção Inválida.\n");
		printf("          Tente Novamente!");
		printf("\n\n\n\nEsse Software foi desenvolvido por Heitor B.®\n\n\n");
		
		system("pause");
	}
	
}

int main() //Função do menú, começo do programa
{
	int opcao=0; //Definindo Variáveis
	int repeticao=1;
	
	for(repeticao=1;repeticao=1;)
	{
		
		system("cls"); //comando de limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo biblioteca de linguagem 

		printf("            Cartório da EBAC \n"); //início do menu
		printf("           Seja Bem-Vinda (o)!\n\n\n");
		printf("Escolha a opção desejada no menu abaixo:\n\n");
		printf("\t1 - Registrar Alunos\n");
		printf("\t2 - Consultar Registros de Alunos\n");
		printf("\t3 - Deletar Registro de Aluno\n");
		printf("\t4 - Encerrar Programa\n\n\n");
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
			printf("Obrigado por utilizar o sistema!!");
			printf("\n\n\nEsse Software foi desenvolvido por Heitor B.®\n\n\n");
			return 0; //chamada para quebrar o loopoing e encerrar
			break;
				
						
			default:
			printf("            Cartório da EBAC \n\n\n");
			printf("\tOpção Indisponível,");
			printf("\nEscolha apenas entre as opções 1, 2 ou 3!");
			printf("\n\n         Tente Novamente!!");
			printf("\n\n\nEsse Software foi desenvolvido por Heitor B.®\n\n\n");
			system("pause");
			break;
		}
		
		
		
		} //fim da seleção
	
	
	}
