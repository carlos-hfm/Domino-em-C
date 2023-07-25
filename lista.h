#ifndef LISTA_H
#define LISTA_H

#include "peca.h"

typedef struct peca Peca;

typedef Peca T;//Tipo do elemento, nesse projeto e o tipo Peca (olhar "peca.h")

struct node{//struct do no que sera criado simbolizando os elementos da lista
T data; //valor que sera dado ao no 
struct node *next, *prev;// ponteiros apontando pro no posterior e anterior
};

typedef struct lista{//Struct da lista com apelido Lista, contem:
struct node *sentinela;//no sentinela, nao tera valor e apontara para os primeiros e ultimos elementos da lista
unsigned quantidade;//numero de pecas na lista
} Lista;

typedef struct {//Struct do iterador, que sera quem nos possibilitara selecionar elementos do meio da lista
struct node *posicao;//aponta para um no que sera a posicao do iterador
Lista *estrutura;//aponta para a lista da qual o iterador faz parte
} iterador;

void inicializaLista(Lista *p);//Funcao que inicializa uma estrutura lista
void destruirLista(Lista *p);//Funcao que destroi a lista previamente inicializada
int ListaVazia(Lista *p);//Funcao que retorna 1 se a lista nao tiver nenhum elemento fora a sentinela e 0 caso o contrario
unsigned tamanhoLista(Lista *p);// Funcao que retorna o numero de elementos da lista
void insereILista(Lista *p, T data);//Funcao que insere um elemento na primeira posicao da lista
void insereFLista(Lista *p, T data);//Funcao que insere um elemento na ultima posicao da lista
void retiraILista(Lista *p);//Funcao que retira o elemento da primeira posicao da lista
void retiraFLista(Lista *p);//Funcao que retira o elemento da ultima posicao da lista
T* topoLista(Lista *p);//Funcao que retorna um ponteiro apontando para o valor peca do elemento da ultima posicao da lista
T* comecoLista(Lista *p);//Funcao que retorna um ponteiro apontando para o valor peca do elemento da primeira posicao da lista
void insereAntesLista( Lista* l, iterador i, T data);//Funcao utilizando o iterador que insere um elemento na posicao seguinte ao da posicao do iterador
void insereDepoisLista( Lista* l, iterador i, T data);//Funcao utilizando o iterador que insere um elemento na posicao anterior ao da posicao do iterador
iterador retiraLista( Lista* l, iterador i);//retira o elemento que o iterador esta apontando e retorna o iterador de posicao seguinte ou anterior ao iterador dependendo da posicao deste
iterador primeiroLista( Lista* l );//retorna o iterador apontando para o primeiro elemento da lista
iterador ultimoLista( Lista* l );//retorna o iterador apontando para o ultimo elemento da lista
T* elementoLista( iterador i );//retorna um ponteiro apontando para o valor peca do no que o iterador esta apontando
iterador proximoIterador( iterador* i );//retorna o iterador da posicao seguinte ao qual o iterador esta apontando antes da funcao ser realizada
iterador IteradorAnterior( iterador* i );//retorna o iterador da posicao anterior ao qual o iterador esta apontando antes da funcao ser realizada
int acabouLista( iterador i );//retorna 1 se o iterador esta apontando para o sentinela, indicando que a lista acabou e 0 caso o contrario


#endif
