/* ----- Informações do projeto -----
- Disciplina: Algoritmos e Estruturas de Dados I (CTCO01)
- Prof.ª Elisa de Cassia Silva Rodrigues
- Tarefa: Lista 3 - TAD Números Complexos
- Instituição: Universidade Federal de Itajubá (UNIFEI)
- Curso: Ciência da Computação
- Feita por Ana Maísa do Nascimento Santos, Monitora da Disciplina
*/

#include <stdio.h>
#include <stdlib.h>
#include "complexos.h"

/*Struct de um número complexo*/
typedef struct n_Complexo{
    float a;
    float b;
}num_complexo;

int main(void) {

	num_complexo *complexos; /*Variável que armazena os 2 números complexos digitados*/

  num_complexo res_soma; /*Variável que armazena o resultado da soma dos complexos digitados*/

  num_complexo res_sub; /*Variável que armazena o resultado da subtração dos complexos digitados*/

  num_complexo res_div; /*Variável que armazena o resultado da divisão dos complexos digitados*/
  
  num_complexo res_mult; /*Variável que armazena o resultado da multiplicação dos complexos digitados*/

  /*Criação dos espaços de memória dos 2 números complexos*/
  complexos = criar_n();

  /*Entrada dos números complexos pelo usuário*/
  printf("Olá! Este programa realiza as 4 operações fundamentais da matemática em Números complexos. Os números complexos são da forma z = ax + bi, onde a e b serão valores digitados por você! Para prosseguir, pediremos a e b para 2 números complexos.");

  printf("\n\nDigite a e b para o 1º Número Complexo: ");
  scanf("%f %f", &complexos[0].a, &complexos[0].b);

	printf("Digite a e b para o 2º Número Complexo: ");
  scanf("%f %f", &complexos[1].a, &complexos[1].b);

  /*Limpeza do terminal*/
  system("clear");

  /*Chamadas das funções das operações*/
  /*Soma*/
	res_soma = somar_complexo(complexos);

  /*Subtração*/
	res_sub = sub_complexo(complexos);

  /*Divisão*/
	res_div = div_complexo(complexos);
  
  /*Multiplicação*/
	res_mult = mult_complexo(complexos);

  printf("Segue os resultados das operações com os valores digitados:\n ");

  /*Verificando se o b da soma é positivo ou negativo para exibir a forma corretamente --> exibição do número*/
 	if (res_soma.b > 0) {
 		printf("\nSoma: %.1f + %.1fi\n",res_soma.a , res_soma.b);
  }
	else {
		printf("\nSoma: %.1f  %.1fi\n",res_soma.a , res_soma.b);
  } 
  
  /*Verificando se o b da subtração é positivo ou negativo para exibir a forma corretamente --> exibição do número*/
	if (res_sub.b > 0) {
	  printf("\nSubtração: %.1f + %.1fi\n", res_sub.a, res_sub.b);
  }
  else {
    printf("\nSubtração: %.1f %.1fi\n", res_sub.a, res_sub.b);
  }
  
  /*Verificando se o b da multiplicação é positivo ou negativo para exibir a forma corretamente --> exibição do número*/
  if(res_mult.b >0) {
	printf("\nMultiplicação: %.1f + %.1fi\n",res_mult.a , res_mult.b);
	}
	else  {
	printf("\nMultiplicação: %.1f  %.1fi\n",res_mult.a , res_mult.b);	
	}

  /*Verificando se o b da divisão é positivo ou negativo para exibir a forma corretamente --> exibição do número*/
  if (res_div.b > 0) {
    printf("\nDivisão: %.2f + %.2fi\n",res_div.a , res_div.b);
  }
  else {
    printf("\nDivisão: %.2f  %.2fi\n",res_div.a , res_div.b);
  }

  /*Liberação da alocação dinâmica da memória*/
	lib_memoria(complexos);

  return 0;
}
