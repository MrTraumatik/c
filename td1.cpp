#include <math.h>

bool isPrime(unsigned int n){
     if(n<=1){
        return false;
    }
    int i = 2;
    while(n%i!=0 && i<sqrt(n)){
        i++;
    }
    return i=sqrt(n);
 }
