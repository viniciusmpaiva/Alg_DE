#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack_queues.h"

#define PILHA 1
#define FILA 2
#define INDEFINIDO 3
#define IMPOSSIVEL 4



void initStack(t_stack *S){
    S->top = NULL;
    S->count = 0;
}




void pushStack(int e, t_stack *S){
    initStack(S);
    t_pointer_stack a = (t_pointer_stack) malloc(sizeof(t_node_stack));
    if(a==NULL){
        printf("There's no space :(");
        return;
    }

    a->element = e;
    a->nxt = S->top;
    S->top = a;
    S->count++;
}


int emptyStack(t_stack *S){
    if(S->top==NULL){
        return 1;
    }
    return 0;
}



int popStack(t_stack *S){
    if(emptyStack(S)){
        printf("Stack is empty!");
        return 0;
    }

    t_pointer_stack a = S->top;
    int e = a->element;

    S->top = S->top->nxt;
    free(a);

    S->count --;
    return e;
}

void enqueue(int e, t_queue *Q){
    t_pointer_queue a =(t_pointer_queue) malloc(sizeof(t_node_queue));
    a->element = e;
    a->nxt = NULL;
    if(Q->rear == NULL){
        Q->front = a;
        Q->rear = a;
    }else{
        Q->rear->nxt = a;
        Q->rear = Q->rear->nxt;
    }
}

int dequeue(t_queue*Q){
    if(Q->front == NULL){
        printf("Queue is empty");
        return 0;
    }
    t_pointer_queue temp;
    temp = Q->front;
    Q->front = Q->front->nxt;
    int e = temp->element;
    free(temp);
    return e;
}

int *createAray(int n){
    int *a = (int*)malloc(sizeof(int)*n);
    if(a==NULL){
        printf("No space :(");
        return NULL;
    }
    return a;
}


void clearStack(t_stack *S){
    t_pointer_stack a = S->top;
    if(a == NULL){
        printf("Stack is empty");
        return;
    }
    while(a!=NULL){
        t_pointer_stack temp = a;
        a = a->nxt;
        free(temp);
    }
    S->top = NULL;
}

void clearQueue(t_queue *Q){
    t_pointer_queue a = Q->front;
    if(a==NULL){
        printf("Queue is empty");
        return;
    }
    while(a!=NULL){
        t_pointer_queue temp = a;
        a = a->nxt;
        free(temp);
    }
    Q->front = NULL;
    Q->rear = NULL;
}






