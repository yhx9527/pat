//
//  main.cpp
//  PAT-A1034
//
//  Created by 雨含香 on 2019/10/4.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1034 Head of a Gang

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int maxn = 2010;

map<string, int> str2int;//姓名到编号
map<int, string> int2str;//编号到姓名
map<string, int> res;//存放结果

int edge[maxn][maxn]={0};//存放边权
int point[maxn]={0};//存放点权
bool vis[maxn]={false};

int numPerson=-1;
int K, cluster=0;
int change(string str){
    if(str2int.find(str)!=str2int.end()){
        return str2int[str];
    } else {
        numPerson++;
        str2int[str]=numPerson;
        int2str[numPerson]=str;
        return numPerson;
    }
}
void dfs(int i, int& sum, int& count, int& head){
    vis[i]=true;
    for(int j=0;j<maxn;j++){
        if(edge[i][j]>0){
            if(vis[j]==false){
                vis[j]=true;
                count++;
                if(point[j]>point[head]) head=j;
                dfs(j, sum, count, head);
            }
            sum+=edge[i][j];
            edge[i][j]=0;
            edge[j][i]=0;
        }
        
    }
}

void dfstraver(){
    int sum=0, count=1, head;
    for(int i=0;i<maxn;i++){
        sum=0, count=1, head=i;//sum为连通图权和，count为连通图元素个数， head为连通图中权最大的元素的编号
        if(vis[i]==false){
            dfs(i, sum, count, head);
        }
        if(count>2&&sum>K){
            cluster++;
            res[int2str[head]]=count;
        }
    }
}

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d %d", &num, &K);
    while(num--){
        string s1,s2;
        int weight;
        cin >> s1 >> s2 >> weight;
        int i=change(s1);
        int j=change(s2);
        edge[i][j]+=weight;
        edge[j][i]+=weight;
        point[i]+=weight;
        point[j]+=weight;
    }
    dfstraver();
    printf("%d\n", cluster);
    for(map<string,int>::iterator it=res.begin();it!=res.end();it++){
        cout<<it->first<<" "<<it->second<<"\n";
    }
    return 0;
}
