//
//  main.cpp
//  PAT-A1143
//
//  Created by 雨含香 on 2019/12/2.
//  Copyright © 2019 雨含香. All rights reserved.
// 1143 Lowest Common Ancestor (30 分)
//树 先序遍历

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> pre;
unordered_map<int, int> mp;

int main(int argc, const char * argv[]) {
    int m,n;
    cin>>m>>n;
    pre.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d", &pre[i]);
        mp[pre[i]]=1;
    }
    while(m--){
        int a,b;
        scanf("%d%d", &a, &b);
        int u;
        for(int i=0;i<n;i++){
            u=pre[i];
            if(min(a,b)<=u&&u<=max(a,b)) break;
        }
        if(mp[a]==0&&mp[b]==0){
            printf("ERROR: %d and %d are not found.\n", a, b);
        }else if(mp[a]==0 || mp[b]==0){
            printf("ERROR: %d is not found.\n", mp[a] ? b : a);
        } else if(a==u || b==u){
            printf("%d is an ancestor of %d.\n", a==u ? a : b, a==u ? b : a);
        } else {
            printf("LCA of %d and %d is %d.\n", a,b,u);
        }
    }
    return 0;
}
