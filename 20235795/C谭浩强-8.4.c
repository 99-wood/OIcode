/*
* File: C-Ã∑∫∆«ø-8.4.c
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
	
	//◊™÷√ 
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			printf("%d ", matrix[j][i]);
		}
		printf("\n");
	}
	return 0; 
}
