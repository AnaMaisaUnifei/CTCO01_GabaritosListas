/* ----- Informações do projeto -----
- Disciplina: Algoritmos e Estruturas de Dados I (CTCO01)
- Prof.ª Elisa de Cassia Silva Rodrigues
- Tarefa: Lista 1 - Exercício 1 - Vetores e Matrizes
- Instituição: Universidade Federal de Itajubá (UNIFEI)
- Curso: Ciência da Computação
- Feita por Ana Maísa do Nascimento Santos, Monitora da Disciplina
*/

#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções - abaixo da main
int *preencher_vetor(int tam);
int **preencher_matriz(int lin, int col, int *vetor);
void imprime_vetor(int *vetor, int tam);
void imprime_matriz(int** matriz, int lin, int col);
void libera_matriz(int **matriz, int lin);

int main(){
  int lin, col, tam, *vetor, **matriz; // Variáveis para linhas, colunas, ponteiro para o vetor e ponteiro para a matriz

  // Coleta das linhas e colunas do usuário
  printf ("Digite o número de linhas: ");
  scanf ("%d", &lin);

  printf ("Digite o número de colunas: ");
  scanf ("%d", &col);

  tam = lin*col; // Atribuição do tamanho (para o vetor)

  // Chamada da função para preencher o vetor
  vetor = preencher_vetor(tam);

  // Chamada da função para imprimir o vetor
  imprime_vetor(vetor, tam);

  // Colocando dados do vetor na matriz com a função
  matriz = preencher_matriz(lin, col, vetor);

  // Chamada da função para imprimir a matriz
  imprime_matriz(matriz, lin, col);

  // Liberação de memória
  free(vetor);
  libera_matriz(matriz, lin);

  return 0;
}

// Função para preencher o vetor com dados informados pelo usuário
int *preencher_vetor (int tam){
  // Declaração de variáveis e ponteiros
  int *vetor, i;

  // Alocação dinâmica do vetor
  vetor = (int*) malloc (tam * sizeof(int));

  // Preenchimento do vetor com dados fornecidos
  printf("----Preenchendo o Vetor----\n");

  for (i = 0; i < tam; i++){
    printf ("Vetor[%d] = ", i);
    scanf ("%d", &vetor[i]);
  }
  
  // Retorno do Vetor construido
  return vetor;
}

// Função para preencher a matriz com os dados do vetor
int **preencher_matriz(int lin, int col, int *vetor){
  // Declaração de variáveis e ponteiros
  int **matriz, i, j, cont = 0;

  // Alcoação dinâmica das linhas da Matriz
  matriz = (int**) malloc (lin * sizeof(int));

  // Preenchimento da Matriz com os dados do vetor
  for (i = 0; i < lin; i++){
    // Alocação dinâmica das colunas da Matriz
    matriz[i] = (int*) malloc(col * sizeof(int));
    for(j = 0; j < col; j++){
      matriz[i][j] = vetor[cont];
      cont++;
    }
  }

  // Mensagem de finalização do preenchimento
  printf("\n----Matriz Preenchida----\n");

  // Retorno da Matriz construída
  return matriz;
}

// Função para imprimir um vetor
void imprime_vetor(int *vetor, int tam){
  // Declaração de variáveis
  int i;

  // Impressão do vetor
  printf("\n----Vetor Cadastrado----\n");
  for (i = 0; i < tam; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n--------------------------\n");
}

// Função para imprimir uma Matriz
void imprime_matriz(int **matriz, int lin, int col){
  // Declaração de variáveis
  int i, j;

  // Impressão da Matriz
  printf("\n----Matriz Cadastrada----\n");
  for (i = 0; i < lin; i++) {
    for(j = 0; j < col; j++){
      printf("%d ", matriz[i][j]);  
    }
    printf("\n");
  }
  printf("--------------------------\n");
}

// Função para liberar a memória alocada para a matriz
void libera_matriz(int **matriz, int lin){
  int i;
  for (i = 0; i < lin; i++) {
   free(matriz[i]);
  }
  free(matriz);
}