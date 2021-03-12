//#ifndef DLNK_LIST_H
//#define DLNK_LIST_H

struct dlnk_list{
    int No;
    struct dlnk_list *prev;
    struct dlnk_list *next;
};
typedef struct dlnk_list dlnkList;

dlnkList* dlnk_create(void);
dlnkList* dlnk_add( dlnkList *list, dlnkList *item);
dlnkList* dlnk_rm_last( dlnkList *list);
dlnkList* dlnk_rm( dlnkList *list, int No);
dlnkList* dlnk_free( dlnkList *list);
dlnkList* dlnk_find(dlnkList *list, int No);
int dlnk_get_size(void);

//#endif
