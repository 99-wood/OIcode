/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-1
* 题目：CG平台 花式排序之字符串
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>

#define MAXN 2010

char str[MAXN];
char str1[MAXN], str2[MAXN];
void swap(char *a, char *b){ //交换函数 
	char tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
int main(){
    scanf("\n%[^\n]", str);
    int len = strlen(str);
    for(int i = 0; i < len; ++i){
        // 根据奇偶放入不同数组
        if(i & 1){
            str1[i >> 1] = str[i];
        }
        else{
            str2[i >> 1] = str[i];
        }
    }
    int len1 = (len >> 1), len2 = (len >> 1) + (len & 1); //两字符串长度

    //冒泡排序升序
    for(int i = 0; i < len1; ++i){
        for(int j = len1 - 1; j > i; --j){
            if(str1[j] < str1[j - 1]){
                swap(&str1[j], &str1[j - 1]);
            }
        }
    }
    //冒泡排序降序
    for(int i = 0; i < len2; ++i){
        for(int j = len2 - 1; j > i; --j){
            if(str2[j] > str2[j - 1]){
                swap(&str2[j], &str2[j - 1]);
            }
        }
    }
    for(int i = 0; i < len; ++i){
        // 根据奇偶输出
        if(i & 1){
            printf("%c", str1[i >> 1]);
        }
        else{
            printf("%c", str2[i >> 1]);
        }
    }
	return 0; 
}
