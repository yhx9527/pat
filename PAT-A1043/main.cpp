//
//  main.cpp
//  PAT-A1043
//
//  Created by 雨含香 on 2019/10/3.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1043 Is It a Binary Search Tree

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};
vector<int> origin, pre1, pre2, post1, post2;

void insert(node*& root, int data){
    if(root==NULL){
        root=new node;
        root->data = data;
        root->left=root->right=NULL;
        return;
    }
    if(data<root->data) insert(root->left, data);
    else insert(root->right, data);
}

void preorder1(node* root){
    if(root==NULL) return;
    pre1.push_back(root->data);
    preorder1(root->left);
    preorder1(root->right);
}
void preorder2(node* root){
    if(root==NULL) return;
    pre2.push_back(root->data);
    preorder2(root->right);
    preorder2(root->left);
}

void postorder1(node* root){
    if(root==NULL) return;
    postorder1(root->left);
    postorder1(root->right);
    post1.push_back(root->data);
}
void postorder2(node* root){
    if(root==NULL) return;
    postorder2(root->right);
    postorder2(root->left);
    post2.push_back(root->data);
}

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d", &num);
    node* root=NULL;
    while(num--){
        int data;
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    preorder1(root);
    preorder2(root);
    if(origin==pre1){
        printf("YES\n");
        postorder1(root);
        for(int i=0;i<post1.size();i++){
            printf("%d",post1[i]);
            if(i<post1.size()-1)
                printf(" ");
        }
    } else if(origin==pre2){
        printf("YES\n");
        postorder2(root);
        for(int i=0;i<post2.size();i++){
            printf("%d",post2[i]);
            if(i<post2.size()-1)
                printf(" ");
        }
    } else {
        printf("NO");
    }
    return 0;
}
