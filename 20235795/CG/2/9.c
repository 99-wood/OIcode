/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-1
* 题目：CG平台 字符串数字个数
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>

#define MAXN 2010

char str[MAXN];

int main(){
    scanf("\n%[^\n]", str);
    int len = strlen(str);
    int ans = 0;
    for(int i = 0; i < len; ++i){
        if(str[i] >= '0' && str[i] <= '9'){ //判断是否为数字
            ans = (ans * 10) + (str[i] - '0');
        }
    }
    printf("%d", ans + 10);
	return 0; 
}

