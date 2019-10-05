//
//  main.cpp
//  PAT-A1030
//
//  Created by 雨含香 on 2019/10/5.
//  Copyright © 2019 雨含香. All rights reserved.
//1030 Travel Plan

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn=505;
const int INF=1000000000;

int map_dis[maxn][maxn];
int map_cost[maxn][maxn];

bool flag[maxn]={false};
vector<int> pre[maxn];
int dis[maxn];
int num;
vector<int> tempPath;
vector<int> path;

void dijkstra(int s){
    fill(dis, dis+maxn, INF);
    dis[s]=0;
    for(int i=0;i<num;i++){
        int MIN=INF,u=-1;
        for(int x=0;x<num;x++){
            if(!flag[x]&&dis[x]<MIN){
                u=x;
                MIN=dis[x];
            }
        }
        
        if(u==-1) return;
        flag[u]=true;
        for(int j=0;j<num;j++){
           if(!flag[j]&&map_dis[u][j]!=INF){
               if(dis[u]+map_dis[u][j] < dis[j]){
                    dis[j] =dis[u]+map_dis[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
               } else if(dis[u]+map_dis[u][j] == dis[j]){
                    pre[j].push_back(u);
               }
           }
        }
    }
}
int minCost=0;
int minRes=INF;
void dfs(int start, int end){
    if(end==start){
        tempPath.push_back(end);
        if(minCost < minRes){
            minRes = minCost;
            path=tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(end);
    
    for(int i=0;i<pre[end].size();i++){
        minCost+=map_cost[end][pre[end][i]];
        dfs(start, pre[end][i]);
        minCost-=map_cost[end][pre[end][i]];
    }
    tempPath.pop_back();
}


int main(int argc, const char * argv[]) {
    int m, start, end;
    scanf("%d %d %d %d", &num, &m, &start, &end);
    fill(map_dis[0], map_dis[0]+maxn*maxn, INF);
    fill(map_cost[0], map_cost[0]+maxn*maxn, INF);
    while(m--){
        int c1,c2,d,cost;
        scanf("%d %d %d %d", &c1, &c2, &d, &cost);
        map_dis[c1][c2] = map_dis[c2][c1]=d;
        map_cost[c1][c2] = map_cost[c2][c1] = cost;
    }
    dijkstra(start);
    dfs(start, end);
    for(int i=path.size()-1;i>=0;i--){
        printf("%d ", path[i]);
    }
    printf("%d %d", dis[end], minRes);
    return 0;
}
