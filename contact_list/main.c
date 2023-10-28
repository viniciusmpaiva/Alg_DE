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
    while(1)
    {
        op = getchar();
        if(op=='0'){
            clearSlist(&sl);
            return 0;
        }
        t_pointer search;
        char key[11];
        char number[10];
        switch (op)
        {
        case 'I': 
            scanf("%s %s", key, number);
            search = searchSlist(key,&sl);
            if(search!=NULL){
                printf("Contatinho ja inserido\n");
            }else{
                insertSlist(key, number, &sl);
            }
            break;
        case 'P':
            scanf("%s", key);
            search = searchSlist(key, &sl);
            if (search == NULL)
            {
                printf("Contatinho nao encontrado\n");
            }
            else
            {
                printf("Contatinho encontrado: telefone %s\n", search->value);
            }
            break;
        case 'R':
            scanf("%s", key);
            search = searchSlist(key,&sl);   
            if(search  == NULL){
                printf("Operacao invalida: contatinho nao encontrado\n");
                break;
            }        
            deleteSlist(key, &sl);
            break;
        
        case 'A':
            int search_int;
            scanf("%s", key);
            scanf("%s", number);
            search_int = modifySl(key, number, &sl);
            if(search_int == 0){
                printf("Operacao invalida: contatinho nao encontrado\n");
            }
            break;
        
        default:
            break;
        }
    }
    return 0;
}