#include "dlnk_list.h"
#include <stdlib.h>


static int list_size;
dlnkList* dlnk_create(void){
   dlnkList *a = (dlnkList *)calloc( 1, sizeof (dlnkList));
   return a;
}
dlnkList* dlnk_add( dlnkList *list, dlnkList *item){
    if( item == NULL){
        return list;
    }

    if( list == NULL){
        list = item;
        list->prev = item;
        list->next = item;
    }else{
        dlnkList *last = list->prev;
        last->next = item;
        item->prev = last;
        list->prev = item;
        item->next = list;
        item->No = last->No+1;
    }
    ++list_size;
    return list;
}

dlnkList* dlnk_rm( dlnkList * list, int No){
    dlnkList *nxt;
    dlnkList *prv;
    dlnkList *cur;
    int i;
    if( list == NULL) return NULL;
    cur = list;
    for(i=0; i < list_size; ++i){
        prv = cur->prev;
        nxt = cur->next;
        if( cur->No == No){
            if ( list_size == 1) {
                free(cur);
                list = NULL;
           }else{
                prv->next = nxt;
                nxt->prev = prv;
           }
       }
       cur = nxt;
    }
    --list_size;
    return list;
}

dlnkList* dlnk_rm_last( dlnkList *list){
    dlnkList *last;
    dlnkList *semilast;
    if( list == NULL) return NULL;
    if( list->prev == list){
        free(list);
        list = NULL;
    }else{
        last     = list->prev;
        semilast = last->prev;
        list->prev = semilast;
        semilast->next =list;
        free(last);
    }
    --list_size;
    return list;
}

dlnkList* dlnk_free( dlnkList *list){
    while( list != NULL ){ 
        list = dlnk_rm_last(list);
    }
    return list;
}

dlnkList* dlnk_find(dlnkList *list, int No){
    if(list==NULL) return NULL;
    dlnkList *pt1 = list;
    dlnkList *pt2 = list;
    dlnkList *pt3 = NULL;
    for(int i=0; i < list_size/2; ++i){
        if(pt1->No == No){
            pt3 = pt1;
            break;
        }
        if(pt2->No == No){
            pt3 = pt2;
            break;
        }
        pt1->next = pt1->next->next;
        pt2->prev = pt2->prev->prev;
    }
    return pt3;
}

int dlnk_get_size(void){
    return list_size;
}
