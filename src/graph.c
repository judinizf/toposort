// Vinícius do Nascimento Fontenele - 9293651
//Julia Diniz Ferreira - 9364865

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "queue.h"

// vertices inteiros
#define vertice int

// incializa o grafo dado o número de vértices totais
grafo inigrafo(int nvert) {
	int i;
	grafo g;
	g.nvert = nvert;
	g.lista = (no **) malloc(nvert * sizeof(struct no *));
	for (i = 0; i < g.nvert; i++) {
		g.lista[i] = NULL;
	}
	return g;
}

// adiciona uma aresta ligando v -> w
void addarco(grafo *g, vertice v, vertice w) {
	int i;
	no *aux, *aux2, *aux3;
	int flag = 0, help; // FLAG >> 0 = certo, 1 = erro
	if (v<0 || v>=g->nvert || w<0 || w>=g->nvert){
		printf("valores invalidos\n");
		exit(2);
	}
	aux = g->lista[v];
	if(v != w) {
		if(aux == NULL){ // primeira aresta partindo de v
			g->lista[v] = (no*) malloc (1 * sizeof(no));
			if(g->lista[v] == NULL){
				printf("erro de alocacao\n");
				exit(3);
			}
			g->lista[v]->prox = NULL;
			g->lista[v]->v = w; // coloca na lista de V a ligação com W
		}
		else {
			if(aux->prox != NULL){ // caso  haja mais de 1 arco na lista de adjacências
				do{
					aux2 = aux;
					aux = aux->prox;
					if(aux->v == w || aux2->v == w){ // estruturas de ordenação
						return;
					}
					if(aux->v > w){
						flag = 1;
						break;
					}
				} while(aux->prox != NULL);
				if(flag == 0) {
					aux->prox = (no*) malloc (1 * sizeof(no)); // crio o novo último nó
					if(aux->prox == NULL){
						printf("erro de alocacao\n");
						exit(4);
					}
					aux->prox->v = w;
					aux->prox->prox = NULL; // o próximo do novo nó se torna nulo
				}
				else { // caso o valor entrado precise ser colocado entre 2 outros valores
					if(aux2->v > w){
						aux3 = (no*) malloc (1 * sizeof(no));
						if(aux3 == NULL){
							printf("erro de alocacao\n");
							exit(5);
						}
						aux2->prox = aux3;
						aux3->prox = aux;
						aux3->v = aux2->v;
						aux2->v = w;
						flag = 0;
					}
					else {
						aux3 = (no*) malloc (1 * sizeof(no));
						if(aux3 == NULL){
							printf("erro de alocacao\n");
							exit(6);
						}
						aux2->prox = aux3;
						aux3->v = w;
						aux3->prox = aux;
						flag = 0;
					}
				}
			}
			else {
				aux->prox = (no*) malloc (1 * sizeof(no)); // crio o novo último nó
				if(aux->prox == NULL){
					printf("erro de alocacao\n");
					exit(7);
				}
				aux->prox->v = w; // caso o segundo valor seja menor q o primeiro da lista
				if(aux->prox->v < aux->v){
					aux->prox->v = aux->v;
					aux->v = w;
				}
				aux->prox->prox = NULL; // o próximo do novo nó se torna nulo
			}
		}
	}
}


// calcula o valor do grau de entrada de cada vértice
int *calculaingrau(grafo *g) {
	int i, j, count = 1, flag = 0;;
	int *vector = NULL;
	vector = (int *) malloc (g->nvert * sizeof(int));
	if (vector == NULL){
		printf("erro de alocacao\n");
		exit(9);
	}
	for (i = 0; i < g->nvert; i++) {
		vector[i] = 0;
	}
	no *aux;
	for (j = 0; j < g->nvert; j++) {
		for (i = 0; i < g->nvert; i++) {
			aux = g->lista[i];
			while (aux != NULL) {
				if (aux->v == j) {
					vector[j]++;
					break;
				}
				else
					aux = aux->prox;
			}
		}
	}
	return vector;
}

// atualiza o vetor com os graus de entrada de cada vértice
int *atualizagrau(grafo *g, int *array, int key){
	int i;
	no *aux;
	aux = g->lista[key];
	for (i = 0; aux != NULL; aux = aux->prox) {
		array[aux->v] = array[aux->v] - 1;
	}
	return array;
}

// faz a menor ordenação topológica lexicograficamente do grafo e imprime na tela
void ordenacaotopologica(grafo *g) {
	int i, j, flag = 0, count = 1, node, help;
	no *aux;
	int *array, *vector;
	// vetor vazio que irá conter os elementos na ordem topológica
	vector = (int *) malloc (g->nvert * sizeof(int));
	if(vector == NULL) {
		printf("erro de alocacao\n");
		exit(10);
	}
	for (i = 0; i < g->nvert; i++){
		vector[i] = -1; // flag pra erros
	}

	// array dos vertices sem arestas de entrada
	array = calculaingrau(g);

	// ordenação topológica
	j = 0;
	while(i != -1) { // laço infinito
		//busca o primeiro vertice com grau de entrada 0
		for (i = 0; i < g->nvert; i++) {
			if(array[i] == 0)
				break;
		}
		if (i != g->nvert) { // constrói o vetor resultado
			vector[j] = i;
			array[i] = -1;
			array = atualizagrau(g, array, i);
			j++;
		}
		else // controle de parada do laço
			break;
	}
	for (i = 0; i < g->nvert; i++)
		printf("%d ", (vector[i] + 1));
		printf("\n");
}