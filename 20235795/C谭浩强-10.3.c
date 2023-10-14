/*
* File: C-谭浩强-10.3.c
* Author: 99_wood
* Date: 2023-10-12
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//补充 bool 类型 
enum bool {false = 0, true = 1};
#define bool int

#define MAXN 100
#define mid ((l + r) >> 1)

#define swap(a, b) ((a == b) ? :(a ^= b, b ^= a, a ^= b)) //交换宏 

int a[MAXN], n = 10;
void input(){
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	return;
}
void solve(){
	int minn = 1, maxx = n; //最小数和最大数下标
	for(int i = 1; i <= n; ++i) {
		if(a[i] < a[minn]) minn = i;
		if(a[i] > a[maxx]) maxx = i;
	}
	swap(a[1], a[minn]);
	if(maxx == 1) maxx = minn;
	swap(a[n], a[maxx]);
	return;
}
void output(){
	for(int i = 1; i <= n; ++i){
		printf("%d ", a[i]);
	}
	return;
}
int main(){
	input();
	solve();
	output();
	return 0; 
}
