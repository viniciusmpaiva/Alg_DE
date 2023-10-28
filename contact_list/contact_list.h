#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H
#define SKIPLIST_MAX_LEVEL 6

typedef struct t_node *t_pointer;


typedef struct t_node{
    char key[11];
    char* value;
    t_pointer *forward;
}t_node;


typedef struct t_skiplist{
    int level;
    int size;
    t_pointer header;
}t_skiplist;


void initSList(t_skiplist *sl);
int insertSlist(char* key,char* value, t_skiplist *sl);
t_pointer searchSlist(char* key, t_skiplist *sl);
void deleteSlist(char* key, t_skiplist *sl);
static void freeNode(t_node *x);
int modifySl(char* key,char* value,t_skiplist *sl);
void clearSlist(t_skiplist *sl);

#endif