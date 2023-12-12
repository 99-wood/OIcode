/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-1
* 题目：CG平台 逆序输出单词
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>

#define MAXN 2010

char str[MAXN][MAXN];
int main(){
    int n = 0;
    while(scanf("%s", str[n++]) != EOF);
    while(n--){
        printf("%s\n", str[n]);
    }
	return 0; 
}
