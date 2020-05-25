#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

int i,aux_ind;
float avaliacao[3], soma, media;

struct disciplina{
	int CodigoD;
	char NomeD[20];
	struct disciplina *proximo;
}Disciplina;
struct disciplina *head = NULL;
struct disciplina *atual = NULL;

struct aluno{
	char NomeA[20];
	int CodigoA;
	char materia;
	float nota[3];
	struct disciplina;
	struct aluno *PROXIMO;
};
struct aluno *Head = NULL;
struct aluno *Atual = NULL;

CadastraDisciplina(int CodigoD,char NomeD){
 struct disciplina *nodo = (struct disciplina*) malloc(sizeof(struct disciplina));
 
 nodo->CodigoD = CodigoD;
 for(i=0;i<=19;i++){
 	nodo-> NomeD[i]= NomeD;
 };
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
 for(i=0;i<=19;i++){
 	Nodo-> NomeA[i]= NomeA;
 };
 
 if(head == NULL){
 		printf("A materia não esta cadastrada"); return 0;
 	}
	while (atual->NomeD!=nodo->NomeD){
		if(atual->proximo == NULL){
		 return;
		} else{
			atual = atual->proximo;
		}
	}
	if(atual == head){
        Nodo-> materia = nodo-> NomeD[i];
    }
    else{    
        Anterior ->proximo = atual -> proximo;
    }
 Nodo->PROXIMO = Head;
 Head = Nodo;
}

struct aluno* LancaNota(int CodigoA){
	int aux_aval;
	
 struct aluno *Nodo = (struct aluno*) malloc(sizeof(struct aluno));
 struct disciplina *nodo = (struct disciplina*) malloc(sizeof(struct disciplina));
 
 struct aluno* Atual = Head;
 struct aluno* anterior = NULL;
 
 struct disciplina* atual = head;
 struct disciplina* Anterior = NULL;
	
	if(Head == NULL){
 			printf("O Aluno não esta cadastrada"); return;
 	}

	while (Atual->CodigoA!=CodigoA){
		while (Atual->CodigoA!=CodigoA){
			if(Atual->PROXIMO == NULL){
				 return;
			} else{
				for ( i = 0 ; i < 2 ; i++){
 					printf("%d Avaliação: ", i+1);
 					scanf("%f", &avaliacao[i]);
 					Nodo->nota[i]=avaliacao[i];
 					soma=soma+avaliacao[i];
				}
			}
		}
	}
	media=soma/3;
}
				
int conceito(float media){
	if(media==10 || media>=8.5){
		printf("A");
	} else if(media<=8.4||media>=7.0){ 
		printf("B");
	} else if (media<=6.9 || media>=6.0) {
		printf("C");
	} else if (media<=5.9 ||media==4){
		printf("D");
	} else if (media<=3.9||media==0){
		printf("F");
	}
}

struct aluno* AlteraNota(int CodigoA){
	float nota_troca, busc_codigo;
	
 struct aluno *Nodo = (struct aluno*) malloc(sizeof(struct aluno));
 struct disciplina *nodo = (struct disciplina*) malloc(sizeof(struct disciplina));
 
 struct aluno* Atual = Head;
 struct aluno* anterior = NULL;
 
 struct disciplina* atual = head;
 struct disciplina* Anterior = NULL;
	
	if(Head == NULL){
 			printf("O Aluno não esta cadastrada"); return;
 	}

	while (Atual->CodigoA!=CodigoA){
		while (Atual->CodigoA!=CodigoA){
			if(Atual->PROXIMO == NULL){
				 return;
			} else{
					printf("Digite o numero da avaliação:");
					scanf("%d", &aux_ind);
					for(i=0;i<=2;i++){
						if(i==aux_ind){
							printf("Insira a nova nota da avaliação:");
							scanf("%d", &nota_troca);
							Nodo->nota[i]=nota_troca;
						}
					}
				}
			}
		}
	}

struct aluno* relatorio(int CodigoA){
 struct aluno* Atual = Head;
	
	if(Head == NULL){
 			printf("O Aluno não esta cadastrada"); return;
 	}

	while (Atual->CodigoA!=CodigoA){
		if(Atual->PROXIMO == NULL){
			 return;
		} else{
			Atual = Atual->PROXIMO;
		}
	}
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
 			fprintf (stderr, "Lista Vazia\n");
 			return;
 		}
 		printf("Lista: \n");
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
	float media, aux_aval;
	
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
					//confirmação do Aluno				
						printf("\nCodigo do Aluno: %d", aux_codigoA);
						printf("\nNome do Aluno: %s", &aux_nomeA);
						printf("\n\nAs opções estão corretas?\n\n"); system("pause");
					//repertição de inserir o ALuno
						printf("Deseja Reperti? S(SIM)/N(NÃo):"); 
						scanf("%s", &repet); 
						repet = toupper(repet);
					}while(repet=='S'); 
			break;
			case 3:
					printf("\n Digite o codigo do Aluno ");
			 		scanf("%d",&busc_codigo);
			 		LancaNota(media);
			break;
			case 4:
					printf("\n Digite o codigo do Aluno ");
			 		scanf("%d",&busc_codigo);
					AlteraNota(aux_aval);
			break;
			case 5:
			 		printf("\n Digite o codigo do Aluno ");
			 		scanf("%d",&busc_codigo);
			 		struct aluno* resultadoBusca = relatorio(busc_codigo);
  					printf("\n Codigo: %d ", resultadoBusca -> CodigoA);
  					printf("\n Nome do Aluno: %s ", resultadoBusca -> NomeA[i]);
  					printf("\n Nome da Disciplina: %s",resultadoBusca -> NomeD[i]);
  					printf("\n Aval 1: %f", resultadoBusca -> nota [0]);
  					printf("\n Aval 2: %f", resultadoBusca -> nota [1]);
  					printf("\n Aval 3: %f", resultadoBusca -> nota [2]);
  					printf("\n Media: %f", media);
  					conceito(media);
			break;
			case 6:
					VisualizaLista();
			break;
			case 7: 
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
