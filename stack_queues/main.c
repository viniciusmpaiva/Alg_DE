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
    int *output = createAray(N);
    t_stack *S;
    t_queue *Q;
    char insert[1] = "i";
    char remove[1] = "r";
    char option[1];
    for(int i=0;i<N;i++){
        int K;
        //Numero de operações de inserção e remoção a serem efetuadas 
        int operations;
        scanf("%d",&operations);
        int *pops = createAray(operations);
        int *dequeues = createAray(operations);
        int *removes = createAray(operations);
        int num_removes=0;
        int *a = createAray(operations);
        for(int j=0; j<operations;j++){
            scanf("%c",option);
            scanf("%d",&a[j]);
            if(strcmp(option,insert) == 0){
                pushStack(a[j],S);
                enqueue(a[j],Q);
                printf("\n%d\n",a[j]);
            }else if(strcmp(option,remove) == 0){
                pops[j]=popStack(S);
                dequeues[j]=dequeue(Q);
                removes[j] = a[j];
                printf("\n%d\n",a[j]);
                num_removes++; 
            }
        }
        free(a);
        int same_pops = 0;
        int same_dequeues = 0;
        for(int m=0;m<num_removes;m++){
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
        free(pops);
        free(dequeues);
        free(removes);
        clearStack(S);
        clearQueue(Q);
    }
    

    for(int i=0; i<N;i++){
        if(output[i] == PILHA){
            printf("pilha");
        }else if(output[i] == FILA){
            printf("fila");
        }else if(output[i] == INDEFINIDO){
            printf("indefinido");
        }else if(output[i] == IMPOSSIVEL){
            printf("impossivel");
        }
    }
    
    free(output);

}