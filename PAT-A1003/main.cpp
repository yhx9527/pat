//
//  main.cpp
//  PAT-A1003
//
//  Created by 雨含香 on 2019/10/5.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1003 Emergency (25 分)
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct node{
    int city;
    int len;
    node(int _city, int _len):len(_len), city(_city){}
};
const int maxn=505;
const int INF = 1000000000;

vector<node> map[maxn];
bool flag[maxn]={false};
int hands[maxn]={0};
int dis[maxn]; ////从其他点到起点的最短距离
int roads[maxn]={0}; //从其他点到起点的道路数
int teams[maxn]={0}; //从其他点到起点可累积的人手

int num;

void dijkstra(int s){
    fill(dis, dis+maxn, INF);
    dis[s]=0;
    teams[s]=hands[s];
    roads[s]=1;
    
    for(int i=0;i<num;i++){
        //找出最短距离的那个点
        int MIN=INF,o=-1;
        for(int j=0;j<num;j++){
            if(!flag[j]&&dis[j]<MIN){
                o=j;
                MIN=dis[j];
            }
        }
        if(o==-1) return;
        
        flag[o]=true;
        
        for(int x=0;x<map[o].size();x++){
            node temp=map[o][x];
            if(!flag[temp.city]){
                if(dis[o]+temp.len<dis[temp.city]){
                    dis[temp.city]=dis[o]+temp.len;
                    teams[temp.city] = teams[o]+hands[temp.city];
                    roads[temp.city]=roads[o];
                } else if(dis[o]+temp.len==dis[temp.city]){
                    if(teams[temp.city] < teams[o]+hands[temp.city]){
                        teams[temp.city] = teams[o]+hands[temp.city];
                    }
                     roads[temp.city]+=roads[o];
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int r, start, end;
    scanf("%d %d %d %d", &num, &r, &start, &end);
    for(int i=0;i<num;i++){
        scanf("%d", &hands[i]);
    }
    while(r--){
        int st,ed,l;
        scanf("%d %d %d", &st, &ed, &l);
        map[st].push_back(node(ed,l));
        map[ed].push_back(node(st,l));
    }
    dijkstra(start);
    printf("%d %d", roads[end], teams[end]);
    return 0;
}
