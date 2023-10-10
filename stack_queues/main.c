#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"stack_queues.h"
#define PILHA 1
#define FILA 2
#define INDEFINIDO 3
#define IMPOSSIVEL 4

int main(){
    int N; 
    //N - Numero de Casos
    scanf("%d",&N);
    int *output = createArray(N);
    char insert[] = "i";
    char remove[] = "r";
    char option[10];
    for(int i=0;i<N;i++){
        int K;
        t_stack S;
        initStack(&S);
        t_queue Q;
        initQueue(&Q);
        //Numero de operações de inserção e remoção a serem efetuadas 
        int operations;
        scanf("%d",&operations);
        int *pops = createArray(operations);
        int *dequeues = createArray(operations);
        int *removes = createArray(operations);
        int num_removes=0;
        int *a = createArray(operations);
        int first_remove = operations;
        for(int j=0; j<operations;j++){
            scanf("%s",option);
            if(strcmp(option,insert) == 0){
                scanf("%d",&a[j]);
                pushStack(a[j],&S);
                enqueue(a[j],&Q);
            }else if(strcmp(option,remove) == 0){
                scanf("%d",&a[j]);
                pops[j]=popStack(&S);
                dequeues[j]=dequeue(&Q);
                removes[j] = a[j];
                if(j<first_remove){
                    first_remove = j;
                }
                num_removes++; 
            }
        }

        int same_pops = 0;
        int same_dequeues = 0;
        //Ta dando problema aqui!!!!!!!!
        for(int m=first_remove;m<(num_removes+first_remove);m++){
            if(pops[m] == removes[m]){
                same_pops++;
            }
            if(dequeues[m] == removes[m]){
                same_dequeues++;
            }
        }
        if(same_pops == num_removes && same_dequeues != num_removes){
            output[i] = PILHA;
        }else if(same_dequeues == num_removes && same_pops !=num_removes){
            output[i] = FILA;
        }else if (same_dequeues ==num_removes && same_pops ==num_removes){
            output[i] = INDEFINIDO;
        }else{
            output[i] = IMPOSSIVEL;
        }
        clearStack(&S);
        clearQueue(&Q);
        free(a);
        free(pops);
        free(dequeues);
        free(removes);
    }
    

    for(int i=0; i<N;i++){
        if(output[i] == PILHA){
            printf("\npilha ");
        }else if(output[i] == FILA){
            printf("\nfila ");
        }else if(output[i] == INDEFINIDO){
            printf("\nindefinido ");
        }else if(output[i] == IMPOSSIVEL){
            printf("\nimpossivel ");
        }
    }
    
    free(output);

}