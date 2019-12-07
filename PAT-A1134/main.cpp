//
//  main.cpp
//  PAT-A1134
//
//  Created by 雨含香 on 2019/12/5.
//  Copyright © 2019 雨含香. All rights reserved.
// 1134 Vertex Cover (25 分)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct node{
  int a,b;
};
vector<node> graph;

int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d", &a, &b);
        graph.push_back({a,b});
    }
    int num;
    cin>>num;
    while(num--){
        int k,key,flag=1;
        scanf("%d",&k);
        unordered_map<int, int> mp;
        while(k--){
            scanf("%d", &key);
            mp[key]=1;
        }
        
        for(auto it:graph){
            if(!mp[it.a] && !mp[it.b]) {
                flag=0;
            }
        }
        if(flag==1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
