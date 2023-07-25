#include "lista.h"
#include <stdlib.h>

void inicializaLista( Lista *p ) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->next = n->prev = p->sentinela = n;
    p->quantidade = 0;
}

void destruirLista( Lista *p ) {
    while(!ListaVazia(p))
    retiraILista(p);
    free(p->sentinela);
}

int ListaVazia( Lista *p ) {
    return p->sentinela->next == p->sentinela; // ou prev
}

unsigned tamanhoLista(Lista *p) {
    return p->quantidade;
}

void insereILista( Lista *p, T data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = p->sentinela->next;
    n->prev = p->sentinela;
    p->sentinela->next = n;
    n->next->prev = n;
    p->quantidade++;
}

void retiraILista( Lista *p) {
    struct node *n = p->sentinela->next;
    if( n != p->sentinela ) { // Lista vazia
        n->next->prev = n->prev;
        n->prev->next = n->next;
        free(n);
        p->quantidade--;
    }
}

void insereFLista( Lista *p, T data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = p->sentinela;
    n->prev = p->sentinela->prev;
    p->sentinela->prev = n;
    n->prev->next = n;
    p->quantidade++;
}

void retiraFLista( Lista *p) {
    struct node *n = p->sentinela->prev;
    if( n != p->sentinela ) { // Lista vazia
        n->next->prev = n->prev;
        n->prev->next = n->next;
        free(n);
        p->quantidade--;
    }
}

T* comecoLista(Lista *l){
     if(!ListaVazia(l))
        return elementoLista(primeiroLista(l));
      else
        return 0;
}

T* topo(Lista *l){
    if(!ListaVazia(l))
        return elementoLista(ultimoLista(l));
    else
      return 0;
}

iterador primeiroLista( Lista* l ) {
    iterador i;
    i.posicao = l->sentinela->next;
    i.estrutura = l;
    return i;
}

iterador ultimoLista( Lista* l ) {
    iterador i;
    i.posicao = l->sentinela->prev;
    i.estrutura = l;
    return i;
}

T* elementoLista( iterador i ) {
    return (&i.posicao->data);
}

int acabouLista( iterador i ) {
    return i.posicao == i.estrutura->sentinela;
}

iterador proximoIterador( iterador* i ) {
    if( !acabouLista( *i ) ) {
        i->posicao = i->posicao->next;
    }
    else
        ;
    return *i;
}

iterador IteradorAnterior( iterador* i ) {
    if( !acabouLista( *i ) ) {
        i->posicao = i->posicao->next;
    }
    else
        ;
   return *i;
}

void insereAntesLista( Lista* l, iterador i, T data){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (i.posicao != l->sentinela->next){
        n->data = data;
        n->next = i.posicao;
        n->prev = i.posicao->prev;
        i.posicao->prev->next = n;
        i.posicao->prev = n;
        l->quantidade++;
        }
    else
        insereILista(l, data);
}

void insereDepoisLista( Lista* l, iterador i, T data){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (i.posicao != l->sentinela->prev){
        n->data = data;
        n->next = i.posicao->next;
        n->prev = i.posicao;
        i.posicao->next = n;
        i.posicao->next->prev = n;
        l->quantidade++;
        }
    else{
        insereFLista(l, data);
    }
}

iterador retiraLista( Lista* l, iterador i) {
    struct node *n = i.posicao;
    if( !acabouLista( i ) ) { // Lista vazia
        n->next->prev = n->prev;
        n->prev->next = n->next;
        if(i.posicao->prev != l->sentinela){
            i.posicao = i.posicao->prev;
        }
        else
            i.posicao = i.posicao->next;
        free(n);
        l->quantidade--;
    }
    else
        ;
    return i;
}