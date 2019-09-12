//
//  main.cpp
//  PAT-A1009
//
//  Created by 雨含香 on 2019/9/11.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1009 Product of Polynomials
//没必要开多余的数组,读第二行时可以边读边计算了

#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {
    int num1,num2;
    double a[1010]={0},c[2010]={0};
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
        if(coefficient != 0){
            for(int i=0;i<=1000;i++){
                if(a[i]!=0){
                    c[i+exponent]+=a[i]*coefficient;
                }
            }
        }
    }
    int count=0;
    
    for(int i=2000;i>=0;i--){
        if(c[i]!=0){
            count++;
        }
    }
    printf("%d",count);
    for(int i=2000;i>=0;i--){
        if(c[i]!=0){
            printf(" %d %.1lf", i, c[i]);
        }
    }
    return 0;
}
