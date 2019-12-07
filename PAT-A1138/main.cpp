//
//  main.cpp
//  PAT-A1138
//
//  Created by 雨含香 on 2019/11/30.
//  Copyright © 2019 雨含香. All rights reserved.
// 1138 Postorder Traversal (25 分)
//树的三种遍历的特点

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> pre;
vector<int> in;
unordered_map<int , int> mp;
int result=-1;

void searchNode(int pre_a,int pre_b,int in_a, int in_b){
    if(in_a>in_b) return;
    if(in_a==in_b){
        result=pre[pre_a];
        return;
    }
    int pos=mp[pre[pre_a]];
    searchNode(pre_a+1, pre_a+pos-in_a,in_a, pos-1);
    if(result!=-1) return;
    searchNode(pre_a+pos-in_a+1, pre_b,pos+1, in_b);
    if(result!=-1) return;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    pre.resize(n+1);
    in.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d", &pre[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &in[i]);
        mp[in[i]]=i;
    }
    searchNode(1,n,1,n);
    cout<<result;
    return 0;
}
