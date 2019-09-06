//
//  main.cpp
//  codeup-5901
//
//  Created by 雨含香 on 2019/9/6.
//  Copyright © 2019 雨含香. All rights reserved.
//
//题目描述
//读入一串字符，判断是否是回文串。“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。
//
//输入
//一行字符串，长度不超过255。
//
//输出
//如果是回文串，输出“YES”，否则输出“NO”。
//
//样例输入
//12321
//样例输出
//YES
#include <iostream>
#include <cstdio>
#include <cstring>

int main(int argc, const char * argv[]) {
    char str[255];
    gets(str);
    int len = strlen(str);
    int left=0, right=len-1;
    
    while(left<right) {
        if(str[left]==str[right]){
            left++;
            right--;
        } else {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
