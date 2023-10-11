/*
* File: C-Ì·ºÆÇ¿-9.1.c
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
#define swap(a, b) {a ^= b; b ^= a; a ^= b;}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	swap(a, b);
	printf("%d %d", a, b);
	return 0; 
}
