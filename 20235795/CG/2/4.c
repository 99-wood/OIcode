/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-1
* ��Ŀ��CGƽ̨ ��֮�ظ�����
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>

#define MAXN 20

int num[MAXN]; // ����������ݵ�����
int cnt[200010]; // ���ĳ�������ִ�����Ͱ
 

int main(){
	int n = 10;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &num[i]);
	}
	for(int i = 1; i <= n; ++i){
		++cnt[num[i] + 100000]; // ���� ͬʱ��ֹ�������Խ�� 
	}
	int flag = 1; //�ж��Ƿ����
	for(int i = 1; i <= 200000; ++i){
		if(cnt[i] == 2){ // �����ǰ�����������������
			printf("%6d", i - 100000);
			flag = 0; //�����
		}
	}
	if(flag){
		printf("None");
	}
	return 0; 
}
