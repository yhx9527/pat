//============================================================================
// Name        : A1156.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Sexy Primes

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    int sqr = (int)sqrt(1.0*n);
    for(int i=2;i<=sqr;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main() {
    int num;
    scanf("%d",&num);
    if(isPrime(num)){
        if(isPrime(num-6)){
            printf("Yes\n%d", num-6);
        } else if(isPrime(num+6)){
            printf("Yes\n%d", num+6);
        }
    } else {
        printf("No\n");
        while(true){
            if(isPrime(num)&&(isPrime(num-6)||isPrime(num+6))){
                printf("%d", num);
                return 0;
            }
            num++;
        }
    }
    return 0;
}

