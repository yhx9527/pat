//
//  main.cpp
//  PAT-A1059
//
//  Created by 雨含香 on 2019/10/2.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1059 Prime Factors

#include <iostream>
#include <cstdio>
#include <cmath>

struct factor {
    int n, count=0;
} fac[10];

const int maxn = 100010;

bool isPrime[maxn]={0};

int find_fac(int num){
    int sqr=(int)sqrt(1.0*num);
    int index=0;
    for(int i=2;i<=sqr;i++){
        if(isPrime[i]==false){
            if(num%i==0){
                fac[index].n=i;
                fac[index].count=0;
                while(num%i==0){
                    num/=i;
                    fac[index].count++;
                }
                index++;
            }
            for(int j=i*2;j<=sqr;j=j+i){
                isPrime[j]=true;
            }
        }
    }
    if(num!=1){
        fac[index].n=num;
        fac[index].count=1;
    }
    return index;
}

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d", &num);
    int len = find_fac(num);
    if(len>0){
        printf("%d=", num);
    } else {
        printf("%d=%d", num, num);
    }
    for(int i=0;i<len;i++){
        
        if(fac[i].count>0){
            printf("%d",fac[i].n);
            if(fac[i].count>1){
                printf("^%d", fac[i].count);
            }
            if(i<len-1){
                printf("*");
            }
        }
    }
    return 0;
}
