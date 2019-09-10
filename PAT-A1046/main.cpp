//
//  main.cpp
//  PAT-A1046
//
//  Created by 雨含香 on 2019/9/10.
//  Copyright © 2019 雨含香. All rights reserved.
//
// Shortest Distance
//需注意超时，因为在最多查询次数下（10^4），如果通过循环来计算最短距离(10^5)，如此会有10^9次操作，必然会超时

#include <iostream>
#include <cstdio>
const int max=100002;
int main(int argc, const char * argv[]) {
    int num;
    scanf("%d", &num);
    int dis[max]={};//保存相邻点的距离
    int calcu[max]={};//保存每个点到原点的距离
    int sum=0;
    for(int i=1;i<=num;i++){
        scanf("%d", &dis[i]);
        calcu[i]=sum;
        sum+=dis[i];
    }
    int count=0;
    scanf("%d", &count);
    int spot1,spot2;
    while(count--){
        scanf("%d%d", &spot1, &spot2);
        int temp=spot1;
        if(temp>spot2) {
            spot1=spot2;
            spot2=temp;
        }
        int length=calcu[spot2]-calcu[spot1];
//        for(int i=spot1;i<spot2;i++){ //将会导致超时
//            length+=dis[i];
//        }
        if(length>(sum-length)){
            length=sum-length;
        }
        printf("%d\n", length);
    }
    return 0;
}
