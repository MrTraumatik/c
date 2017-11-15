#ifndef DLNODE_UTILITY_H
#define DLNODE_UTILITY_H
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "value_t.h"


struct DLNode * forwardDLN(struct DLNode * pDLN, int value);
struct DLNode * backDLN(struct DLNode * pDLN, int value);

#endif // DLNODE_UTILITY_H
