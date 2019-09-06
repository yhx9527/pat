//
//  main.cpp
//  PAT-B1009
//
//  Created by 雨含香 on 2019/9/6.
//  Copyright © 2019 雨含香. All rights reserved.
//
//给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
//
//输入格式：
//
//测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。
//
//输出格式：
//
//每个测试用例的输出占一行，输出倒序后的句子。
//
//输入样例：
//
//Hello World Here I Come
//输出样例：
//
//Come I Here World Hello
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char str[90]; //记得考虑结束符
    cin.getline(str, 90);
    int len = strlen(str);
    char arr[90][90];
    int index= 0;
    int word = 0;
    for(int i=0;i<len;i++){
        if(str[i]!=' '){
            arr[index][word++] = str[i];
        } else {
            arr[index][word] = '\0';
            index++;
            word = 0;
        }
    }

    for(int i=index;i>=0;i--){
        printf("%s", arr[i]);
        if(i>0){
           printf(" ");
        }
    }
    return 0;
}
