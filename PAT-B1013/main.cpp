//
//  main.cpp
//  PAT-B1013
//
//  Created by 雨含香 on 2019/10/2.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1013. 数素数

#include <iostream>
#include <cstdio>
#include <cmath>

bool isPrime(int n){
    bool flag=true;
    int sqr=(int)round(sqrt(1.0*n));
    for(int i=2;i<=sqr;i++){
        if(n%i==0){
            return false;
        }
    }
    return flag;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int m,n,count=0,i=2,j=0;
    scanf("%d %d", &m, &n);
    while(1){
        if(isPrime(i)){
            count++;
            if(count>=m && count<=n){
                j++;
                printf("%d", i);
                if(j % 10==0){
                    printf("\n");
                } else if(count != n){
                    printf(" ");
                }
            } else if(count > n){
                break;
            }
        }
        i++;
    }
    return 0;
}
