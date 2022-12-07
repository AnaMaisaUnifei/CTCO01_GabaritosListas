/* ----- Informações do projeto -----
- Disciplina: Algoritmos e Estruturas de Dados I (CTCO01)
- Prof.ª Elisa de Cassia Silva Rodrigues
- Tarefa: Lista 1 - Exercício 2 - Registro de Alunos
- Instituição: Universidade Federal de Itajubá (UNIFEI)
- Curso: Ciência da Computação
- Feita por Ana Maísa do Nascimento Santos, Monitora da Disciplina
*/

#include <stdio.h>
#include <stdlib.h>

/*Registro Struct ALUNO*/
typedef struct{
  int matricula;
  char nome[50];
  int dia_nasc;
  int mes_nasc;
  int ano_nasc;
  float nota;
}ALUNO;

/*Protótipos das funções*/
ALUNO *alocacao(int n);
void cadastra_aluno(int indice, ALUNO *V);
void preenche_alunos(ALUNO *V, int n);
void i_alunos_ap(ALUNO *V, int n);
void imprime_aluno(int indice, ALUNO *V);

/*Função principal*/
int main(void) {

  //Declaração de variáveis
  int n, i;
  ALUNO *V;

  //Coleta da quantidade de alunos a serem cadastrados
  printf("Quantos alunos(as) deseja cadastrar? \n");
  scanf("%d", &n);

  //Chamada da função de alocação do vetor
  V = alocacao(n);

  //Chamada da função de preenchimento do vetor
  preenche_alunos(V, n);

  //Chamada da função de impressão dos alunos aprovados
  i_alunos_ap(V, n);

  //Limpeza da alocação do vetor
  free(V);

  return 0;
}


/*Função que aloca a memória dinamicamente para um vetor do tipo ALUNO*/
ALUNO *alocacao(int n){
  ALUNO *V;

  //Alocação dinâmica da memória utilizado o tipo ALUNO
  V = (ALUNO*) malloc(n*sizeof(ALUNO));

  return V;

}

/*Função para preencher o registro de um aluno*/
void cadastra_aluno(int indice, ALUNO *V){

  //Coleta da matrícula
  printf("Digite a matrícula do(a) aluno(a) %d: ", indice+1);
  scanf("%d", &V[indice].matricula);

  //Coleta do nome do aluno
  printf("Digite o nome do(a) aluno(a) %d: ", indice+1);
  scanf(" %s", V[indice].nome);

  //Coleta do dia do nascimento do aluno
  printf("Digite o dia de nascimento do(a) aluno(a) %d: ", indice+1);
  scanf("%d", &V[indice].dia_nasc);

  //Coleta do mês de nascimento do aluno
  printf("Digite o mês de nascimento do(a) aluno(a) %d: ", indice+1);
  scanf("%d", &V[indice].mes_nasc);

  //Coleta do ano de nascimento do aluno
  printf("Digite o ano de nascimento do(a) aluno(a) %d: ", indice+1);
  scanf("%d", &V[indice].ano_nasc);

  //Coleta da nota do aluno
  printf("Digite a nota do(a) aluno(a) %d: ", indice+1);
  scanf("%f", &V[indice].nota);
}

/*Função para preencher o vetor de alunos*/
void preenche_alunos(ALUNO *V, int n){
  int i;

  //Percorrendo as posições do vetor para cadastrar os alunos
  for (i=0; i<n; i++){
    //Chamada da função de cadastro de um aluno
    cadastra_aluno(i, V);

    //Limpeza do terminal
    system("clear");
  }
}

/*Função para imprimir o registo de um aluno*/
void imprime_aluno(int indice, ALUNO *V){

  printf("Registro do aluno %d \n", indice+1);

  //Exibição das informações de um aluno
  printf("Matrícula: %d", V[indice].matricula);
  printf("\nNome: %s", V[indice].nome);
  printf("\nData de nascimento: %d/%d/%d", V[indice].dia_nasc, V[indice].mes_nasc, V[indice].ano_nasc);
  printf("\nNota: %f", V[indice].nota);

}

/*Função para imprimir o vetor de alunos aprovados*/
void i_alunos_ap(ALUNO *V, int n){
  int i;

  printf("Lista de Alunos(as) aprovados(as)\n\n");

  //Percorrendo o vetor para encontrar os alunos com nota maior ou igual a 6
  for (i=0; i<n; i++){
    if (V[i].nota >= 6){

      //Chamada da função de impressão de um registro de aluno
      imprime_aluno(i, V);
      printf("\n --------------------------- \n");
    }
  }

}
