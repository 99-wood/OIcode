/*
* File: C-Ì·ºÆÇ¿-11.8.c
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

#define MAXN 10010
#define mid ((l + r) >> 1)

struct Student{
	int num, score;
}student[MAXN];
void swap(struct Student *a, struct Student *b){
	struct Student tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d%d", &student[i].num, &student[i].score);
	for(int i = n + 1; i <= n + m; ++i) scanf("%d%d", &student[i].num, &student[i].score);
	
	//Ã°ÅÝÅÅÐò 
	for(int i = 1; i <= n + m; ++i){
		for(int j = n + m; j > i; --j){
			if(student[j].num < student[j - 1].num) swap(&student[j], &student[j - 1]);
		}
	}
	for(int i = 1; i <= n; ++i) printf("%d %d\n", student[i].num, student[i].score);
	for(int i = n + 1; i <= n + m; ++i) printf("%d %d\n", student[i].num, student[i].score);
	return 0; 
}
