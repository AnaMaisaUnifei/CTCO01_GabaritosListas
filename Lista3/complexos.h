/* ----- Informações do projeto -----
- Disciplina: Algoritmos e Estruturas de Dados I (CTCO01)
- Prof.ª Elisa de Cassia Silva Rodrigues
- Tarefa: Lista 3 - TAD Números Complexos
- Instituição: Universidade Federal de Itajubá (UNIFEI)
- Curso: Ciência da Computação
- Feita por Ana Maísa do Nascimento Santos, Monitora da Disciplina
*/

/*Protótipos das funções do arquivo "complexos.c"*/

/*Struct de um número complexo*/
typedef struct n_Complexo num_complexo;

/*Função de alocação do espaço de memória para os 2 números complexos a serem usados*/
num_complexo *criar_n();

/*Liberação da memória alocada na função criar_n*/
void lib_memoria();

/*Função que efetua a soma dos números complexos digitados*/
num_complexo somar_complexo();

/*Função que efetua a subtração dos números complexos digitados*/
num_complexo sub_complexo();

/*Função que efetua a multiplicação dos números complexos digitados*/
num_complexo mult_complexo();

/*Função que efetua a divisão dos números complexos digitados*/
num_complexo div_complexo();