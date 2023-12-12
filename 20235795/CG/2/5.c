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
    for(int i = 1; i <= len; ++i){
        if((str[i] < '0' || str[i] > '9') && (str[i - 1] >= '0' && str[i - 1] <= '9')){ //判断数字的结束
            ++ans;
        }
    }
    printf("%d", ans);
	return 0; 
}
