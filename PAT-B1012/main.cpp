//
//  main.cpp
//  PAT-B1012
//
//  Created by 雨含香 on 2019/9/8.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1012 数字分类
#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {
    int num,res[5]={0},count[5]={0},a;
    scanf("%d", &num);
    while(num--) {
        scanf("%d",&a);
        switch(a%5){
            case 0:
                if(a%2==0){
                    res[0]+=a;
                    count[0]++;
                }
                break;
            case 1:
                if(count[1]%2){
                    res[1]-=a;
                }else{
                    res[1]+=a;
                }
                count[1]++;
                break;
            case 2:
                res[2]+=1;
                count[2]++;
                break;
            case 3:
                res[3]+=a;
                count[3]++;
                break;
            case 4:
                if(res[4]<=a){
                    res[4]=a;
                    count[4]=1;
                }
                break;
        }
    }
    if(count[0])
        printf("%d ", res[0]);
    else printf("N ");
    if(count[1])
        printf("%d ", res[1]);
    else printf("N ");
    if(count[2])
        printf("%d ", res[2]);
    else printf("N ");
    if(count[3])
        printf("%.1f ", (double)res[3]/count[3]);
    else printf("N ");
    if(count[4])
        printf("%d", res[4]);
    else printf("N");
    return 0;
}
