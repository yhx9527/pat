//
//  main.cpp
//  PAT-A1025
//
//  Created by 雨含香 on 2019/9/16.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1025 PAT Ranking

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student{
    char registration_number[15];
    int grade;
    int final_rank;
    int location_number;
    int local_rank;
} ranklist[30010];
bool cmp(student a, student b){
    if(a.grade != b.grade){
        return a.grade>b.grade;
    } else {
        return strcmp(a.registration_number, b.registration_number)<0;
    }
}

int main(int argc, const char * argv[]) {
    int num,index=0;
    scanf("%d", &num);
    for(int file=1;file<=num;file++){
        int count;
        scanf("%d", &count);
        for(int i=0;i<count;i++){
            scanf("%s %d", ranklist[index].registration_number, &ranklist[index].grade);
            ranklist[index].location_number = file;
            index++;
        }
        sort(ranklist+index-count, ranklist+index, cmp);
        ranklist[index-count].local_rank=1;
        for(int i=index-count+1;i<index;i++){
            if(ranklist[i].grade==ranklist[i-1].grade){
                ranklist[i].local_rank = ranklist[i-1].local_rank;
            } else {
                ranklist[i].local_rank = i+1-index+count;
            }
        }
    }
    sort(ranklist, ranklist+index, cmp);
    
    printf("%d", index);
    ranklist[0].final_rank=1;
    printf("\n%s %d %d %d", ranklist[0].registration_number, ranklist[0].final_rank, ranklist[0].location_number, ranklist[0].local_rank);
    
    for(int i=1;i<index;i++){
        if(ranklist[i].grade==ranklist[i-1].grade){
            ranklist[i].final_rank = ranklist[i-1].final_rank;
        } else {
            ranklist[i].final_rank = i + 1;
        }
        printf("\n%s %d %d %d", ranklist[i].registration_number, ranklist[i].final_rank, ranklist[i].location_number, ranklist[i].local_rank);
    }
    return 0;
}
