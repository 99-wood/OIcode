/*
* File: C-Ì·ºÆÇ¿-10.1.c
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

#define MAXN 10
#define mid ((l + r) >> 1)

int a[MAXN], tmp[MAXN];
void sort(int l, int r){
	if(l == r) return;
	sort(l, mid);
	sort(mid + 1, r);
	int i = l, j = mid + 1, k = l;
	while(i <= mid && j <= r){
		if(a[i] < a[j]){
			tmp[k++] = a[i++];
		}
		else{
			tmp[k++] = a[j++];
		}
	}
	while(i <= mid) tmp[k++] = a[i++];
	while(j <= r) tmp[k++] = a[j++];
	for(k = l; k <= r; k++) a[k] = tmp[k];
	return; 
}

int main(){
	int n = 3;
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(1, n);
	for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
	return 0; 
}
