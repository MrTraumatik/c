#ifndef DLLIST_H
#define DLLIST_H
#include <stdbool.h>
#include <stddef.h>
#include "dlnode.h"
#include <stdlib.h>
#include "value_t.h"
enum DLLError{
    EDLLMEMORYFAIL = 60,
    EDLLEMPTY
};

struct DLList;
struct DLList * newDLL();
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

#endif // DLLIST_H
