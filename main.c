#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "deque.h"
#include "pilha.h"
#include "time.h"
#define NPECAS 28
#define TRUE 1
#define FALSE 0

typedef struct jogador{ //Struct jogador com apelido Jogador, contem:
    Lista mao; //Lista onde ficam as pecas na mao dos jogadores
} Jogador;

//Funcoes do jogo

int inicioJogo(Pilha *monte, Jogador *jogadores); //Funcao que incializa o jogo, pergunta quantas pessoas vao jogar, cria o monte de pecas e distribui para as maos do jogadores. Retorna o numero de jogadores

int quantosJ(); //Pergunta e retorna o numero de pessoas qua vao jogar (2-4)

void criaPecas(Pilha *montePecas); //Cria os 28 elementos de peca, atribui os numeros aos lados de cada peca, e coloca todas na pilha que representa o monte

void embaralhaMonte(Pilha *montePecas); //Embaralha as pecas no monte

void jogada(int j, Deque *mesa, Pilha *monte, Jogador *jogadores); //Essa funcao faz uma jogada do domino, nela o jogador da vez (j) pega uma peca da mao e coloca na mesa

void mostraPeca(Peca p); //Imprime uma peca especifica

void mostrarMao(int j, Jogador *jogadores); //Imprime as pecas na mao de um jogador

int perguntaJogada(int j, Jogador *jogadores); //Pergunta e retorna qual peca o jogador quer usar

int vencedor(Jogador *jogadores, int NJ); //Verifica se algum jogador venceu (se nao tem mais nenhuma peca na mao), caso haja um vencedor retorna o numero do jogador -1 (0-3), caso ninguem venceu ainda retorna -1

void inverterPeca(int j, Jogador *jogadores, int p); //Inverte os lados esquerdo e direiro de uma peca de um jogador

int pecasMao(int j, Jogador *jogadores); //Retorna o numero de pelas na mao de um jogador

void compraPeca(int j, Pilha *monte, Jogador *jogadores); //Faz o jogador j comprar uma peca do monte

int colocaPeca(Jogador *jogadores, int j, Deque *mesa, int p); //Coloca a peca que o jogador escolheu na mesa, se for possivel. Retorna 1/TRUE caso jogada foi valida e 0/FALSE caso jogada foi invalida

void distribui(Pilha *montePecas, Jogador *jogadores, int nj); //Distribui as pecas do monte para a mao dos jogadores, 7 pecas pra cada

void imprimeMesa (Deque* mesa); //Imprime a mesa


int main(){

    printf("Bem-vindo ao jogo de domino!\n\n");

    Deque *mesa = criaDeque(); //A mesa e um deque
    Pilha *monte = criaPilha(); //O monte e uma pilha
    Jogador jogadores[4]; //Vetor de jogadores

    int numJogadores = inicioJogo(monte, jogadores);

    printf("\nVamos comecar!\n\n");

    int j = 0;
    while (vencedor(jogadores, numJogadores) == -1){ //Loop que controla as jogadas, termina quando existir um vencedor
        if(emptyDeque(mesa) == 0)
            imprimeMesa(mesa);

        jogada(j, mesa, monte, jogadores);
        j++;
        if (j + 1 > numJogadores)
            j = 0;
    }

    printf("O jogo acabou! O jogador %d e o vencedor!!\n", vencedor(jogadores, numJogadores) + 1);

    liberaDeque(mesa);
   destroiPilha(monte);

   for (int j = 0; j < numJogadores; j++)
        destruirLista(&jogadores[j].mao);

    return 0;
}

int quantosJ(){
    int n = 0;
    while (n <= 1 || n > 4){
        printf("Quantas pessoas irao jogar?\n");
        printf("Digite aqui apenas o numero (2-4)... \n ");
        scanf("%d", &n);
        if (n == 0){
            printf("Nao e possivel jogar com nenhum jogador...\n");
            printf("Responda novamente...\n");
        } else if (n == 1){
            printf("Nao e possivel jogar com apenas 1 jogador...\n");
            printf("Responda novamente...\n");
        } else if ( n > 4){
            printf("Nao e possivel jogar com mais de 4 jogadores...\n");
            printf("Responda novamente...\n");
        }
    }
    return n;
}

