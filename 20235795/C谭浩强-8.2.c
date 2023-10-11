/*
* File: C-Ì·ºÆÇ¿-8.2.c
* Author: 99_wood
* Date: 2023-10-10
*/
#include<stdio.h>
#include<math.h>
#define MAXN 110
#define mid ((l + r) >> 1)
#define E 1e-7
int main(){
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	if(fabs(b * b - 4 * a * c) <= E){
		printf("x1=%.3lf x2=%.3lf", (-b / (a * 2)), (-b / (a * 2)));
	}
	else if(b * b - 4 * a * c < 0){
		printf("x1=%.3lf+%.3lfi x2=%.3lf-%.3lfi",
			(-b / (a * 2)),
			sqrt(4 * a * c - b * b) / (a * 2),
			(-b / (a * 2)),
			sqrt(4 * a * c - b * b) / (a * 2));
	}
	else{
		printf("x1=%.3lf+%.3lf x2=%.3lf-%.3lf",
			(-b / (a * 2)),
			sqrt(b * b - 4 * a * c) / (a * 2),
			(-b / (a * 2)),
			sqrt(b * b - 4 * a * c) / (a * 2));
	}
	return 0; 
}
