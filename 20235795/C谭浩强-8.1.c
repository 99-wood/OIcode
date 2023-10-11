/*
* File: C-谭浩强-8.1.c
* Author: 99_wood
* Date: 2023-10-10
*/
#include<stdio.h>
#include<math.h>
#define MAXN 110
#define mid ((l + r) >> 1)
int gcd(int a, int b){ //最大公因数 
	return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b){ //最小公倍数 
	return a / gcd(a, b) * b;
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d %d", gcd(a, b), lcm(a, b));
	return 0; 
}
