#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "peca.h"

typedef Peca T; //Tipo do elemento, nesse projeto e o tipo Peca (olhar "peca.h")

typedef struct pilha{ //Struct da pilha com apelido Pilha, contem:
    unsigned topo;    //Inteiro sem sinal que guarda o indice imediatamente depois do indice do elemento que esta no topo da pilha/ultimo elemento (indice do ultimo elemento +1)
    T *vetor;         //Vetor que guarda os elementos da pilha
    int max;
} Pilha;

//Funcoes da estrutura pilha

Pilha* criaPilha(); //Inicializa uma estrutura pilha e retorna um ponteiro para a pilha

void destroiPilha(Pilha *p); //Destroi/desaloca a pilha

int inserePilha(Pilha *p, T elem); //Insere um elemento no topo da pilha, retorna 1 caso inserido com sucesso e 0 caso pilha esta cheia ou nula

int removePilha(Pilha *p); //Remove um elemento do topo da pilha, retorna 1 caso removido com sucesso e 0 caso pilha esta vazia ou nula

T topPilha(Pilha *p); //Retorna o elemento que esta no topo da pilha

int emptyPilha(Pilha *p); //Verifica se a pilha esta vazia, retorna 1 caso verdadeiro, 0 caso falso e -1 caso a pilha apontada esta nula/inexistente

int sizePilha(Pilha *p);  //Retorna o tamanho da pilha/numero de elementos presentes na pilha, ou -1 caso pilha apontada esta nula


#endif // PILHA_H_INCLUDED