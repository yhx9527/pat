//
//  main.cpp
//  PAT-A1018
//
//  Created by 雨含香 on 2019/10/7.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1018 Public Bike Management

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn=505;
const int INF=1000000000;
struct node{
    int v;
    int time;
    node(int _v, int _time):v(_v), time(_time){}
};
vector<node> roads[maxn];
int bike_num[maxn]={0};
bool flag[maxn]={false};
vector<int> pre[maxn];
vector<int> path, tempPath;
int dis[maxn];
int num;
int weight[maxn]={0};
int minNeed=INF, minRemain=INF;

void dijkstra(){
    fill(dis, dis+maxn, INF);
    dis[0]=0;
    
    for(int z=0;z<=num;z++){
        int u=-1, MIN=INF;
        for(int i=0;i<=num;i++){
            if(!flag[i]&&dis[i]<MIN){
                u=i;
                MIN=dis[i];
            }
        }
        if(u==-1) return;
        flag[u]=true;
        for(int j=0;j<roads[u].size();j++){
            node temp = roads[u][j];
            int target = temp.v;
            if(!flag[target]){
                if(dis[u]+temp.time<dis[target]){
                    dis[target] = dis[u]+temp.time;
                    pre[target].clear();
                    pre[target].push_back(u);
                }else if(dis[u]+temp.time==dis[target]){
                    pre[target].push_back(u);
                }
            }
        }
    }
}
int idea=0, fact=0, capacity, minbike=INF, back=INF;

void dfs(int now){
    if(now==0){
        if(fact < idea){
            int temp=idea-fact;
            if(temp < minbike){
                minbike=temp;
                back=0;
                tempPath.push_back(now);
                path=tempPath;
                tempPath.pop_back();
            }
        } else {
            minbike=0;
            int temp=fact-idea;
            if(temp < back){
                back=temp;
                tempPath.push_back(now);
                path=tempPath;
                tempPath.pop_back();
            }
        }
        return;
    }
    tempPath.push_back(now);
    fact+=bike_num[now];
    idea+=capacity/2;
   for(int i=0;i<pre[now].size();i++){
        int index =pre[now][i];
       dfs(index);
   }
    fact-=bike_num[now];
    idea-=capacity/2;
   tempPath.pop_back();
}

void DFS(int v){
    if(v==0){
        tempPath.push_back(v);
        int need=0, remain=0;
        for(int i=tempPath.size()-1;i>=0;i--){
            int id=tempPath[i];
            if(weight[id]>0){
                remain+=weight[id];
            }else{
                if(remain>abs(weight[id])){
                    remain-=abs(weight[id]);
                }else{
                    need+=abs(weight[id])-remain;
                    remain=0;
                }
            }
        }
        if(need<minNeed){
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        } else if(need == minNeed && remain < minRemain){
            minRemain=remain;
            path=tempPath;
        }
        tempPath.pop_back();
    }
    tempPath.push_back(v);
   for(int i=0;i<pre[v].size();i++){
        int index =pre[v][i];
       DFS(index);
   }
   tempPath.pop_back();
}

int main(int argc, const char * argv[]) {
    int road_num, end;
    scanf("%d %d %d %d", &capacity, &num, &end, &road_num);
    for(int i=1;i<=num;i++){
//        scanf("%d", &bike_num[i]);
        scanf("%d", &weight[i]);
        weight[i]-=capacity/2;
    }
    while(road_num--){
        int s,e,t;
        scanf("%d %d %d", &s, &e, &t);
        roads[s].push_back(node(e, t));
        roads[e].push_back(node(s, t));
    }
    dijkstra();
//    dfs(end);
    DFS(end);
//    printf("%d ", minbike);
    printf("%d ", minNeed);
    for(int i=path.size()-1;i>=0;i--){
        printf("%d", path[i]);
        if(i>0) printf("->");
    }
//    printf(" %d", back);
    printf(" %d", minRemain);
    return 0;
}
