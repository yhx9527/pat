//
//  main.cpp
//  PAT-A1138(1)
//
//  Created by 雨含香 on 2019/11/30.
//  Copyright © 2019 雨含香. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> pre;
vector<int> in;
unordered_map<int, int> mp;
int flag=0;
void searchNode(int prel, int inl, int inr){
    if(inl>inr || flag==1){
        return;
    }
    int pos=mp[pre[prel]];
    searchNode(prel+1, inl, pos-1);
    searchNode(prel+mp[pre[prel]]-inl+1, pos+1, inr);
    if(flag==0){
        printf("%d", pre[prel]);
        flag=1;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    pre.resize(n);
    in.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d", &pre[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &in[i]);
        mp[in[i]]=i;
    }
    searchNode(0,0,n-1);
    return 0;
}
