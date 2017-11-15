#ifndef MATHESI_H
#define MATHESI_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef int value_t;

bool isPrime(unsigned int n);
void printPrimeFactor(unsigned int number, bool showPower);
unsigned gcd(unsigned a, unsigned b);
void printGCD(unsigned a, unsigned b);
void arrayIntPrint(const int data [], unsigned nbElem);
void arrayIntSort(int data [], unsigned nbElem, bool ascending);
bool isSorted(int tab[],unsigned x);
size_t strlen (const char *str);
int strcmp( const char *lhs, const char *rhs );
void cmptest(const char* lhs, const char* rhs);
char *strcpy( char *dest, const char *src );
void testStrcmp(const char* lhs, const char* rhs);

//TD2
unsigned * primeFactorsA (unsigned * count, unsigned number);
unsigned primeFactorsB(unsigned * * factor, unsigned * * multiplicity, unsigned number);
struct PrimeFactor * primeFactorsC(unsigned * count, unsigned number);
struct PrimeFactorization;
void primeFactorsD(struct PrimeFactorization * pf);




#endif // MATHESI_H
