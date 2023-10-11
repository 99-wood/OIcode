/*
* File: C-Ì·ºÆÇ¿-8.5.c
* Author: 99_wood
* Date: 2023-10-10
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAXN 10010
#define mid ((l + r) >> 1)
char str[MAXN];
void swap(char *a, char *b){ //½»»»º¯Êý 
	*a ^= *b;
	*b ^= *a;
	*a ^= *b; 
	return;
}
int main(){
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < (len >> 1); ++i){
		swap(&str[i], &str[len - i - 1]);
	}
	printf("%s", str);
	return 0; 
}
