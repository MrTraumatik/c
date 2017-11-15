#ifndef ALLOCDYNAMIQUE_H
#define ALLOCDYNAMIQUE_H
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

unsigned * primeFactorsA (unsigned * count, unsigned number);
unsigned primeFactorsB(unsigned * * factor, unsigned * * multiplicity, unsigned number);
struct PrimeFactor * primeFactorsC(unsigned * count, unsigned number);
struct PrimeFactorization;
void primeFactorsD(struct PrimeFactorization * pf);


#endif // ALLOCDYNAMIQUE_H