int inicioJogo(Pilha *monte, Jogador *jogadores){
    criaPecas(monte);
    embaralhaMonte(monte);
    int nJogadores = quantosJ();
    distribui(monte, jogadores, nJogadores);
    return nJogadores;
}

void jogada(int j, Deque *mesa, Pilha *monte, Jogador *jogadores){
    printf("E a vez do Jogador %d!\n\n", j+1);
    int p = 1;
    int jogadaLegal = FALSE;
    while (jogadaLegal == FALSE && p != 0){
        printf("Essa e a sua mao: \n\n");
        mostrarMao(j, jogadores);
        p = perguntaJogada(j, jogadores);
        if (p == 0){
            if (emptyPilha(monte) == 0){
                compraPeca(j, monte, jogadores);
                jogadaLegal = TRUE;
            } else {
                printf("Nao ha pecas para serem compradas.\n");
            }
        } else {
            jogadaLegal = colocaPeca(jogadores, j, mesa, p);
        }
    }
}

void criaPecas(Pilha *montePecas){
    Peca pecaAtual;
    for (int i = 0; i <= 6; i++)
        for (int j = i; j <= 6; j++){
            pecaAtual.lado1 = i;
            pecaAtual.lado2 = j;
            inserePilha(montePecas, pecaAtual);
    }
}

void embaralhaMonte(Pilha *montePecas){
    srand(time(NULL));
    Peca vetor[NPECAS];
    for (int i = 0; i < NPECAS; i++){
        vetor[i] = topPilha(montePecas);
        removePilha(montePecas);
      }

    int i = 0;
    int verifRepeticao[NPECAS];
    int igual;
    while (i < NPECAS) {
        igual = FALSE;
        verifRepeticao[i] = rand() % NPECAS-1;
        for (int j = 0; j < i; j++){
            if (verifRepeticao[j] == verifRepeticao[i])
                igual = TRUE;
        }
        if (igual == FALSE){
      inserePilha( montePecas, vetor[verifRepeticao[i]]);
        i++;
        }
    }
}

void mostraPeca(Peca p){
    printf("[%d|%d] ", p.lado1, p.lado2);
}

void mostrarMao(int j, Jogador *jogadores){
    int i = 1;
    for( iterador it = primeiroLista(&jogadores[j].mao); !acabouLista(it); it = proximoIterador(&it),i++ ){
        printf("%d - [%d|%d]\n",i, elementoLista(it)->lado1, elementoLista(it)->lado2);
      }
   printf("\n");
  }

void distribui(Pilha *montePecas, Jogador *jogadores, int nj){
    for(int j = 0; j < nj;j++){
        inicializaLista(&jogadores[j].mao);
      iterador it = primeiroLista(&jogadores[j].mao);
        for(int i = 0; i < 7;i++, it = proximoIterador(&it)){
            Peca domino = topPilha(montePecas);
            removePilha(montePecas);
            insereFLista(&jogadores[j].mao, domino);
        }
    }
}

int perguntaJogada(int j, Jogador *jogadores){
    int p = 0;
    int pecaExiste = FALSE;
    while (pecaExiste != TRUE){
        printf("Qual peca voce quer usar?\n");
        printf("Caso nao possa usar nenhuma peca digite 0\n");
        scanf("%d", &p);
        printf("\n");

        if (p <= pecasMao(j, jogadores) && p >= 0)
            pecaExiste = TRUE;
        else if (p < 0){
            printf("Essa peca nao existe...\n");
            printf("Responda novamente.\n\n");
        } else if (p > pecasMao(j, jogadores)){
            printf("Voce so tem %d pecas na mao...\n", pecasMao(j, jogadores));
            printf("Responda novamente.\n\n");
        }
    }
    return p;
}
int vencedor(Jogador *jogadores, int NJ){
    int ven = -1;
    for (int i = 0; i < NJ; i++){
        if (pecasMao(i, jogadores) == 0){
            ven = i;
        }
    }
    return ven;
}

