/*
* File: C-̷��ǿ-8.3.c
* Author: 99_wood
* Date: 2023-10-10
*/
#include<stdio.h>
#include<math.h>
#define MAXN 110
#define mid ((l + r) >> 1)
int isPrime(int a){ //�ж��Ƿ�Ϊ���� 
	int q = sqrt(a);
	for(int i = 2; i <= q; ++i){
		if(a % i == 0) return 0; 
	}
	return 1;
}
int main(){
	int n;
	scanf("%d", &n);
	printf(isPrime(n) ? "prime" : "not prime");
	return 0; 
}
