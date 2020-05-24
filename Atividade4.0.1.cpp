#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

struct disciplina{
	int CodigoD;
	char NomeD;
	struct disciplina *proximo;
}Disciplina;
struct disciplina *head = NULL;
struct disciplina *atual = NULL;

struct aluno{
	char NomeA;
	int CodigoA;
	struct aluno *PROXIMO;
};
struct aluno *Head = NULL;
struct aluno *Atual = NULL;

CadastraDisciplina(int CodigoD,char NomeD){
 struct disciplina *nodo = (struct disciplina*) malloc(sizeof(struct disciplina));
 
 nodo->CodigoD = CodigoD;
 nodo-> NomeD = NomeD;
 //aponta para o nó antigo
 nodo->proximo = head;
 //aponta para o novo nó
 head = nodo;
}

int CadastraAluno(int CodigoA, char NomeA, char NomeD){
 
}

LancaNota(int CodigoA){

}

struct aluno* AlteraNota(int CodigoA){

}

struct aluno* relatorio(int CodigoA){
	
}
 			

int main(){
	int  aux_codigo;
	char repet, opcao,aux_nome;
	
	setlocale(LC_ALL, "portuguese");
	
	do{
		system ("cls");
		
		printf("1- Cadastra Disciplina\n");
		printf("2- Cadastra estudante\n");
		printf("3- Lançar Nota\n");
		printf("4- Altera Nota\n");
		printf("5- Relatorio\n");
		printf("6- Sair do programa\n\n");
		printf("escolha a opção: "); scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				 	do{
				 	//Entrada de Dados da disciplina
				 		system("cls");
						printf("\nDigite o codigo da disciplina: "); 
						scanf("%d",&aux_codigo); 
						fflush(stdin);
						printf("Insira o Nome da disciplina:");
						scanf("%s", &aux_nome);
						CadastraDisciplina(aux_codigo, aux_nome);
						printf("\n");
					//confirmação da diciplina				
						printf("\nCodigo: %d", aux_codigo);
						printf("\nNome da Disciplina: %s", &aux_nome);
						printf("\n\nAs opções estão corretas?\n\n"); system("pause");
					//repertição de inserir diciplina	
						printf("Deseja Reperti? S(SIM)/N(NÃo):"); 
						scanf("%s", &repet); 
						repet = toupper(repet);
					}while(repet=='S'); 
					
			break;
			case 2:
				 	
			break;
			case 3:
			 
			break;
			case 4:
		
			break;
			case 5:
			 		
			break;
			case 6: 
					return 0;
			break;
			default: printf("Opção Invalida...");
		}
		do{
			system("cls");
			printf("Deseja tentar novamente? S(SIM)/N(NÃo):"); 
			scanf("%s", &repet); 
			repet = toupper(repet);	
		}while(repet!='S'&& repet!='N');
	}while(repet=='S');
}
