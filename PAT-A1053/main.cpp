//
//  main.cpp
//  PAT-A1053
//
//  Created by 雨含香 on 2019/10/3.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1053 Path of Equal Weight

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct node{
    int weight;
    vector<int> childs;
} trees[105];
int sum=0;
vector<vector<int> > arrs;
vector<int> arr;

void dfs(int index, int now){
    if(trees[index].childs.size()==0&&now==sum){
        for(int j=0;j<arr.size();j++){
            printf("%d", arr[j]);
            if(j<arr.size()-1){
                printf(" ");
            }
        }
        printf("\n");
    }

    for(int i=0;i<trees[index].childs.size();i++){
        int pos =trees[index].childs[i];
        arr.push_back(trees[pos].weight);
        dfs(pos, now+trees[pos].weight);
        arr.pop_back();
    }
}

bool cmp1(int a, int b){
    return trees[a].weight > trees[b].weight;
}
int main(int argc, const char * argv[]) {
    int count,non;
    scanf("%d %d %d", &count, &non, &sum);
    for(int i=0;i<count;i++){
        scanf("%d", &trees[i].weight);
    }
    for(int i=0;i<non;i++){
        int pos, num, index;
        scanf("%d %d", &pos, &num);
        while(num--){
            scanf("%d", &index);
            trees[pos].childs.push_back(index);
        }
        sort(trees[pos].childs.begin(), trees[pos].childs.end(), cmp1);
    }
    arr.push_back(trees[0].weight);
    dfs(0, trees[0].weight);
    
    
    return 0;
}
