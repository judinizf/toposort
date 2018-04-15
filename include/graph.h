// Vinícius do Nascimento Fontenele - 9293651
//Julia Diniz Ferreira - 9364865

#ifndef _GRAPH_H
#define _GRAPH_H

#define vertice int

// estrutura nó
typedef struct no{
	vertice v;
	struct no* prox;
}no;

// estrutura grafo
typedef struct grafo{
	int nvert;
	int narest;
	no** lista;
}grafo;

// estrutura da ordenação topológica
typedef struct ordem{
		vertice w;
		struct ordem* prox;
		struct ordem* ant;
}ordem;

grafo inigrafo(int nvert);
void addarco(grafo *g, vertice v, vertice w);
int *calculaingrau(grafo *g);
int *atualizagrau(grafo *g, int *array, int key);
void ordenacaotopologica(grafo *g);

#endif