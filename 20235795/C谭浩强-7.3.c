/*
* File: C-Ã∑∫∆«ø-7.3.c
* Author: 99_wood
* Date: 2023-10-10
*/
#include<stdio.h>
#include<math.h>
#define MAXN 10
#define mid ((l + r) >> 1)
int matrix[MAXN][MAXN]; //æÿ’Û 
int main(){
	int n = 3;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &matrix[i][j]);
		}
	}
	int sum1 = 0, sum2 = 0;
	for(int i = 1; i <= n; ++i){
		sum1 += matrix[i][i];
		sum2 += matrix[i][n - i + 1];
	}
	printf("%d %d", sum1, sum2);
	return 0; 
}
