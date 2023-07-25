#include "deque.h"
#include <stdlib.h>

Deque* criaDeque(){
    Deque *dq;
    dq = (Deque*) malloc(sizeof(Deque));
    if (dq != NULL){
        dq->inicio = 0;
        dq->final = 0;
        dq->qtd = 0;
        dq->max = 28;
        dq->dados = (T*) malloc(dq->max * sizeof(T));
    }
    return dq;
}


void liberaDeque(Deque* dq){
    free(dq->dados);
    free(dq);
}

int tamanhoDeque(Deque* dq){
    if (dq == NULL)
        return -1;
    return dq->qtd;
}

int emptyDeque(Deque* dq){
    if (dq == NULL)
        return -1;
    if (dq->qtd == 0)
        return 1;
    else
        return 0;
}

int fullDeque(Deque* dq){
    if (dq == NULL)
        return -1;
    if (dq->qtd == dq->max)
        return 1;
    else
        return 0;
}

T firstDeque(Deque* dq){
    return dq->dados[dq->inicio];
}

T lastDeque(Deque* dq){
    return dq->dados[dq->final-1];
}

int insereInicioDeque(Deque* dq, T elem){
    if (dq == NULL || fullDeque(dq))
        return 0;
    dq->inicio--;
    if (dq->inicio < 0)
        dq->inicio = dq->max-1;
    dq->dados[dq->inicio] = elem;
    dq->qtd++;
    return 1;
}

int insereFinalDeque(Deque* dq, T elem){
    if (dq == NULL || fullDeque(dq))
        return 0;
    dq->dados[dq->final] = elem;
    dq->final++;
    if (dq->final == dq->max)
        dq->final = 0;
    dq->qtd ++;
    return 1;
}

T removeInicioDeque(Deque* dq){
    T elem = dq->dados[dq->inicio];
    dq->inicio++;
    if (dq->inicio == dq->max)
        dq->inicio = 0;
    dq->qtd--;
    return elem;
}

T removeFinalDeque(Deque* dq){
    dq->final--;
    if (dq->final < 0)
        dq->final = dq->max-1;
    T elem = dq->dados[dq->final];
    dq->qtd--;
    return elem;
}