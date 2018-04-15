// Vinícius do Nascimento Fontenele - 9293651
//Julia Diniz Ferreira - 9364865

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "queue.h"

int main (int argc, char *argv[]) {
	int wc, nvert, narest, i;
	int n, k, vol;
	vertice v1,v2, w;

	// PARTE 1
	scanf("%d", &wc);
	scanf("%d %d", &nvert, &narest);
	
	grafo g = inigrafo(nvert);
	pilha p = {0, -1, NULL};
	
	for (i = 0; i < narest; i++) {
		scanf("%d %d", &v1, &v2);
		addarco(&g,(v1-1),(v2-1));
	}
	ordenacaotopologica(&g);
	
	// PARTE 2
	scanf("%d", &wc);
	scanf("%d %d %d", &n, &k, &vol);
	//addontop(&p, n);
	
	return 0;
}