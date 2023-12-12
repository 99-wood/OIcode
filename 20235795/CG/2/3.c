/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-1
* ��Ŀ��CGƽ̨ ����򵥲���
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>

#define MAXN 10

int num[MAXN][MAXN]; //����������ݵ����� 

void swap(int *a, int *b){ //�������� 
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

int main(){
	int n = 5;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &num[i][j]);
		}
	}
	//��ÿ���������ŵ���һ�� 
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(num[i][j] > num[i][1]){
				swap(&num[i][j], &num[i][1]);
			}
		}
	}
	int ans = 1;
	for(int i = 1; i <= n; ++i){
		if(num[i][1] < num[ans][1]){ //�����ǰ�е����ֵС�ڵ�ǰ�⣬����� 
			ans = i;
		}
	}
	printf("%d", num[ans][1]);
	return 0; 
}
