/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-1
* ��Ŀ��CGƽ̨ top-k����
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>

#define MAXN 20

int num[MAXN]; //����������ݵ����� 

void swap(int *a, int *b){ //�������� 
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
int main(){
	int n = 10;
	int sum = 0;
	double average = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &num[i]);
	}
	//���������ð������ 
	for(int i = 1; i <= n; ++i){
		for(int j = n; j > i; --j){
			if(num[j] > num[j - 1]){
				swap(&num[j], &num[j - 1]);
			}
		}
	}
	printf("%d\n%d\n%d\n", num[1], num[2], num[3]);
	return 0; 
}
