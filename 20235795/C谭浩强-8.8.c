/*
* File: C-Ì·ºÆÇ¿-8.8.c
* Author: 99_wood
* Date: 2023-10-10
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
char str[MAXN];
int endd = 0;
int main(){
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; ++i){
		printf("%c ", str[i]);
	}
	return 0; 
}
