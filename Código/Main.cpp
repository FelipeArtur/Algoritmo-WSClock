#include "BliBlio_WSClock.h"
//Equipe: Equipe: Guilherme Marinho, Felipe Lima
//fun��es para printa das escolhas, tela inicial, e tela final
	void printar_opcaos(){
		printf("Escolha uma opcaoao:\n(R) Referencia��o de P�gina \n(S) P�gina a ser Substitu�da \n(W) T�rmino do per�odo de trabalho\n(E) Exibi��o da Lista Circular com Atributos das P�ginas\n(F) Fim da simulacao\n");
	}
	void printar_tela_final(){
		printf("Trabalho feito\n");
	}
	void print_tela_inicial(){
		printf("Trabalho de WSClock\nEquipe: Guilherme Martinho e Felipe Lima\n");
	}
	
int main(){
	//fun��o para poder escrever acentos da lingua portuguesa
	setlocale(LC_ALL, "Portuguese");

	
	Clock c;
	//Cria��o de variaveis que vou utilizar na main
	unsigned int x, numero_paginas, tempo_Ref;
	//Inicilizei a lista encadeada CLock
	inicializar_Clock(&c);
	//Printando a tela inicial
	print_tela_inicial();
	//Fun��es de pausar a tela e limpar ela dps de ler a mensagem inicial
	system("pause");
	system("cls");
	//Pede a quantidade de frames que vai fazer para passar como parametro para fun��o de inserir_pagina
	printf("Escreva a quantidade de frames que voce deseja(A quantidade preceisa ser maior do que 1): ");
	scanf(" %d", &numero_paginas);
	//loop para repetir a inser��o de frames na pagina ate a quantidade de frames escolhida seja cumprida
	for (x = 0; x < numero_paginas; x++){
	
		printf("Digite o tempo desejado:");
		scanf("%d",&tempo_Ref);
		inserir_pagina(&c, x, tempo_Ref);
	}
	//variaveis auxiliares para o uso do switch case
	unsigned int auxiliar1;
	char opcao;
		//Switch case da tela de op��o onde recebe a op��o escolhida 
		while (true)
	{
		//Chama a fun��o de printar op��es
		printar_opcaos();
		scanf(" %c", &opcao);
		//Se a op��o digitada for R  ele entra nesse if e realizar a refrencia de pagina
		if (opcao == 'R')
		{
			printf(" Referencia��o de P�gina:");
				printf("Digite a pagina (numero de 0 a %d): ", numero_paginas - 1);
				scanf(" %d", &auxiliar1);
				referenciar_pag(&c, auxiliar1);
				printf("Pagina %d referenciada\n", auxiliar1);
		}
		//Se a op��o digitada for S  ele entra nesse else if e realizar a Substitui��o de pagina
		else if (opcao == 'S')
		{
			printf("P�gina a ser Substitu�da:");
			substituir_pagina(&c);
		}
		//Se a op��o digitada for W  ele entra nesse else if ele mostra o termino do periodo de trabalho
		else if (opcao == 'W')
		{
			printf("T�rmino do per�odo de trabalho:");
			printf("achar_tempo atual: %d\n", tempo);
		}
		//Se a op��o digitada for E  ele entra nesse else if ele printa a lista circular com todos os atributos da pagina
		else if (opcao == 'E')
		{
			printf("Exibicao da lista circular com atributos das paginas ");
			printar_Clock(c);
		}
		//Se a op��o digitada for F  ele entra nesse else if ele finiliza o codigo e sai do switch case
		else if (opcao == 'F')
		
			break;
		else{
			//Caso a pessoa digite uma op��o incorreta ele exibe essa mensagem de erro e volta pra tela de escolher a op��o
			printf("Erro\Op��o digitada n�o existe!!!\n");
		}
		system("pause");
		printf("**********************************************\n");
	}
	//Limpa a tela e printa a tela final
	system("cls");
	printar_tela_final();
	return 0;
}
