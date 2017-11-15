#include "dllist.h"
#include "dlnode.h"
#include "dlnode_utility.h"
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
struct DLList * newDLL(){

}

void deleteDLL(struct DLList * * adpDLL);

void clearDLL(struct DLList * pDLL);

struct DLNode * getHeadDLL(const struct DLList * pDLL);

value_t getHeadValueDLL(const struct DLList * pDLL);

struct DLNode * getTailDLL(const struct DLList * pDLL);

value_t getTailValueDLL(const struct DLList * pDLL);

bool isEmptyDLL(const struct DLList * pDLL);

size_t getSizeDLL(const struct DLList * pDLL);

struct DLNode * insertHeadDLL(struct DLList * pDLL, value_t value);

struct DLNode * removeHeadDLL(struct DLList * pDLL);

struct DLNode * insertTailDLL(struct DLList * pDLL, value_t value);

struct DLNode * removeTailDLL(struct DLList * pDLL);

struct DLNode * insertAfterDLL(struct DLList * pDLL,

struct DLNode * pDLN, value_t newValue);

struct DLNode * insertBeforeDLL(struct DLList * pDLL,struct DLNode * pDLN, value_t newValue);

struct DLNode * removeDLL(struct DLList * pDLL, struct DLNode * pDLN);



























