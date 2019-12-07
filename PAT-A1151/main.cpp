//
//  main.cpp
//  PAT-A1151
//
//  Created by 雨含香 on 2019/11/23.
//  Copyright © 2019 雨含香. All rights reserved.
//1151 LCA in a Binary Tree (30 分)
//树的遍历，树的结构，map。与1143类似

#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> in, pre;
map<int,int> pos;

void findp(int a, int b,int root, int rootloc){
    int aIn=pos[a], bIn=pos[b], rootIn=pos[root];
    if(aIn<rootIn&&bIn<rootIn){
        findp(a, b, pre[rootloc+1], rootloc+1);
    } else if(aIn>rootIn&&bIn>rootIn){
        findp(a, b, pre[rootloc+rootIn], rootloc+rootIn);
    } else if((aIn<rootIn&&bIn>rootIn)||(aIn>rootIn&&bIn<rootIn)){
        printf("LCA of %d and %d is %d.\n", a, b, root);
    } else if(aIn==rootIn){
        printf("%d is an ancestor of %d.\n", a, b);
    } else if(bIn==rootIn){
        printf("%d is an ancestor of %d.\n", b, a);
    }
}

int main(int argc, const char * argv[]) {
    int n,m;
    cin >> n >> m;
    in.resize(m+1);
    pre.resize(m+1);
    for(int i=1;i<=m;i++){
        scanf("%d", &in[i]);
        pos[in[i]]=i;
    }
     for(int i=1;i<=m;i++){
        scanf("%d", &pre[i]);
    }
    for(int i=1;i<=n;i++){
        int t1,t2;
        scanf("%d%d", &t1, &t2);
        if(pos[t1]==0&&pos[t2]==0){
            printf("ERROR: %d and %d are not found.\n", t1, t2);
        } else if(pos[t1]==0 || pos[t2]==0){
            printf("ERROR: %d is not found.\n", pos[t1]?t2:t1);
        } else {
            findp(t1, t2, pre[1], 1);
        }
    }
    
    return 0;
}
