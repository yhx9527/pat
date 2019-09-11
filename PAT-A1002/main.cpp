//
//  main.cpp
//  PAT-A1002
//
//  Created by 雨含香 on 2019/9/11.
//  Copyright © 2019 雨含香. All rights reserved.
//
// 1002 A+B for Polynomials
#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {
    int num1,num2;
    double a[1010]={0},b[1010]={0};
    scanf("%d", &num1);
    while(num1--){
        int exponent; double coefficient;
        scanf("%d %lf", &exponent, &coefficient);
        a[exponent] = coefficient;
    }
    scanf("%d", &num2);
    while(num2--){
        int exponent; double coefficient;
        scanf("%d %lf", &exponent, &coefficient);
        b[exponent] = coefficient;
    }
    int count=0;
    for(int i=0;i<=1000;i++){
        a[i]=a[i]+b[i];
        if(a[i]!=0) count++;
    }
    printf("%d", count);
    for(int i=1000;i>=0;i--){
        if(a[i] != 0){
            printf(" %d %.1lf", i, a[i]);
            count--;
//            if(count != 0) printf(" ");
        }
    }
    
    return 0;
}
