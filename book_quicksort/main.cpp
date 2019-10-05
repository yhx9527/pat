//
//  main.cpp
//  book_quicksort
//
//  Created by 雨含香 on 2019/9/26.
//  Copyright © 2019 雨含香. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int Partition(int A[], int left, int right){
    int p= (round((1.0*rand()/RAND_MAX*(right-left)+left)));
    swap(&A[left], &A[p]);
    int temp=A[left];
    while(left<right){
        while(left<right && A[right]>=temp){
            right--;
        }
        A[left]=A[right];
        while(left<right && A[left]<temp){
            left++;
        }
        A[right]=A[left];
    }
    A[left] = temp;
    return left;
}

void quickSort(int A[], int left, int right){
    if(left < right){
        int pos = Partition(A, left, right);
        quickSort(A, left, pos-1);
        quickSort(A, pos+1, right);
    }
}

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int A[10]={9,3,4,2,13,2,1,4,14,5};
    quickSort(A, 0, 9);
    for(int i=0;i<10;i++){
        printf("%d ", A[i]);
    }
    return 0;
}
