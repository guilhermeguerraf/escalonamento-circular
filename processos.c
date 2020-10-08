#include<stdio.h>
#include<stdlib.h>
#include "processos.h"

struct processos{
    char nome[3];
    int tempoProcessamento, tempoEspera, tempoResposta;
} filaPronto[T];

int fim = 0;
int espera;
int resposta;
int i;

void menu(){
    system("cls");
    printf("1 - Inserir processo na fila");
    printf("\n2 - Mostrar fila de processos");
    printf("\n3 - Escalonamento FIFO");
    printf("\n4 - Escalonamento Circular");
    printf("\n5 - SAIR");
}

int escolhaOpcao(){
    int opcao;
    fflush(stdin);
    printf("\n\nEscolha sua opcao: ");
    scanf("%d",&opcao);
    return opcao;
}

void inserir(){
    if (fim == T){
        printf("\nFILA CHEIA");
    }else{
        fflush(stdin);
        printf("\nEntre com o nome do processo: ");
        gets(filaPronto[fim].nome);
        fflush(stdin);
        printf("Entre com o tempo de processador: ");
        scanf("%d", &filaPronto[fim].tempoProcessamento);
        fim++;
    }
}

void mostrar(){
    if (fim == 0){
        printf("\nFILA VAZIA\n");
    }else{
        for(int i=0; i<fim; i++){
        printf("\n-----------------------------");
        printf("\nNome do processo:\t%s", filaPronto[i].nome);
        printf("\nTempo de processamento:\t%d", filaPronto[i].tempoProcessamento);
        printf("\n-----------------------------");
        }
    }
    printf("\n");
    system("pause");
}

void fifo(){
    float tme=0;
    float tmr=0;
    espera = 0;
    resposta = 0;
    for(i=0; i<fim; i++){
        filaPronto[i].tempoEspera = espera;
        filaPronto[i].tempoResposta = resposta + filaPronto[i].tempoProcessamento;
        tme = tme + filaPronto[i].tempoEspera;
        tmr = tmr + filaPronto[i].tempoResposta;
        espera = espera + filaPronto[i].tempoProcessamento;
        resposta = resposta + filaPronto[i].tempoProcessamento;
    }
    for(i=0; i<fim; i++){
        printf("\nProcesso: %s", filaPronto[i].nome);
        printf("\nTempo de Espera:\t%d", filaPronto[i].tempoEspera);
        printf("\nTempo de Resposta:\t%d\n", filaPronto[i].tempoResposta);
    }
    printf("\n\nEspera:\t%f", tme);
    printf("\nResposta:\t%f", tmr);
    printf("\nTempo medio espera (tme):\t%f", (tme/fim));
    printf("\nTempo medio retorno (tmr):\t%f", (tmr/fim));
    printf("\n\n");
    system("pause");
}

void circular(){
    int contadorProcessoFila = fim;
    int quantum;
    espera = 0;
    resposta = 0;
    i = 0;
    while(contadorProcessoFila > 0){
        if(filaPronto[i].tempoProcessamento == 0){
            i++;
        }else{
            printf("\nProcesso: %s", filaPronto[i].nome);
            filaPronto[i].tempoEspera = espera;
            printf("\nTempo de Espera:\t%d", filaPronto[i].tempoEspera);
            for(quantum = 0; quantum < 2; quantum++){
                espera++;
                resposta++;
                filaPronto[i].tempoProcessamento--;
                if(filaPronto[i].tempoProcessamento == 0)
                    break;
            }
            filaPronto[i].tempoResposta = resposta;
            printf("\nTempo de Resposta:\t%d", filaPronto[i].tempoResposta);
            printf("\nTempo de processamento restante: %d\n", filaPronto[i].tempoProcessamento);
            if(filaPronto[i].tempoProcessamento == 0){
                contadorProcessoFila--;
                printf("\nProcesso %s concluido\n", filaPronto[i].nome);
            }
            i++;
        }
        if(i == fim)
            i = 0;
    }
    printf("\n\n");
    system("pause");
}
