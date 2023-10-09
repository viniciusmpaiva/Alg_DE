#ifndef STACK_QUEUES_H
#define STACK_QUEUES_H

typedef struct t_node_stack *t_pointer_stack;

typedef struct t_node_stack{
    int element;
    t_pointer_stack nxt;
} t_node_stack;


typedef struct {
    t_pointer_stack top;
    int count;
} t_stack;

typedef struct t_node_queue *t_pointer_queue;

typedef struct t_node_queue{
    int element;
    t_pointer_queue nxt;
}t_node_queue;

typedef struct t_queue{
    t_pointer_queue front;
    t_pointer_queue rear;
}t_queue;



void initStack(t_stack *S);
void pushStack(int e, t_stack *S);
int emptyStack(t_stack *S);
int popStack(t_stack *S);
int *createAray(int n);
void enqueue(int e, t_queue *Q);
int dequeue(t_queue *Q);
void clearStack(t_stack *S);
void clearQueue(t_queue *Q);

#endif