/*
* File: C-Ì·ºÆÇ¿-9.2.c
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
#define mod(a, b) (a % b)
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", mod(a, b));
	return 0; 
}