void inverterPeca(int j, Jogador *jogadores, int p){
  int  aux;
  iterador it = primeiroLista(&jogadores[j].mao);
  for( ; p - 1 > 0; p--)
    it = proximoIterador(&it);

  aux = elementoLista(it)->lado1;
  elementoLista(it)->lado1 = elementoLista(it)->lado2;
  elementoLista(it)->lado2 = aux;
}

int pecasMao(int j, Jogador *jogadores){
  return tamanhoLista(&jogadores[j].mao);
}

void compraPeca(int j, Pilha *monte, Jogador *jogadores){
    printf("Agora voce vai comprar uma peca.\n");
    Peca retirada = topPilha(monte);
    removePilha(monte);
    insereFLista(&jogadores[j].mao, retirada);
    printf("A peca comprada foi essa: \n\n");
    mostraPeca(retirada);
    printf("\n");
    printf("\n");
}

int colocaPeca(Jogador *jogadores, int j, Deque *mesa, int p){
    char fc = 'A', inverter = 'A';

    iterador it = primeiroLista(&jogadores[j].mao);
    for( int i = p; i-1 > 0; i--)
        it = proximoIterador(&it);

    if(emptyDeque(mesa) == 0 && (elementoLista(it)->lado1 != elementoLista(it)->lado2)){
        while (inverter != 'S' && inverter != 'N'){
        printf("Voce quer inverter esta peca? (digite 'S' ou 'N')\n");
        scanf(" %c", &inverter);
        printf("\n");
        if (inverter != 'S' && inverter != 'N'){
            printf("Nao entendi...\n");
            printf("Responda novamente...\n");
        }
        else if (inverter == 'S'){  
            if (p <= pecasMao(j, jogadores) && p >= 0)
                inverterPeca(j, jogadores, p);
        }
        }
    } 


    if(emptyDeque(mesa) == 0){
        while(fc != 'F' && fc != 'C'){
            printf("Deseja colocar essa peca no final(F) ou no comeco(C) da mesa?\n");
            scanf(" %c", &fc);
            printf("\n");
            if(fc != 'F' && fc != 'C')
                printf("Nao entendi... Responda novamente\n");
        }
    }
    Peca jogada = (*elementoLista(it));

    if(fc == 'F'){
        if(elementoLista(it)->lado1 != lastDeque(mesa).lado2){
            printf("Jogada invalida\n");
            return 0;
      }
        else{
            insereFinalDeque(mesa, jogada);
            retiraLista(&jogadores[j].mao, it);
            return 1;
        }
    }

    else if(fc == 'C'){
        if(elementoLista(it)->lado2 != firstDeque(mesa).lado1){
            printf("Jogada invalida\n");
            return 0;
        }
        else{
            insereInicioDeque(mesa, jogada);
            retiraLista(&jogadores[j].mao, it);
            return 1;
        }
    }
    else{
        insereInicioDeque(mesa, jogada);
        retiraLista(&jogadores[j].mao, it);
        return 1;}
    }

void imprimeMesa (Deque* mesa){
    printf("\n");
    Peca vetor[NPECAS];
    int tam = tamanhoDeque(mesa);
    for (int i = 0; i < tam; i++){
        if (i == 0)
            printf("A mesa esta assim: \n\n");
        vetor[i] = removeInicioDeque(mesa);
        mostraPeca(vetor[i]);
    }

    for (int i = 0; i < tam; i++){
        insereFinalDeque(mesa, vetor[i]);
    }
    printf("\n");
    printf("\n");

}
