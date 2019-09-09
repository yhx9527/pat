//
//  main.cpp
//  PAT-B1018
//
//  Created by 雨含香 on 2019/9/8.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1018 锤子剪刀布
#include <iostream>
#include <cstdio>

int change(char c){
    if(c=='B') return 0;
    else if(c=='C') return 1;
    else return 2;
}

int main(int argc, const char * argv[]) {
    char map[3]={'B', 'C', 'J'};
    int num;
    scanf("%d", &num);
    int res1[3]={0}, res2[3]={0}; //两人的j猜拳结果,胜，平，负
    int win1[3]={0}, win2[3]={0}; //两人每个手势赢的次数，B，C, J
    char a,b;
    while(num--){
        getchar();
        scanf("%c %c", &a, &b);
        int k1=change(a);
        int k2=change(b);
        if((k1+1)%3==k2){
            res1[0]++;
            res2[2]++;
            win1[k1]++;
        } else if(k1==k2) {
            res1[1]++;
            res2[1]++;
        } else if((k2+1)%3==k1){
            res2[0]++;
            res1[2]++;
            win2[k2]++;
        }
    }
    printf("%d %d %d\n", res1[0], res1[1], res1[2]);
    printf("%d %d %d\n", res2[0], res2[1], res2[2]);
    int max1=0, max2=0;
    for(int i=0;i<3;i++){
        if(win1[max1]<win1[i]){
            max1=i;
        }
        if(win2[max2]<win2[i]){
            max2=i;
        }
    }
    printf("%c %c", map[max1], map[max2]);
    return 0;
}
