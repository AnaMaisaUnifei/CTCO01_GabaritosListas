/* ----- Informações do projeto -----
- Disciplina: Algoritmos e Estruturas de Dados I (CTCO01)
- Prof.ª Elisa de Cassia Silva Rodrigues
- Tarefa: Lista 5 - TAD Dados de Hanoi
- Instituição: Universidade Federal de Itajubá (UNIFEI)
- Curso: Ciência da Computação
- Feita por Ana Maísa do Nascimento Santos, Monitora da Disciplina
*/

// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hanoi.h"

/*=====Definição das extruturas de dados=====*/

// definição do struct dado
typedef struct dado{
  char caractere;
  int ordem;
}Dado;

// definição do struct elemento
typedef struct elemento{
  Dado letra;
  struct elemento *prox;
}Elemento;
/*===========================================*/

/*=====Funções da TAD Pilha Encadeada=====*/

// função para alocar memória do tipo Pilha
Pilha* criar()
{
  Pilha *pi = (Pilha*) malloc(sizeof(Pilha));  

  // se a lista foi criada corretamente, indica que ela está vazia
  if(pi != NULL){
    *pi = NULL;
    //printf("criou");
  } 

  return pi;
}

// função para liberar memória
int liberar(Pilha *pi)
{
  if(pi == NULL){    
    return 0;
  }

  // libera todos os nós da pilha que foram alocados
  Elemento *no;
  while(*pi != NULL){
    no = *pi;
    *pi = (*pi)->prox;
    free(no);
  }

  // libera o ponteiro da pilha
  free(pi);

  return 1;  
}

// função para obter o tamanho da pilha
int tamanho_pilha(Pilha *pi)
{
  // a pilha não foi criada corretamente
  if(pi == NULL){
    return 0;
  }

  int cont = 0;
  Elemento *no = *pi;

  // acrescenta cont até acabar a lista
  while(no != NULL){
    cont++;
    no = no->prox;
  }

  return cont;
}

// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));  

  return no;
}

// função para inserir elemento no início da pilha (topo)
int empilhar(Pilha *pi, char letra, int ordem)
{
  // cria um elemento novo
  Elemento *no = criar_elemento();

  if(no == NULL){
    return 1;
  }

  // atribui valores ao elemento novo
  no->letra.caractere = letra;
  no->letra.ordem = ordem;
  no->prox = (*pi);

  // insere elemento no início da pilha (topo)
  *pi = no;

  return 0;
}

// função para remover elemento do início da pilha (topo)
int desempilhar(Pilha *pi)
{
  if(pi == NULL){
    return 0;
  }

  // pilha vazia, não remove nada
  if((*pi) == NULL){
    return 0;
  }

  // muda inicio para o proximo elemento
  Elemento *atual;
  atual = *pi;
  *pi = (*pi)->prox;

  // libera Elemento atual
  free(atual);

  return 1;
}

// função para consultar o primeiro elemento (topo)
int topo_pilha(Pilha *pi, char *letra){

  // verifica se a pilha foi criada corretamente e se não está vazia
  if(pi == NULL || *pi == NULL){
    return 0;
  }

  // copia o dado do topo da pilha (início da lista)
  *letra = (*pi)->letra.caractere;

  return 1;
}
/*===========================================*/

/*===Funções para execução dos Tubos de Dados de Hanoi====*/

// Mostrar os tubos na tela
void mostrar_tubos(Pilha *p1, Pilha *p2, Pilha *p3){

  printf("====== Tubos de Dados de Hanoi ======\n\n");
  printf("           1     2     3\n");
	Pilha p1aux;
	Pilha p2aux;
	Pilha p3aux;
	char pr1, pr2, pr3;

	for(int i = 0; i<5;i++){
		
		p1aux = *p1;
		p2aux = *p2;
		p3aux = *p3;
		
		if(p1aux != NULL )
			pr1 = (p1aux)->letra.caractere;
		else
			pr1 = ' ';

		if(p2aux != NULL )
			pr2 = (p2aux)->letra.caractere;
		else
			pr2 = ' ';

		if(p3aux != NULL )
			pr3 = (p3aux)->letra.caractere;
		else
			pr3 = ' ';
		
		
		for(int j = 0; j <(5-i-1);j++){

			if(p1aux != NULL ){
				p1aux = (p1aux)->prox;
				if(p1aux == NULL )
					pr1 = ' '; 
			else
				pr1 = (p1aux)->letra.caractere;
			}
		
		if(p2aux != NULL){
			p2aux = (p2aux)->prox;
			if(p2aux == NULL )
				pr2 = ' ';
			else
				pr2 = (p2aux)->letra.caractere;
		}
		
		

		if(p3aux != NULL){
			p3aux = (p3aux)->prox;
			if(p3aux == NULL )
				pr3 = ' ';
			else
				pr3 = (p3aux)->letra.caractere;
		}
		
		

		} 
      
			printf("          |%c|   |%c|   |%c|   \n",pr1,pr2,pr3);

		
	}		
  printf("          / /   / /   / /\n");  printf("\n");
  printf("=====================================\n\n");

}

//Função para tirar da pilha
int tirar(Pilha *pi, int *ordem, char *letra){

  if(pi == NULL){
     printf("Escolha uma torre com cubos!");
    return 1;
  }

  *letra = (*pi)->letra.caractere;
  *ordem = (*pi)->letra.ordem;

  desempilhar(pi);

  return 0;
}

//Função para colocar em uma pilha
int colocar(Pilha *pi, int *ordem, char *letra){

  if((*pi) != NULL && *ordem < (*pi)->letra.ordem){
    printf("A letra não pode ser inserida nesse tubo pois não corresponde a ordem alfabética.");
    return 1;
  }
          	
  empilhar(pi, *letra, *ordem);
  return 0;

}
