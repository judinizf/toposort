// Vinícius do Nascimento Fontenele - 9293651
//Julia Diniz Ferreira - 9364865

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// retorna se a pilha é vazia ou não
int isempty(pilha *p){
    if(p->top == -1)
        return 1; // retorna 1 para pilha vazia
    else
        return 0; // retorna 0 caso contrário
}

/*

// acrescenta o valor NUMBER no topo da pilha
void push(pilha *p, int number){
    p->size++; 
    p->vet = (int*) realloc(p->vet, p->size * sizeof(int));
    if(p->vet == NULL) {
        printf("erro de alocacao\n");
        exit(1);
    }
    p->top++;
    p->vet[p->top]=number;
}


// apenas para inicializar a pilha, já q a entrada é ao contrário 
// do funcionamento da pilha
void addontop(pilha *p, int n) {
    int i, aux;
    pilha p2;
    for (i = 0; i < n; i++) {
        scanf("%d", &aux);
        push(p2, aux);
    }
    for (i = 0; i < n; i++) {
        aux = p2.vet[p2.top];
        p2.top--;
        p2.size--;
        push(p, aux);
    }
}


// deteta toda a pilha;
void deletestack(pilha *p){
    if(!isempty(p)){
        p->vet[p->top]=0;
        p->top--;
    }
}

*/