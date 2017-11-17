#include <stdio.h>
#include "mathesi.h"
#include "dlnode.h"
#include "value_t.h"
#include "dllist.h"
#include "dllist_utility.h"
#include "dlnode_utility.h"
#include "allocdynamique.h"

#include <stdlib.h>

struct PrimeFactor{
    unsigned value;
    unsigned multiplicity;
};
struct PrimeFactorization{
    unsigned number;
    unsigned count;
    struct PrimeFactor * primeFactors;
};
struct DLNode{
    struct DLNode *previous;
    struct DLNode *next;
    value_t value;
};
struct DLList{
    struct DLNode * head;
    struct DLNode * tail;
};

int main(){
    /*
    printf("small info :\n");
    printf("char : %d octets\n", sizeof(char));
    printf("int : %d octets\n", sizeof(int));
    printf("long : %d octets\n", sizeof(long));
    printf("double : %d octets\n", sizeof(double));

    printf("--------------------------\n");
    printf("Exercice 1.1 et 1.2\n");
    printf("--------------------------\n");
    printf("%d est premier ? %i\n",64,isPrime(64));
    printf("2 est premier ? ");
    printf(isPrime(2)?"True" : "False");
    printf("\n");
    printf("Les nombres premiers entre 200 et 349 :\n");
    for(int i =200;i<350;i++){
        if (isPrime(i)){
            printf("%i",i);
        }else{
            printf(".  ");
        }
        if((i==209)||(i==219)||(i==229)||(i==239)
                ||(i==249)||(i==259)||(i==269)
                ||(i==279)||(i==289)||(i==299)
                ||(i==309)||(i==319)||(i==329)
                ||(i==339)||(i==349)){
            printf(("\n"));
        }
    }
    printf("\n");

    printf("--------------------------\n");
    printf("Exercice 1.3\n");
    printf("--------------------------\n");
    printf("126 en facteur premiers : ");
    unsigned int n = 126;
    printPrimeFactor(n, true);
    printf("\n");

    printf("--------------------------\n");
    printf("Exercice 1.4 et 1.5\n");
    printf("--------------------------\n");
    unsigned a = 423;
    unsigned b = 135;
    unsigned res = gcd(a,b);
    printf("PGCD entre 423 et 125: ");
    printf("%u",res);
    printf("\n");
    printGCD(a,b);
    printf("\n");

    printf("--------------------------\n");
    printf("Exercice 1.6\n");
    printf("--------------------------\n");
    const int data[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned x = 10;
    printf("affichage d'un tableau :");
    arrayIntPrint(data, x);

    printf("--------------------------\n");
    printf("Exercice 1.7\n");
    printf("--------------------------\n");
    printf("tri duy table [6;5]");
    unsigned df =2;
    int dataNotSorted[2]={6, 5};
    arrayIntSort(dataNotSorted, df, true);
    printf("\n");

    printf("--------------------------\n");
    printf("Exercice 1.10 - strlen\n");
    printf("--------------------------\n");
    const char *str="eeeeeeee";
    size_t taille = strlen(str);
    printf("nombre de caracteres dans %s : %d \n", str, taille);

    printf("--------------------------\n");
    printf("Exercice 1.10 - strcmp\n");
    printf("--------------------------\n");
    //const char *lhs = "Comp of string test";
    //const char *rhs = "Comp of string test";
    printf("PROBLEM HERE\n");
    //testStrcmp(lhs, rhs);

    printf("--------------------------\n");
    printf("Exercice 1.10 - strcpy\n");
    printf("--------------------------\n");
    //const char* src = "This is a test";
    //char *dest="AAAA";
    //strcpy(dest, src);
    printf("PROBLEM HERE\n");

    printf("--------------------------\n");
    printf("Exercice 2.1\n");
    printf("--------------------------\n");
    unsigned nbElem =0;
    unsigned * decomposition = primeFactorsA(&nbElem, 126);
    free(decomposition);

    printf("--------------------------\n");
    printf("Exercice 2.3\n");
    printf("--------------------------\n");
    unsigned nbElem2 =0;
    struct PrimeFactor *decomposition2 = primeFactorsC(&nbElem2, 84);
    free(decomposition2);

    printf("--------------------------\n");
    printf("Exercice 2.4\n");
    printf("--------------------------\n");
    struct PrimeFactorization f={84, 0, NULL};
    primeFactorsD(&f);
    free(f.primeFactors);
    */

    printf("--------------------------\n");
    printf("Exercice 3\n");
    printf("--------------------------\n");

    value_t val = 10;
    value_t val3 = 20;
    struct DLList *liste=newDLL();
    //printf("%d",liste->head);
    printf("\n");

    insertHeadDLL(liste, val);
    printf("head :");
    printf("%d",liste->head->value);
    printf("\n");

    insertTailDLL(liste, val3);
    printf("tail:");
    printf("%d",liste->tail->value);
    printf("\n");

    struct DLNode *node=liste->head;
    value_t val2=5;
    insertAfterDLL(liste, node, val2);
    printf("%d",node->next->value);
    printf("\n");

    while(node!=NULL){
        printf("%d",node->value);
        printf("\n");
        node=getNextDLN(node);
    }

    printf("\n");
    bool mybool= isEmptyDLL(liste);
    printf(mybool?"true":"false");
    printf("\n");


    size_t *size=malloc(sizeof(*size));
    unsigned int x = 2;
    size[0]=x;
    value_t *tab=to_arrayDLL(size, liste);
    printf("%d\n",tab[2]);
    //FREEEEEE le tableau une fois fini !!!!!
/*
    size_t *size2=malloc(sizeof(*size2));
    unsigned int y = 2;
    size2[0]=y;
    value_t *tab2=to_array_reverseDLL(size2, liste);
    printf("%d", tab2[1]);
*/
    struct DLList *nListe = newDLL();
    nListe = reverseDLL(liste);
    //printf("%d",nListe->tail->value);


    //===================================
    //END
    printf("\n");
    return 0;

}










