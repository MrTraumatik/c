#include "dllist.h"
#include "dlnode.h"
#include "dlnode_utility.h"
#include "dllist_utility.h"
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "value_t.h"
//========================================
//TD3 - liste bi-chainee
//========================================
struct DLNode{
    struct DLNode *previous;
    struct DLNode *next;
    value_t value;
};
struct DLNode * newDLN(value_t value){
    struct DLNode* newNode = malloc(sizeof(struct DLNode));
    if(newNode==0){
        errno=EDLNMEMORYFAIL;
        return NULL;
    }
    newNode->previous=NULL;
    newNode->next=NULL;
    newNode->value=value;
    return newNode;
}
void deleteDLN(struct DLNode * * adpDLN){
    free(adpDLN);
    *adpDLN=NULL;
}
struct DLNode * getPreviousDLN(const struct DLNode * pDLN){
    return pDLN->previous;
}
struct DLNode * getNextDLN(const struct DLNode * pDLN){
    return pDLN->next;
}
value_t getValueDLN(const struct DLNode * pDLN){
    return pDLN->value;
}
void setPreviousDLN(struct DLNode * pDLN, struct DLNode * pNewPrevious){
    pDLN->previous=pNewPrevious->previous;
}
void setNextDLN(struct DLNode * pDLN, struct DLNode * pNewNext){
    pDLN->next=pNewNext->next;
}
void setValueDLN(struct DLNode * pDLN, value_t newValue){
    pDLN->value=newValue;
}
struct DLNode * forwardDLN(struct DLNode * pDLN, int value){
    if(value>=0){
        while(pDLN!=NULL&&value>0){
            pDLN=pDLN->next;
            value--;
        }
    }else{
        while(pDLN!=NULL&&value<0){
            pDLN=pDLN->previous;
            value++;
        }
    }

    if(pDLN==NULL){
        return NULL;
    }
    return pDLN;
}
struct DLNode * backDLN(struct DLNode * pDLN, int value){
    if(value>=0){
        while(pDLN!=NULL&&value>0){
            pDLN=pDLN->previous;
            value--;
        }
    }else{
        while(pDLN!=NULL&&value<0){
            pDLN=pDLN->next;
            value++;
        }
    }
    if(pDLN==NULL){
        return NULL;
    }
    return pDLN;
}

//=============================================
struct DLList{
    struct DLNode * head;
    struct DLNode * tail;
};

struct DLList * newDLL(){
    struct DLList *liste = malloc(sizeof(struct DLList));
    if(liste==0){
        errno=EDLLMEMORYFAIL;
        return NULL;
    }
    return liste;
}
void deleteDLL(struct DLList * * adpDLL){
    free(adpDLL);
    adpDLL=NULL;
}
void clearDLL(struct DLList * pDLL){
    free(pDLL);
    pDLL->head=NULL;
    pDLL->tail=NULL;
}
struct DLNode * getHeadDLL(const struct DLList * pDLL){
    if(pDLL->head==NULL){
        return NULL;
    }
    return pDLL->head;
}
value_t getHeadValueDLL(const struct DLList * pDLL){
    if(pDLL->head==NULL){
        errno=EDLLEMPTY;
        return errno;
    }
    return pDLL->head->value;
}
struct DLNode * getTailDLL(const struct DLList * pDLL){
    if(pDLL->tail==NULL){
        return NULL;
    }
    return pDLL->tail;
}
value_t getTailValueDLL(const struct DLList * pDLL){
    if(pDLL->tail==NULL){
        errno=EDLLEMPTY;
        return errno;
    }
    return pDLL->tail->value;
}
bool isEmptyDLL(const struct DLList * pDLL){
    return pDLL->head==NULL;
}
size_t getSizeDLL(const struct DLList * pDLL){
    int size=0;
    struct DLNode *node=pDLL->head;
    while(node!=NULL){
        size++;
        node = node->next;
    }
    return size;
}
struct DLNode * insertHeadDLL(struct DLList * pDLL, value_t value){
    struct DLNode *node = malloc(sizeof(struct DLNode));
    node->value=value;
    node->previous=NULL;
    node->next=NULL;

    if(pDLL->head==NULL)
    {
        pDLL->head=node;
        pDLL->tail=node;
    }else
    {
        node->next=pDLL->head->next;
        pDLL->head=node;
    }

    return node;

}
struct DLNode * removeHeadDLL(struct DLList * pDLL){
    if(pDLL->head==NULL){
        errno=EDLLEMPTY;
        return NULL;
    }
    struct DLNode *node=pDLL->head->next;
    if(node!=NULL){
        node->previous=NULL;
    }
    deleteDLN((&pDLL->head));
    pDLL->head=node;
    return node;
}
struct DLNode * insertTailDLL(struct DLList * pDLL, value_t value){
    struct DLNode *node = newDLN(value);
    node->value=value;
    node->previous=NULL;
    node->next=NULL;

