// Vinícius do Nascimento Fontenele - 9293651
//Julia Diniz Ferreira - 9364865

#ifndef _QUEUE_H
#define _QUEUE_H

// estrutura da pilha
typedef struct pilha{
    int size;
    int top;
    int *vet;
}pilha;

int isempty(pilha *p);
void push(pilha *p, int number);
void addontop(pilha *p, int n);
void deletestack(pilha *p);

#endif