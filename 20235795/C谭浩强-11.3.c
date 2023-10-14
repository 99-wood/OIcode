/*
* File: C-Ì·ºÆÇ¿-11.3.c
* Author: 99_wood
* Date: 2023-10-13
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//²¹³ä bool ÀàÐÍ 
enum bool {false = 0, true = 1};
#define bool int

#define MAXN 110
#define mid ((l + r) >> 1)

struct Student{
	char num[MAXN], name[MAXN];
	int socre1, score2, score3;
}student[MAXN];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%s%s%d%d%d", student[i].num, student[i].name, &student[i].socre1, &student[i].score2, &student[i].score3); 
	}
	for(int i = 1; i <= n; ++i){
		printf("%s,%s,%d,%d,%d\n", student[i].num, student[i].name, student[i].socre1, student[i].score2, student[i].score3); 
	}
	return 0; 
}