    if(pDLL->head==NULL)
    {
        pDLL->head=node;
        pDLL->tail=node;
    }else
    {
        node->previous=pDLL->tail->previous;
        pDLL->tail=node;
    }
    return node;
}
struct DLNode * removeTailDLL(struct DLList * pDLL){
    if(pDLL->tail==NULL){
        errno=EDLLEMPTY;
        return NULL;
    }
    struct DLNode *node=pDLL->tail->previous;
    if(node!=NULL){
        node->next=NULL;
    }
    deleteDLN((&pDLL->tail));
    pDLL->tail=node;
    return node;
}
struct DLNode * insertAfterDLL(struct DLList * pDLL, struct DLNode * pDLN, value_t newValue){
    struct DLNode *node = newDLN(newValue);
    struct DLNode *node2 = newDLN(pDLN->next->value);
    if(pDLL->head==NULL){
        insertHeadDLL(pDLL, newValue);
        return pDLL->head;
    }else{
        node->next=pDLN->next;
        node->previous=pDLN->next->previous;
        pDLN->next=node;
        node2->previous=node;
        return node;
    }
}
struct DLNode * insertBeforeDLL(struct DLList * pDLL,struct DLNode * pDLN, value_t newValue){
    struct DLNode *nodeToInsert = newDLN(newValue);
    struct DLNode *nodeBeforepDLN = pDLN->previous;
    if(pDLL->head==NULL){
        insertHeadDLL(pDLL, newValue);
    }else
    if(pDLL->tail==NULL){
        insertTailDLL(pDLL, newValue);
    }else{
        pDLN->previous=nodeToInsert;
        nodeBeforepDLN->next=nodeToInsert;
        nodeToInsert->previous=nodeBeforepDLN;
        nodeToInsert->next=pDLN;
    }
    return nodeToInsert;
}
struct DLNode * removeDLL(struct DLList * pDLL, struct DLNode * pDLN){
    if(pDLL->head==NULL){
        return NULL;
    }
    struct DLNode *node=pDLN->next;
    if(pDLN==pDLL->head){
        removeHeadDLL(pDLL);
    }else if(pDLN==pDLL->tail){
        removeTailDLL(pDLL);
    }else{
        pDLN -> previous -> next = pDLN -> next;
        pDLN -> next -> previous = pDLN -> previous;
        deleteDLN(&pDLN);
    }
    return node;
}

value_t * to_arrayDLL(size_t * size, const struct DLList * pDLL){
    if(isEmptyDLL(pDLL)){
        size=0;
        return NULL;
    }
    struct DLNode *node=pDLL->head;
    value_t * tab=malloc(sizeof(value_t)**size);
    //tab[0]=node->value;
    int i=0;
    while(node!=NULL){
        tab[i]=node->value;
        node=node->next;
        i++;
    }
    return tab;
}

value_t * to_array_reverseDLL(size_t * size, const struct DLList * pDLL){
    if(isEmptyDLL(pDLL)){
        size=0;
        return NULL;
    }
    struct DLNode *node = pDLL->tail;
    value_t *tab=malloc(sizeof(value_t)**size);
    int i=0;
    while(node!=NULL){
        tab[i]=node->value;
        node=node->previous;
        i++;
    }
    return tab;
}

struct DLList * reverseDLL(const struct DLList * pDLL){
    struct DLList *liste=malloc(sizeof(struct DLList));
    if(liste ==NULL){
        errno=EDLLMEMORYFAIL;
        return NULL;
    }
    liste=newDLL();
    struct DLNode *node=malloc(sizeof(struct DLNode));

    struct DLNode *nodeTemp=malloc(sizeof(struct DLNode));
    node=newDLN(pDLL->tail->value);
    insertHeadDLL(liste,node->value);
    while(node->previous!=NULL){
        nodeTemp=node;
        node=node->previous;
        insertAfterDLL(liste,nodeTemp,node->value);
    }
    /*
    node=pDLL->head;
    while(node!=NULL){
        insertHeadDLL(liste, node->value);
        node=node->next;
    }
    */
    return liste;
}

bool isSorted(struct DLList *liste){
    struct DLNode *node=malloc(sizeof(struct DLNode));
    node=liste->head;
    bool isSmaller=true;
    while(isSmaller){
        isSmaller=node->value<node->next->value;
        node=node->next;
    }
    return isSmaller;
}
bool inGoodPlace(struct DLList *liste){

}
void sortLink(struct DLList *liste){
    struct DLNode *node=malloc(sizeof(struct DLNode));
    node=liste->head;
    //met le min en head :
    while(node!=NULL){
        if(node->next->value<node->value){
            liste->head=node->next;
        }
        node=node->next;
    }
    //tri le reste
    while(!isSorted(liste)){

    }


}

void sortDLL(struct DLList * pDLL, int (* comp)(value_t, value_t), enum SortingMethod sm){
    if(sm=SORT_BY_CHANGING_LINK){
        //le maillage des elmt de la liste est modifié, pas les valeurs contenues
    }else{
        //les valeurs contenues dans les elmts sont modifiés, pas le maillage
    }
}


struct DLList * mergeDLL(const struct DLList * pDLL_l, const struct DLList * pDLL_r, int (* comp)(value_t, value_t));


























