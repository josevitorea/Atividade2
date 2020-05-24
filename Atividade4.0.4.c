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
	char materia;
	struct aluno *PROXIMO;
};
struct aluno *Head = NULL;
struct aluno *Atual = NULL;

CadastraDisciplina(int CodigoD,char NomeD){
 struct disciplina *nodo = (struct disciplina*) malloc(sizeof(struct disciplina));
 
 nodo->CodigoD = CodigoD;
 nodo-> NomeD = NomeD;
 nodo->proximo = head;
 head = nodo;
}

int CadastraAluno(int CodigoA, char NomeA, char materia){
 struct aluno *Nodo = (struct aluno*) malloc(sizeof(struct aluno));
 struct disciplina *nodo = (struct disciplina*) malloc(sizeof(struct disciplina));
 
 struct aluno* Atual = Head;
 struct aluno* anterior = NULL;
 
 struct disciplina* atual = head;
 struct disciplina* Anterior = NULL;
 
 Nodo->CodigoA = CodigoA;
 Nodo-> NomeA = NomeA;
 
 if(head == NULL){
 		printf("A materia n�o esta cadastrada"); return 0;
 	}
	while (atual->NomeD!=nodo->NomeD){
		if(atual->proximo == NULL){
			printf("A materia n�o esta cadastrada"); return 0;
		} else{
			atual = atual->proximo;
		}
	}
	if(atual == head){
        Nodo-> materia = nodo-> NomeD;
    }
    else{    
        Anterior ->proximo = atual -> proximo;
    }
 Nodo->PROXIMO = Head;
 Head = Nodo;
}

struct aluno* LancaNota(int CodigoA){

}

struct aluno* AlteraNota(int CodigoA){

}

struct aluno* relatorio(int CodigoA){
 struct aluno* Atual = Head;
	
	if(Head == NULL){
 			printf("O Aluno n�o esta cadastrada"); return;
 	}

	while (Atual->CodigoA!=CodigoA){
		if(Atual->PROXIMO == NULL){
			printf("O Aluno n�o esta cadastrada"); return;
		} else{
			Atual = Atual->PROXIMO;
		}
	}
	return Atual;
}

struct aluno* VisualizaLista (void)
{
 struct disciplina *nodo = (struct disciplina*) malloc(sizeof(struct disciplina));
 
 struct aluno* Atual = Head;
 struct aluno* anterior = NULL;
 
 struct disciplina* atual = head;
 struct disciplina* Anterior = NULL;
 
 	struct aluno *Nodo, *Head;
 		if (Nodo->NomeA){
 			fprintf (stderr, "Fila est� vazia\n");
 			return;
 		}
 		printf("Fila: \n");
 		Head = Nodo = Nodo -> NomeA;
 		int i = 1;
 		do {
 			printf ("%s <-- ", Nodo -> NomeA);
 			Nodo = Nodo -> PROXIMO;
 			i++;
 		} while (Nodo != Head);
}
 			

int main(){
	int  aux_codigo, aux_codigoA, busc_codigo;
	char repet, opcao,aux_nome, aux_nomeA;
	
	setlocale(LC_ALL, "portuguese");
	
	do{
		system ("cls");
		
		printf("1- Cadastra Disciplina\n");
		printf("2- Cadastra estudante\n");
		printf("3- Lan�ar Nota\n");
		printf("4- Altera Nota\n");
		printf("5- Relatorio\n");
		printf("6- Visualizar lista");
		printf("7- Sair do programa\n\n");
		printf("escolha a op��o: "); scanf("%d", &opcao);
		
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
					//confirma��o da diciplina				
						printf("\nCodigo: %d", aux_codigo);
						printf("\nNome da Disciplina: %s", &aux_nome);
						printf("\n\nAs op��es est�o corretas?\n\n"); system("pause");
					//reperti��o de inserir diciplina	
						printf("Deseja Reperti? S(SIM)/N(N�o):"); 
						scanf("%s", &repet); 
						repet = toupper(repet);
					}while(repet=='S'); 
					
			break;
			case 2:
				 	do{
				 	//Entrada de Dados do Aluno	
				 		system("cls");
						printf("\nDigite o codigo do Aluno: "); 
						scanf("%d",&aux_codigoA); 
						fflush(stdin);
						printf("Insira o Nome do aluno:");
						scanf("%s", &aux_nomeA);
						printf("Insira o Nome da disciplina:");
						scanf("%s", &aux_nome);
						CadastraAluno(aux_codigoA, aux_nomeA, aux_nome);
						printf("\n");
					//confirma��o do Aluno				
						printf("\nCodigo do Aluno: %d", aux_codigoA);
						printf("\nNome do Aluno: %s", &aux_nomeA);
						printf("\n\nAs op��es est�o corretas?\n\n"); system("pause");
					//reperti��o de inserir o ALuno
						printf("Deseja Reperti? S(SIM)/N(N�o):"); 
						scanf("%s", &repet); 
						repet = toupper(repet);
					}while(repet=='S'); 
			break;
			case 3:
			 
			break;
			case 4:
		
			break;
			case 5:
			 		printf("\n Digite o id do elemento procurado ");
			 		scanf("%d",&busc_codigo);
			 		struct aluno* resultadoBusca = relatorio(busc_codigo);
  					printf("\n Codigo: %d ", resultadoBusca -> CodigoA);
  					printf("\n Nome do Aluno: %s ", resultadoBusca -> NomeA);
			break;
			case 6:
					VisualizaLista();
			break;
			case 7: 
					return 0;
			break;
			default: printf("Op��o Invalida...");
		}
		do{
			system("cls");
			printf("Deseja tentar novamente? S(SIM)/N(N�o):"); 
			scanf("%s", &repet); 
			repet = toupper(repet);	
		}while(repet!='S'&& repet!='N');
	}while(repet=='S');
}

