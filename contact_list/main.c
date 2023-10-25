#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "contact_list.h"

int main()
{
    char op;
    t_skiplist sl;
    initSList(&sl);
    t_pointer res;
    for (;;)
    {
        op = getchar();
        if(op=='0'){
            clearSlist(&sl);
            return 0;
        }
        char key[11];
        char number[10];
        switch (op)
        {
        case 'I': 
            scanf("%s", key);
            scanf("%s", number);
            res = searchSlist(key,&sl);
            if(res!=NULL){
                printf("Contatinho ja inserido\n");
            }else{
                insertSlist(key, number, &sl);
            }
            break;
        case 'P':
            scanf("%s", key);
            res = searchSlist(key, &sl);
            if (res == NULL)
            {
                printf("contatinho nao encontrado\n");
            }
            else
            {
                printf("Contatinho encontrado: telefone %s\n", res->value);
            }
            break;
        case 'D':
            scanf("%s", key);
            int del;
            del = deleteSlist(key, &sl);
            if (del == 1)
            {
                printf("Operacao invalida: contatinho nao encontrado\n");
            }
            break;
        
        case 'A':
            int found;
            scanf("%s", key);
            scanf("%s", number);
            found = modifySl(key, number, &sl);
            if(found == 0){
                printf("Operacao invalida: contatinho nao encontrado\n");
            }
            break;
        }
    }
}