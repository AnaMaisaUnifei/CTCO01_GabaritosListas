/* ----- Informações do projeto -----
- Disciplina: Algoritmos e Estruturas de Dados I (CTCO01)
- Prof.ª Elisa de Cassia Silva Rodrigues
- Tarefa: Lista 5 - TAD Dados de Hanoi
- Instituição: Universidade Federal de Itajubá (UNIFEI)
- Curso: Ciência da Computação
- Feita por Ana Maísa do Nascimento Santos, Monitora da Disciplina
*/

// Bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Biblioteca do projeto
#include "hanoi.h"

int main(void) {
	char letra;
	int tamanho = 0, ordem = 0, ok = 1, tubo;

	// Criação das pilhas
	Pilha *p1 = NULL;
	Pilha *pi2 = NULL;
	Pilha *p3 = NULL;

	p1 = criar();
	pi2 = criar();
	p3 = criar();

	// Inserção dos dados na pilha 1

	empilhar(p1, 'U', 1);
	empilhar(p1, 'O', 2);
	empilhar(p1, 'I', 3);
	empilhar(p1, 'E', 4);
	empilhar(p1, 'A', 5);

	// Repetição até que a pilha 3 não esteja completa
	while (tamanho_pilha(p3) != 5) {
		// Primeira mostra de tubos
		mostrar_tubos(p1, pi2, p3);

		// Repetição de retirada
		while (ok == 1) {
			printf("\nDe qual tubo deseja retirar um cubo?: ");
			scanf("%d", &tubo);

			switch (tubo) {
			case 1:
				ok = tirar(p1, &ordem, &letra);
				break;

			case 2:
				ok = tirar(pi2, &ordem, &letra);
				break;

			case 3:
				ok = tirar(p3, &ordem, &letra);
				break;

			default:
				printf("Esse tubo não existe!");
				break;
			}
		}

		// Mostra depois da retirada
		system("clear");
		ok = 1;
		mostrar_tubos(p1, pi2, p3);

		// Repetição de inserção
		while (ok == 1) {
			printf("\nEm qual tubo deseja inserir o cubo?: ");
			scanf("%d", &tubo);

			switch (tubo) {
			case 1:
				ok = colocar(p1, &ordem, &letra);
				break;

			case 2:
				ok = colocar(pi2, &ordem, &letra);
				break;

			case 3:
				ok = colocar(p3, &ordem, &letra);
				break;

			default:
				printf("Esse tubo não existe!");
				break;
			}
		}

		// Mostra final do ciclo
		system("clear");
		ok = 1;
	}

	printf("Parabéns! Você ganhou!");

	// Liberar as pilhas
	liberar(p1);
	liberar(pi2);
	liberar(p3);

	return 0;
}