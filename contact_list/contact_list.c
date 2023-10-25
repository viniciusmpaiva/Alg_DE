#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include <string.h>
#include "contact_list.h"


void initSList(t_skiplist *sl){
    t_pointer header = (t_pointer) malloc(sizeof(t_node));
    sl->header = header;
    strcpy(header->key, " ");
    header->forward =(t_pointer*) malloc(sizeof(t_node*) * (SKIPLIST_MAX_LEVEL +1 ) );
    for(int i=0; i<=SKIPLIST_MAX_LEVEL; i++){
        header->forward[i] = sl->header;
    }
    sl->level = 1;
    sl->size = 0;
}


static int randLevel(){
    int level = 1;
    while(rand()<RAND_MAX/2 && level < SKIPLIST_MAX_LEVEL){
        level++;
    }
    return level;
}

int insertSlist(char* key, char* value, t_skiplist *sl){
    t_pointer update[SKIPLIST_MAX_LEVEL+1];
    t_pointer x = sl->header;
    int level;
    for(int i=sl->level;i>=1;i--){
        while(x->forward[i] != sl->header && strcmp(x->forward[i]->key,key)<0){
            x = x->forward[i];
        }
        update[i] = x;
    }
    if (x->forward[1]!=sl->header)  x->forward[1];

    if(strcmp(key,x->key) == 0 && x != sl->header){ //Arrumar
        return 0;
    }else{
        level = randLevel();
        if(level>sl->level){
            for(int i=sl->level+1;i<=level;i++){
                update[i] = sl->header;
            }
            sl->level = level;
        }
        x =(t_pointer)malloc(sizeof(t_node));

        strcpy(x->key,key);//Arrumar

        x->value = strdup(value);
        x->forward = (t_pointer*)malloc(sizeof(t_pointer) * (level+1));

        for(int i=1;i<=level;i++){
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
    return 1;
}

t_pointer searchSlist(char* key, t_skiplist *sl){
    t_pointer x = sl->header;
    for(int i=sl->level;i>=1;i--){
        while(strcmp(x->forward[i]->key,key)<0 && x->forward[i] != sl->header){
            x=x->forward[i];
        }
    }
    if(strcmp(x->forward[1]->key, key) == 0 && x->forward[1] !=sl->header){
        return x->forward[1];
    }
    return NULL;
}

static void freeNode(t_node *x){
    if(x){
        free(x->forward);
        free(x);
    }
}

int deleteSlist(char* key, t_skiplist *sl){
    t_pointer update[SKIPLIST_MAX_LEVEL+1];
    t_pointer x = sl->header;
    for(int i=sl->level;i>=1;i--){
        while(strcmp(x->forward[i]->key,key)<0 && x->forward[i] !=sl->header){
            x=x->forward[1];
        }
        update[i] = x;
    }

    if(x->forward[1]!=sl->header)    x=x->forward[1];
    if(strcmp(x->key, key) == 0 && x!=sl->header){
        for(int i=1;i<=sl->level;i++){
            if(update[i]->forward[i] !=x){
                break;
            }
            update[i] ->forward[1] = x->forward[i];
        }
        free(x->value);
        freeNode(x);

        while(sl->level>1 && sl->header->forward[sl->level] == sl->header){
            sl->level--;
        }
        return 0;
    }
    return 1;
}

int modifySl(char* key, char* value,t_skiplist *sl){
    t_pointer x = searchSlist(key,sl);
    if(x==NULL){
        return 0;     
    }
    x->value = strdup(value);
    return 1;
}

void clearSlist(t_skiplist *sl){
    t_pointer x = sl->header->forward[0];
    while(x!=NULL && x!=sl->header){
        t_pointer nxt = x->forward[0];
        freeNode(x);
        x=nxt;
    }
}

