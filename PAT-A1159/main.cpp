//
//  main.cpp
//  PAT-A1159
//
//  Created by 雨含香 on 2019/11/7.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1159. Structure of a Binary Tree
//树的构建，遍历，哈希，字符解析


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct treeNode{
    int key,level;
    treeNode * left;
    treeNode * right;
    treeNode * parent;
    treeNode(int key):key(key){};
};
bool is_full = true;
unordered_map<int, treeNode*> mp;

treeNode* build(int*post, int* inorder, int n){
    if(n<=0) return nullptr;
    treeNode* root = new treeNode(post[n-1]);
    root->parent = nullptr;
    mp[root->key]= root;
    
    int i;
    for(i=0;i<n&&inorder[i]!=root->key;i++);
    
    root->left = build(post, inorder, i);
    root->right = build(post+i, inorder+i+1, n-i-1);
    if(root->left) root->left->parent = root;
    if(root->right) root->right->parent = root;
    
    return root;
}

void traver(treeNode* root){
    if(!root) return;
    if(root->parent) root->level = root->parent->level+1;
    if(root->left&&!root->right) is_full = false;
    if(!root->left&&root->right) is_full = false;
    
    traver(root->left);
    traver(root->right);
    
}

int main(int argc, const char * argv[]) {
    int n,m;
    cin >> n;
    int* post = new int[n];
    int* inorder = new int[n];
    for(int i=0;i<n;i++) cin >> post[i];
    for(int i=0;i<n;i++) cin >> inorder[i];
    treeNode* tree = build(post, inorder, n);
    tree->level=1;
    traver(tree);
    cin >> m;getchar();
    string str;
    cout<<endl;
    while(m--){
        getline(cin, str);
        int a, b;
        bool flag;
        if(str.find("root")!=string::npos){
            sscanf(str.c_str(), "%d is the root", &a);
            flag = (a==tree->key);
        } else if(str.find("siblings")!=string::npos){
            sscanf(str.c_str(), "%d and %d are siblings", &a, &b);
            flag = (mp[a]->parent==mp[b]->parent);
        }  else if(str.find("parent")!=string::npos){
            sscanf(str.c_str(), "%d is the parent of %d", &a, &b);
            flag = (mp[b]->parent==mp[a]);
        } else if(str.find("left")!=string::npos){
            sscanf(str.c_str(), "%d is the left child of %d", &a, &b);
            flag = (mp[b]->left==mp[a]);
        } else if(str.find("right")!=string::npos){
            sscanf(str.c_str(), "%d is the right child of %d", &a, &b);
            flag = (mp[b]->right==mp[a]);
        } else if(str.find("level")!=string::npos){
            sscanf(str.c_str(), "%d and %d are on the same level", &a, &b);
            flag = (mp[a]->level==mp[b]->level);
        } else{
            flag = is_full;
        }
        cout << (flag ? "YES" : "NO") <<endl;
    }
    
    
    return 0;
}
