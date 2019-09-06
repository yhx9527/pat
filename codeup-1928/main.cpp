//
//  main.cpp
//  codeup-1928
//
//  Created by 雨含香 on 2019/9/5.
//  Copyright © 2019 雨含香. All rights reserved.
//

#include <iostream>
#include <cstdio>
int months[13][2] = {
    {0,0},{31, 31},{28, 29},{31, 31},{30,30},{31,31},{30,30},{31,31},
    {31, 31},{30,30},{31,31},{30,30},{31, 31}
};
bool isLeap(int year){
    return (year % 4==0 && year % 100 !=0) || (year % 400==0);
}
int main(int argc, const char * argv[]) {
    int date1, date2;
    int y1, m1, d1;
    int y2, m2, d2;
    while(scanf("%d %d", &date1, &date2)!=EOF){
        int count=1;
        if(date1 > date2){
            int temp = date1;
            date1 = date2;
            date2 = temp;
        }
        y1 = date1 / 10000;
        m1 = date1 % 10000 / 100;
        d1 = date1 % 100;
        y2 = date2 / 10000;
        m2 = date2 % 10000 / 100;
        d2 = date2 % 100;
        while(y1<y2 || m1 < m2 || d1 < d2){
            d1++;
            int index = isLeap(y1);
            if(d1==months[m1][index]+1){
                m1++;
                d1=1;
            }
            if(m1==13){
                y1++;
                m1=1;
            }
            count++;
        }
        printf("%d\n", count); //codeup答案记得要换行
    }
    return 0;
}
