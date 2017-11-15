#ifndef DLNODE_H
#define DLNODE_H
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "value_t.h"
#include "dllist.h"
enum DLNError{
 //Erreur lors d’une allocation mémoire d’un élément de liste.
 EDLNMEMORYFAIL = 50
};

struct DLNode;
struct DLNode * newDLN(value_t value);
void deleteDLN(struct DLNode * * adpDLN);
struct DLNode * getPreviousDLN(const struct DLNode * pDLN);
struct DLNode * getNextDLN(const struct DLNode * pDLN);
value_t getValueDLN(const struct DLNode * pDLN);
void setPreviousDLN(struct DLNode * pDLN,
struct DLNode * pNewPrevious);
void setNextDLN(struct DLNode * pDLN, struct DLNode * pNewNext);
void setValueDLN(struct DLNode * pDLN, value_t newValue);

#endif // DLNODE_H
