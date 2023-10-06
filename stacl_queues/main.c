#include<stdio.h>
#include"stack_queues.h"

int main(){
    int N; 
    //N - Numero de Casos
    scanf("%d",&N);
    t_stack *S;
    t_queue *Q;
    for(int i=0;i<N;i++){
        int K;
        //Numero de operações de inserção e remoção a serem efetuadas
        scanf("%d"<&K); 
        int *a = createAray(K);
        int *pops = createAray(K);
        int *enqueues = createAray(K);
        int *removes = createAray(K);

        char insert[1] = "i";
        char remove[1] = "r";
        char op[1];

        for(int j=0; j<K;j++){
            scanf("%s",&op);
            int e;
            scanf("%d",&e);
            if(strcmp(op,insert) == 0){
                pushStack(e,S);
            }else if(strcmp(op,remove) == 0){
                pops[j]=popStack(S);
                enqueues[j]=dequeue(Q);
                removes[j] = e; 
            }
        }

        for(int m=0;m<K;m++){
            if(pops[m] == removes[m]){
                //Não pode ser pilha
            }
        }
    }

}