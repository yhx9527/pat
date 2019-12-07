//
//  main.cpp
//  PAT-A1135
//
//  Created by 雨含香 on 2019/12/6.
//  Copyright © 2019 雨含香. All rights reserved.
// 1135 Is It A Red-Black Tree (30 分)
//树的遍历，创建，查找，汇总

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct node {
    int val;
    struct node*left;
    struct node*right;
};

node* build(node *&root, int val){
    if(root==NULL){
        root=new node();
        root->val = val;
        root->left=root->right=NULL;
    } else {
        if(abs(val)>abs(root->val)){
            root->right=build(root->right, val);
        } else {
            root->left=build(root->left, val);
        }
    }
    return root;
}
bool judge1(node *root){
    if(root==NULL) return true;
    if(root->val <0){
        if((!root->left || root->left->val>0) && (!root->right || root->right->val>0)) return true;
        return false;
    }
    return judge1(root->left) && judge1(root->right);
}
int getNum(node*root){
    if(root==NULL) return 0;
    int l=getNum(root->left);
    int r=getNum(root->right);
    return root->val>0?max(l,r)+1:max(l,r);
}
bool judge2(node *root){
    if(root==NULL) return true;
    int l = getNum(root->left);
    int r=getNum(root->right);
    if(l!=r) return false;
    return judge2(root->left) && judge2(root->right);
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    while(n--){
        int m;
        scanf("%d", &m);
        node*root=NULL;
        while(m--){
            int val;
            scanf("%d", &val);
            root=build(root, val);
        }
        if(root->val<0 || !judge1(root) || !judge2(root)){
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}
