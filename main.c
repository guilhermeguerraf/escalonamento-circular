#include<stdio.h>
#include<stdlib.h>
#include "processos.h"

int main()
{
    int opcao;
    do{
        menu();
        opcao = escolhaOpcao();
        switch(opcao){
            case 1:
                inserir();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                fifo();
                break;
            case 4:
                circular();
                break;
            case 5:
                break;
            default:
                printf("\nOpcao invalida!");
        }
    }while(opcao != 5);
    return 0;
}
