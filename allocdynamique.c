#include "allocdynamique.h"
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

//========================================
//TD2 -Allocation dynamique et structure
//========================================
/*
Crée et retourne une zone dynamiquement allouée d’unsigned dont le contenu,
un tableau d’unsigned, est l’ensemble des facteurs premiers du paramètre number.
Le nombre d’unsigned formant la zone retournée est stocké dans l’entier dont l’adresse
est fournie via le pointeur count.
Les facteurs premiers sont rangés dans l’ordre croissant, c’est-à-dire que le plus petit est
à l’indice 0 du tableau retourné. Si un nombre apparaît plusieurs fois dans la décomposition
en facteurs premiers de number, il apparaît autant de fois dans le tableau retourné.
*/
unsigned * primeFactorsA (unsigned * count, unsigned number){
    unsigned * tabPrimeFact=NULL; //le pointeur va servir de tableau
    int indice=0;
    unsigned numTemp=number;
    while(number%2==0){
        count++;
        number = number/2;
    }
    for(int i = 3;i<sqrt(number);i=i+2){
        while(number%i==0){
            count++;
            number=number/i;
        }
    }
    if(number>2){
        count++;
    }
    printf("count = %d \n", *count);
    number = numTemp;
    tabPrimeFact = malloc(*count*sizeof(int));

    while(number%2==0){
        tabPrimeFact[indice]=2;
        indice++;
        number = number/2;
    }
    for(int i = 3;i<sqrt(number);i=i+2){
        while(number%i==0){
            tabPrimeFact[indice]=i;
            indice ++;
            number=number/i;
        }
    }
    if(number>2){
        tabPrimeFact[indice]=number;
        indice ++;
    }
    *count = 0;
    for(int i=0 ; i < indice  ; i++){
        printf("%d-",tabPrimeFact[i]);
        count++;
    }
    printf("\n");
    printf("count = %d \n", *count -1);
    return  tabPrimeFact;

    //free(tabPrimeFact);
    //doit etre géré par l'appellant de la fction
}

//décompose number en produit de facteurs premiers. stocke les facteurs premiers de number,
//rangés dans l’ordre croissant, dans une première zone qu’elle
//alloue dynamiquement, tandis que leurs multiplicités sont rangées dans une seconde zone
//qu’elle alloue également dynamiquement. Ces deux zones dynamiques sont des tableaux
//dynamiques d’unsigned. Les adresses de ces deux tableaux sont écrites par la fonction
//primeFactorsB dans les deux pointeurs d’unsigned dont les adresses sont fournies via
//les paramètres factor et multiplicity. La valeur retournée est le nombre d’éléments
//de chacun de ces tableaux.


//unsigned primeFactorsB(unsigned * * factor, unsigned * * multiplicity, unsigned number){

//}

struct PrimeFactor{
    unsigned value;
    unsigned multiplicity;
};
//alloue une zone mémoire dynamique où elle range de manière contiguë des struct PrimeFactor.
//Elle retourne l’adresse du premier élément de ce tableau dynamique de struct PrimeFactor.
//Le contenu du tableau dynamique est l’ensemble des facteurs premiers du paramètre number.
//À chaque facteur premier correspond un élément du tableau : son champ value renferme sa valeur,
//son champ multiplicity sa multiplicité. Le nombre d’éléments de ce tableau, c’est-à-dire le nombre
//de facteurs premiers distincts, est stocké dans l’entier non signé dont l’adresse est fournie
//à la fonction via le paramètre count.
struct PrimeFactor * primeFactorsC(unsigned * count, unsigned number){
    struct PrimeFactor * tab=NULL;
    int indice =0;
    int m=0;
    tab=malloc(*count * sizeof(number));
    while(number%2==0){
        m++;
        tab[indice].value=2;
        tab[indice].multiplicity=m;
        number = number/2;
    }
    for(int i = 3;i<sqrt(number);i=i+2){
        if(number%i==0){
            indice++;
            m=0;
            while(number%i==0){
                m++;
                tab[indice].value=i;
                tab[indice].multiplicity=m;
                number=number/i;
            }
        }
    }
    if(number>2){
        indice++;
        tab[indice].value=number;
        tab[indice].multiplicity=1;
    }
    for(int i=0;i<=indice;i++){
        printf("{%d,%d}",tab[i].value,tab[i].multiplicity);
        count++;
    }
    printf("\ncount = %d\n",*count/2);
    return (struct PrimeFactor *) tab;

}

struct PrimeFactorization{
    unsigned number;
    unsigned count;
    struct PrimeFactor * primeFactors;
};

//décompose en facteurs premiers le champ number de la structure pointée par son paramètre pf.
//Elle stocke dans son champ count le nombre de facteurs premiers distincts.
//Elle alloue un tableau dynamique de struct PrimeFactor dont elle stocke
//l’adresse du premier élément dans le champ primeFactors de la
//struct PrimeFactorization pointée par pf. Le contenu de ce tableau dynamique
//est l’ensemble des facteurs premiers distincts du nombre pf->number
void primeFactorsD(struct PrimeFactorization *pf){
    unsigned number = pf->number;
    unsigned num = number;
    unsigned count = pf->count;
    struct PrimeFactor * tab = pf->primeFactors;
    int indice =0;
    int m=0;
    tab=malloc( sizeof(number));
    while(number%2==0){
        m++;
        tab[indice].value=2;
        tab[indice].multiplicity=m;
        number = number/2;
    }
    for(int i = 3;i<sqrt(number);i=i+2){
        if(number%i==0){
            indice++;
            m=0;
            while(number%i==0){
                m++;
                tab[indice].value=i;
                tab[indice].multiplicity=m;
                number=number/i;
            }
        }
    }
    if(number>2){
        indice++;
        tab[indice].value=number;
        tab[indice].multiplicity=1;
    }
    printf("{%d,",num);
    for(int i=0;i<=indice;i++){
        count++;
    }
    printf("%d,",count);
    for(int i=0;i<=indice;i++){
        printf("{%d,%d}",tab[i].value,tab[i].multiplicity);
    }
    printf("}\n");
}
