//
//  main.cpp
//  self1
//
//  Created by 雨含香 on 2019/12/7.
//  Copyright © 2019 雨含香. All rights reserved.
// 层次遍历+中序遍历-->打印前序遍历


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
vector<int> inorder;
queue<int> layer;
unordered_map<int, int> mp;

void preorder(int root, int l, int r){
    if(l>r) return;
    printf("%d ", root);
    int lroot=-1,rroot=-1;
    if(mp[root]>l){
        lroot = layer.front();
        layer.pop();
    }
    if(r>mp[root]){
        rroot = layer.front();
        layer.pop();
    }
    if(lroot!=-1){
        preorder(lroot, l, mp[root]-1);
    }
    if(rroot!=-1){
        preorder(rroot, mp[root]+1, r);
    }
    
    
}

int main() {
    int n;
    cin>>n;
    inorder.resize(n);
    
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        layer.push(x);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &inorder[i]);
        mp[inorder[i]]=i;
    }
    int root = layer.front();
    layer.pop();
    preorder(root, 0, n-1);
}

