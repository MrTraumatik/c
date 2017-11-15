#include "mathesi.h"
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
//========================================
//TD1 - Fonction et tableau
//========================================
bool isPrime(unsigned int n){
    int cpt = 0;
    int i = 2;
    while(n%i!=0 && i<=sqrt(n)){
        i++;
        cpt++;
    }
    return i>sqrt(n);
}
void printPrimeFactor(unsigned int number, bool showPower){
    int cpt = 0;
    if(showPower){
        while(number%2==0){
            number = number/2;
            cpt ++;
        }
        printf("%d", 2);
        if(cpt>1){
            printf("^%d", cpt);
        }
        cpt =0;
        for(int i=3;i<sqrt(number);i=i+2){
            while(number%i==0){
                number=number/i;
                cpt++;
            }
            printf("%d x ", i);
            if(cpt>1){
                printf("^%d", cpt);
            }
            if(number>2){
                printf("%d", number);
            }
        }

    }else{
        while(number%2==0){
            printf("%d x ", 2);
            number = number/2;
        }
        for(int i = 3;i<sqrt(number);i=i+2){
            while(number%i==0){
                printf("%d x ", i);
                number=number/i;
            }
        }
        if(number>2){
            printf("%d", number);
        }
    }
}
unsigned gcd(unsigned a, unsigned b){
    unsigned int res;
    unsigned int temp;

    while(res>0){
        if(a<b){
            temp =a;
            a= b;
            b= temp;
        }
        res = a%b;
        a= b;
        b= res;
    }
    return a;
}
void printGCD(unsigned a, unsigned b){
    unsigned int x = a;
    unsigned int y =b;
    for(int i =0;i<6;i++){
        for(int j=0;j<3;j++){
            printf("gcd(%3d, %3d) = %2d", x, y, gcd(x,y));
            if(j!=2){
                printf("   | ");
            }
            y=y-5;
        }
        printf("\n");
        x=x+3;
        y=b;
    }
}
void arrayIntPrint(const int data [], unsigned nbElem){
    for(unsigned int i=0;i<nbElem;i++){
        printf("%d  ",data[i]);
    }
    printf("\n");
}
void arrayIntSort(int data [], unsigned nbElem, bool ascending){
    int tmp;
    if(ascending){
        while(!isSorted(data, nbElem)){
            for(unsigned int i=0;i<nbElem-1;i++){
                if(data[i]>data[i+1]){
                    tmp = data[i];
                    data[i]=data[i+1];
                    data[i+1]=tmp;
                }
            }
        }
    }else{
        while(!isSorted(data, nbElem)){
            for(unsigned int i=0;i<nbElem-1;i++){
                if(data[i]<data[i+1]){
                    tmp =data [i];
                    data[i]=data[i+1];
                    data[i+1]=tmp;
                }
            }
        }
    }
    for(unsigned int i=0;i<nbElem;i++) {
        printf("%d  ",data[i]);
    }
}
bool isSorted(int tab[],unsigned x){
    unsigned int chck=0;
    for(unsigned int i=0;i<x-1;i++){
        if(tab[i]>tab[i+1]){
            chck++;
        }
    }
    return chck<1;
}
size_t strlen(const char *str){
    char j;
    int i=0;
    int cpt=0;
    while(j!=0){
        j=str[i];
        cpt++;
        i++;
    }
    return cpt;
    /*
    size_t length = sizeof &str;
    return length-1; //sizeof compte le 0 de départ, pas strlen, donc -1
    */
}
int strcmp( const char *lhs, const char *rhs ){
    bool isSame=true;
    int i=0;
    while(isSame && *lhs!='\n' && *rhs!='\n'){
         isSame= (lhs[i]==rhs[i]);
         i++;
    }
    if(isSame && *lhs=='\n' && *rhs=='\n' ){
        return 0;
    }else if(!isSame && *lhs=='\n' && *rhs!='\n'){
        return -1;
    }else {
        return 1;
    }
}
void testStrcmp(const char* lhs, const char* rhs){
    int rc = strcmp(lhs, rhs);
    if(rc == 0)
        printf("[%s] equals [%s]\n", lhs, rhs);
    else if(rc < 0)
        printf("[%s] precedes [%s]\n", lhs, rhs);
    else if(rc > 0)
        printf("[%s] follows [%s]\n", lhs, rhs);
}
char *strcpy( char *dest, const char *src ){
    int i=0;
    while(*src!='\n'){
        dest[i]=src[i];
        i++;
    }
    dest[i]='\n';
    return dest;
}

