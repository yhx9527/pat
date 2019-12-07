//
//  main.cpp
//  PAT-A1158
//
//  Created by 雨含香 on 2019/11/7.
//  Copyright © 2019 雨含香. All rights reserved.
// 1158 Telefraud Detection
//图的构建，图的元素操作，并查集，结果排序
#include <iostream>
#include <vector>
using namespace std;

//并查集值得记忆
struct UnionFind{
    vector<int> id;
    vector<int> sz;
    
    UnionFind(int n):id(n), sz(n,1){
        for(int i=0;i<n;i++){
            id[i]=i;
        }
    }
    //寻父并压缩
    int find(int x){
        if(id[x]==x) return x;
        return id[x]=find(id[x]);
    }
    //合并，按照权重来看谁是爸爸
    void Union(int x, int y){
        int p1 = find(x);
        int p2 = find(y);
        if(p1==p2) return;
        if(sz[p1]<sz[p2]){
            id[p1]=p2; sz[p2]+=sz[p1];
        }else{
            id[p2]=p1; sz[p1]+=sz[p2];
        }
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int thre,n,m;
    cin >> thre >> n >> m;
    //邻接矩阵vector法，值得记忆
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    while(m--){
        int i,j,k;
        cin>>i>>j>>k;
        graph[i][j]+=k;
    }
    vector<int> suspect;
    for(int i=1;i<=n;i++){
        int count=0,callback=0;
        for(int j=1;j<=n;j++){
            if(graph[i][j]>0&&graph[i][j]<=5){
                count++;
                if(graph[j][i]>0){
                    callback++;
                }
            }
        }
        if(count>thre&&callback<count*0.2){
            suspect.push_back(i);
        }
    }
    if(suspect.empty()){
        cout<<"None"<<endl;
    }
    UnionFind uf(n+1);
    
    for(int i=0;i<suspect.size();i++){
        for(int j=i+1;j<suspect.size();j++){
            if(graph[suspect[i]][suspect[j]]>0&&graph[suspect[j]][suspect[i]]>0){
                uf.Union(suspect[i],suspect[j]);
            }
        }
    }
    
    vector<int>temp[n+1];
    for(auto x:suspect){
        temp[uf.find(x)].push_back(x);
    }
    vector<vector<int>>ans;
    for(auto gang:temp){
        if(!gang.empty()) ans.push_back(gang);
    }
    sort(ans.begin(), ans.end(), [](vector<int>a, vector<int>b){
        return a.front() < a.front();
    });
    for(auto gang:ans){
        for(int i=0;i<gang.size();i++){
            cout<<gang[i]<<(i<gang.size()-1 ? ' ': '\n');
        }
    }
    
    
    return 0;
}
