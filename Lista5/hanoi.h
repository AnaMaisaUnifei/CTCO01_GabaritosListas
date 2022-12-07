// TAD para Pilha Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#ifndef _PILHA
#define _PILHA

typedef struct elemento* Pilha;
typedef struct dado Dado;             

// funções para alocar e desalocar memória
Pilha* criar();                        
int liberar(Pilha *pi);   

// função para obter informação da pilha
int tamanho_pilha(Pilha *pi);      

// funções para empilhar e desempilhar elementos da pilha
int empilhar(Pilha *pi, char letra, int ordem);
int desempilhar(Pilha *pi);               

// função para consultar elemento no topo da pilha
int topo_pilha(Pilha *pi, char *letra); 

void mostrar_tubos(Pilha *p1, Pilha *p2, Pilha *p3);
int  tirar(Pilha *pi, int *ordem, char *letra);
int colocar(Pilha *pi, int *ordem, char *letra);

#endif 