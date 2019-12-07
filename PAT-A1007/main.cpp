//
//  main.cpp
//  PAT-A1007
//
//  Created by 雨含香 on 2019/10/9.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1007 Maximum Subsequence Sum

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=10010;
int arr[maxn];
int dp[maxn];
int pre[maxn]={0};

int main(int argc, const char * argv[]) {
    int num;
    bool flag=false;
    scanf("%d", &num);
    for(int i=0;i<num;i++){
        scanf("%d", &arr[i]);
        if(arr[i]>=0) flag=true;
    }
    if(!flag) {
        printf("0 %d %d", arr[0], arr[num-1]);
        return 0;
    }
    dp[0]=arr[0];
    pre[0]=0;
    for(int i=1;i<num;i++){
        dp[i]=max(arr[i], dp[i-1]+arr[i]);
        if(dp[i]==arr[i]){
            pre[i]=i;
        } else {
            pre[i]=pre[i-1];
        }
    }
    int maxNum=dp[0], first=0, last=0;
    for(int i=0;i<num;i++){
        if(dp[i]>maxNum){
            maxNum = dp[i];
            last = i;
            first = pre[i];
        }
    }
    printf("%d %d %d", maxNum, arr[first], arr[last]);
    return 0;
}
