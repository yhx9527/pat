//
//  main.cpp
//  PAT-A1155
//
//  Created by 雨含香 on 2019/11/18.
//  Copyright © 2019 雨含香. All rights reserved.
//1155 Heap Paths
//堆的存储，遍历，判断，dfs

#include <iostream>
#include <vector>
using namespace std;
int num[1010];
vector<int> v;
int ifmin=1,ifmax=1;
int n;
void dfs(int i){
    if(2*i>n&&2*i+1>n){
        if(i<=n){
            for(int j=0;j<v.size();j++){
                printf("%d%s", v[j], j<v.size()-1 ? " " : "\n");
            }
        }
    }else {
        v.push_back(num[2*i+1]);
        dfs(2*i+1);
        v.pop_back();
        v.push_back(num[2*i]);
        dfs(2*i);
        v.pop_back();
    }
    
}

int main(int argc, const char * argv[]) {

    cin >>n;
    for(int i=1;i<=n;i++){
        scanf("%d", &num[i]);
    }
    v.push_back(num[1]);
    dfs(1);
    for(int i=2;i<=n;i++){
        if(num[i/2]>num[i]) ifmin=0;
        if(num[i/2]<num[i]) ifmax=0;
    }
    if(ifmin==1){
        printf("Min Heap");
    } else {
        printf("%s", ifmax==1 ? "Max Heap" : "Not Heap");
    }
    return 0;
}
