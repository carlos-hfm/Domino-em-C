#include "pilha.h"
#include <stdlib.h>

Pilha* criaPilha(){
    Pilha *p;
    p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL){
        p->topo = 0;
        p->max = 28;
        p->vetor = (T*) malloc(p->max * sizeof(T));
    }
    return p;
}

void destroiPilha(Pilha *p){
    free(p->vetor);
    free(p);
}

int inserePilha(Pilha *p, T elem){
   if (p == NULL || p->topo == p->max)
        return -1;
    p->vetor[p->topo] = elem;
    p->topo++;
    return 1;
}

int removePilha(Pilha *p){
    if (p == NULL || p->topo == 0)
        return -1;
    p->topo--;
    return 1;
}

T topPilha(Pilha *p){
    return p->vetor[p->topo-1];
}

int emptyPilha(Pilha *p){
    if (p == NULL)
        return -1;
    if (p->topo == 0)
        return 1;
    else
        return 0;
}

int sizePilha(Pilha *p){
    if (p == NULL)
        return -1;
    return p->topo;
}
