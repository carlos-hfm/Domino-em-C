#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>

#include "peca.h"

typedef Peca T; //Tipo do elemento, nesse projeto e o tipo Peca (olhar "peca.h")

typedef struct deque {        //Struct do deque com apelido Deque, contem:
    int inicio, final, qtd;   //Tres inteiros que guardam os indices do inicio e final do deque, e a quantidade de elementos presentes no deque
    T *dados;                 //Vetor que quarda os elementos do deque
    int max;                  //Inteiro que guarda o numero maximo possivel de elementos do deque, para esse projeto, e 28 (total de pecas do domino)
} Deque;

//Funcoes da estrutura deque

Deque* criaDeque(); //Funcao que inicializa uma estrutura deque e retorna um ponteiro para o deque

void liberaDeque(Deque* dq); //Destroi/desaloca o deque

int tamanhoDeque(Deque* dq); //Funcao que retorna o tamanho/numero de elementos contidos no deque, ou -1 caso deque apontado esta nulo/inexistente

int emptyDeque(Deque* dq); //Verifica se o deque esta vazio, retorna 1 caso verdadeiro, 0 caso falso e -1 caso o ponteiro usado aponta pra um deque nulo/inexistente

int fullDeque(Deque* dq);  //Verifica se o deque esta cheio/atingiu o numero maximo de elementos, retorna 1 caso verdadeiro, 0 caso falso e -1 caso o ponteiro usado aponta pra um deque nulo/inexistente

T firstDeque(Deque* dq); //Retorna o elemento que esta no inicio do deque

T lastDeque(Deque* dq);  //Retorna o elemento que esta no final do deque

int insereInicioDeque(Deque* dq, T elem); //Insere um elemento no inicio do deque, retorna 1 caso foi inserido com sucesso e 0 caso deque esta cheio ou nulo

int insereFinalDeque(Deque* dq, T elem);  //Insere um elemento no final do deque, retorna 1 caso foi inserido com sucesso e 0 caso deque esta cheio ou nulo

T removeInicioDeque(Deque* dq);  //Remove um elemento no inicio do deque e retorna esse elemento

T removeFinalDeque(Deque* dq);   //Remove um elemento no final do deque e retorna esse elemento


#endif // DEQUE_H

