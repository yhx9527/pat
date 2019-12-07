//
//  main.cpp
//  PAT-A1142
//
//  Created by 雨含香 on 2019/12/1.
//  Copyright © 2019 雨含香. All rights reserved.
// 1142 Maximal Clique (25 分)
// 图的邻接问题

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int maxn=210;
int graph[maxn][maxn]={0};

int main(int argc, const char * argv[]) {
    int v,e;
    cin>>v>>e;
    while(e--){
        int a1,a2;
        scanf("%d%d", &a1,&a2);
        graph[a1][a2]=graph[a2][a1]=1;
    }
    int n;
    cin>>n;
    while(n--){
        int k;
        scanf("%d", &k);
        vector<int> arr(k);
        unordered_map<int, int> mp;
        for(int i=0;i<k;i++){
            scanf("%d", &arr[i]);
            mp[arr[i]]=1;
        }
        int isclique=1, ismax=1;
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                if(graph[arr[i]][arr[j]]==0) isclique=0;
            }
        }
        if(isclique==0) {
            printf("Not a Clique\n");
            continue;
        }
        for(int i=1;i<maxn;i++){
            if(mp[i]==0){
                int count=0;
                for(int j=0;j<k;j++){
                    if(graph[i][arr[j]]==1) count++;
                }
                if(count==k) ismax=0;
            }
        }
        if(ismax==0){
            printf("Not Maximal\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}
