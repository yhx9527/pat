//
//  main.cpp
//  PAT-A1067
//
//  Created by 雨含香 on 2019/10/5.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1076 Forwards on Weibo

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int value;
    int layer;
    node(int _v,int _l):value(_v),layer(_l){}
};

const int maxn=1010;
vector<node> users[maxn];
vector<node> searcharr;

int level;

void BFS(node u){
    queue<node> q;
    bool appear[maxn]={false};
    q.push(u);
    appear[u.value]=true;
    int l=0;
    int count=0;
    while(!q.empty()){
        node user=q.front();
        q.pop();
        int v=user.value;
        for(int i=0;i<users[v].size();i++){
            node next=users[v][i];
            if(appear[next.value]==false){
                appear[next.value]=true;
                next.layer= user.layer+1;
                if(next.layer<=level){
                    count++;
                }
                q.push(next);
            }
        }
    }
    printf("%d\n", count);
}

void BFSTrave(){
    for(int i=0;i<searcharr.size();i++){
        BFS(searcharr[i]);
    }
}

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d %d",&num, &level);
    for(int i=1;i<=num;i++){
        int count;
        scanf("%d", &count);
        while(count--){
            int temp;
            scanf("%d", &temp);
            users[temp].push_back(node(i, 0));
        }
    }
    int snum;
    scanf("%d", &snum);
    while(snum--){
        int temp;
        scanf("%d", &temp);
        searcharr.push_back(node(temp, 0));
    }
    BFSTrave();
    return 0;
}
