/*
* File: C-Ì·ºÆÇ¿-9.8.c
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

#define MAX(a, b) (a > b ? a : b)

double max(double a, double b){
	return a > b ? a : b;
}
int main(){
	double a, b, c;
	scanf("%lf%lf%lf",&a, &b, &c);
	printf("%.3lf\n", max(a, max(b, c)));
	printf("%.3lf\n", MAX(a, MAX(b, c)));
	return 0; 
}
