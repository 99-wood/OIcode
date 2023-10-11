/*
* File: C-Ì·ºÆÇ¿-9.3.c
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

#define S(a, b, c)  ((a + b + c) / 2)
#define area(a, b, c)  (sqrt(S(a, b, c) * (S(a, b, c) - a) * (S(a, b, c) - b) * (S(a, b, c) - c)))
int main(){
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	printf("%.3lf", area(a, b, c));
	return 0; 
}
