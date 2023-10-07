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
        int *denqueues = createAray(K);
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
                enqueue(e,Q);
            }else if(strcmp(op,remove) == 0){
                pops[j]=popStack(S);
                denqueues[j]=dequeue(Q);
                removes[j] = e; 
            }
        }
        int same_pops = 0;
        int same_dequeues = 0;
        for(int m=0;m<K;m++){
            if(pops[m] == removes[m]){
                same_pops++;
            }else if(denqueues[m] == removes[m]){
                same_dequeues++;
            }
        }
        if(same_pops == K && same_dequeues != K){
            printf("pilha");
        }else if(same_dequeues == K && same_pops !=K){
            printf("fila");
        }else if (same_dequeues ==K && same_pops ==K){
            printf("indefinido");
        }else{
            printf("impossivel");
        }
    }

}