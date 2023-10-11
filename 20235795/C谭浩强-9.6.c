/*
* File: C-Ì·ºÆÇ¿-9.6.c
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

int main(){
	double a;
	scanf("%lf", &a);
	printf("%6.2lf\n", a);
	printf("%6.2lf%6.2lf\n", a, a);
	printf("%6.2lf%6.2lf%6.2lf\n", a, a, a);
	return 0; 
}
