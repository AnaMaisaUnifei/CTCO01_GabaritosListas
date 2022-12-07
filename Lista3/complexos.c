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

/*Função de alocação do espaço de memória para os 2 números complexos a serem usados*/
num_complexo *criar_n (){

	num_complexo *complexo;
	
	complexo = (num_complexo*) malloc(2 * sizeof(num_complexo));

  return complexo;
}

/*Liberação da memória alocada na função criar_n*/
void lib_memoria (num_complexo *complexo){

	free(complexo);

  return;
}

/*Função que efetua a soma dos números complexos digitados*/
num_complexo somar_complexo (num_complexo *complexo){
  num_complexo soma;
   
	soma.a = complexo[0].a+complexo[1].a;
	soma.b = complexo[0].b+complexo[1].b;
	
  return soma;
}

/*Função que efetua a subtração dos números complexos digitados*/
num_complexo sub_complexo (num_complexo *complexo){
  num_complexo subtracao;

  subtracao.a = complexo[0].a-complexo[1].a; 
	subtracao.b = complexo[0].b-complexo[1].b;

  return subtracao;
}

/*Função que efetua a multiplicação dos números complexos digitados*/
num_complexo mult_complexo (num_complexo *complexo){
	num_complexo multiplicacao;
	
	multiplicacao.a = complexo[0].a*complexo[1].a - complexo[0].b*complexo[1].b;	
	multiplicacao.b = complexo[0].b*complexo[1].a + complexo[0].a*complexo[1].b;
  
  
	return multiplicacao;
}

/*Função que efetua a divisão dos números complexos digitados*/
num_complexo div_complexo(num_complexo *complexo){
  num_complexo divisao;

  divisao.a = ((complexo[0].a * complexo[1].a) + (complexo[0].b * complexo[1].b)) / ((complexo[1].a*complexo[1].a)+(complexo[1].b*complexo[1].b));
  
  divisao.b = ((complexo[0].b * complexo[1].a) - (complexo[0].a * complexo[1].b)) / ((complexo[1].a*complexo[1].a)+(complexo[1].b*complexo[1].b));
	
  return divisao;
}