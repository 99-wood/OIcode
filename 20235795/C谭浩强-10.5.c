/*
* File: C-̷��ǿ-10.5.c
* Author: 99_wood
* Date: 2023-10-13
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//���� bool ���� 
enum bool {false = 0, true = 1};
#define bool int

#define MAXN 10000010
#define mid ((l + r) >> 1)

bool vis[MAXN];
int n;
bool check(){ //�жϻ��Ƿ�����δ���� 
	for(int i = 1; i <= n; ++i){
		if(!vis[i]) return true;
	}
	return false;
}
int main(){
	scanf("%d", &n);
	int cnt = 0, last;
	while(check()){
		for(int i = 1; i <= n; ++i){
			if(!vis[i]){
				++cnt;
				if(cnt % 3 == 0){
					vis[i] = true;
					last = i;
				}
			}
		}
	}
	printf("%d", last);
	return 0; 
}
