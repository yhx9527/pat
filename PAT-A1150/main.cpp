//
//  main.cpp
//  PAT-A1150
//
//  Created by 雨含香 on 2019/11/22.
//  Copyright © 2019 雨含香. All rights reserved.
//1150 Travelling Salesman Problem (25 分)
//图的存储(邻接矩阵)，访问， set集合，多个圆的判断

#include <iostream>
#include <set>
#include <vector>
using namespace std;
int edge[230][230]={0}, n,m, minid, mindis=99999999;

void check(int i){
    int count,sum=0,flag=1;
    scanf("%d", &count);
    vector<int> route(count);
    set<int> myset;
    for(int j=0;j<count;j++){
        scanf("%d", &route[j]);
        myset.insert(route[j]);
    }
    for(int k=0;k<count-1;k++){
        if(edge[route[k]][route[k+1]]==0) flag=0;
        sum+=edge[route[k]][route[k+1]];
    }
    
    if(flag==0){
        printf("Path %d: NA (Not a TS cycle)\n", i);
    }else if(myset.size()<n || route[0]!=route[count-1]){
        printf("Path %d: %d (Not a TS cycle)\n", i, sum);
    } else if(count==n+1){
        printf("Path %d: %d (TS simple cycle)\n", i, sum);
        if(sum<mindis){
            mindis=sum;
            minid=i;
        }
    } else {
        printf("Path %d: %d (TS cycle)\n", i, sum);
        if(sum<mindis){
            mindis=sum;
            minid=i;
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    while(m--){
        int t1, t2, d;
        scanf("%d %d %d",&t1, &t2, &d);
        edge[t1][t2]=edge[t2][t1]=d;
    }
    int k;
    cin >> k;
    for(int i=1;i<=k;i++){
        check(i);
    }
    
    printf("Shortest Dist(%d) = %d", minid, mindis);
    return 0;
}
