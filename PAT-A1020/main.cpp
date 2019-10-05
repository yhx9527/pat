//
//  main.cpp
//  PAT-A1020
//
//  Created by 雨含香 on 2019/10/3.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1020 Tree Traversals (25 分)
//Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=35;
int postarr[maxn], inarr[maxn];
struct node{
    int data;
    node* left;
    node* right;
};
node* root=NULL;

node* create_tree(int p1, int p2, int i1, int i2){
    if(p1>p2) {
        return NULL;
    }
    int data=postarr[p2];
    int k;
    for(k=i1;k<=i2;k++){
        if(data==inarr[k]){
            break;
        }
    }
    node* root=new node;
    root->data=data;
    root->left=create_tree(p1, p1+k-i1-1, i1, k-1);
    root->right=create_tree(p1+k-i1, p2-1, k+1, i2);
    return root;
}
void levelorder(){
    queue<node*> q;
    q.push(root);
    printf("%d", root->data);
    int i=0;
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(i>0){
            printf(" %d", temp->data);
        }
        if(temp->left!=NULL) {
            q.push(temp->left);
            i++;
        }
        if(temp->right!=NULL) {
            q.push(temp->right);
            i++;
        }
    }
}

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d", &num);
    for(int i=0;i<num;i++){
        scanf("%d", &postarr[i]);
    }
    for(int i=0;i<num;i++){
        scanf("%d", &inarr[i]);
    }
    root=create_tree(0, num-1, 0, num-1);
    levelorder();
    
    return 0;
}
