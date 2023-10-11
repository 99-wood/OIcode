/*
* File: C-Ì·ºÆÇ¿-9.4.c
* Author: 99_wood
* Date: 2023-10-11
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

#define LEAP_YEAR(y) ((y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) ? "L" : "N")

int main(){
	int n;
	scanf("%d", &n);
	printf(LEAP_YEAR(n));
	return 0; 
}
