/*
* File: C-̷��ǿ-10.5.c
* Author: 99_wood
<<<<<<< HEAD
* Date: 2023-10-12
=======
* Date: 2023-10-13
>>>>>>> e6800dba418aa3fa279aa43bae6599d8a379eaca
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

<<<<<<< HEAD
int vis[MAXN], n;
bool check(){
=======
bool vis[MAXN];
int n;
bool check(){ //�жϻ��Ƿ�����δ���� 
>>>>>>> e6800dba418aa3fa279aa43bae6599d8a379eaca
	for(int i = 1; i <= n; ++i){
		if(!vis[i]) return true;
	}
	return false;
}
int main(){
<<<<<<< HEAD
	int last = 0;
	int cnt = 0;
	scanf("%d", &n);
	while(check()){
		for(int i = 1; i <= n; ++i){
			if(!vis[i]){ //δ 
=======
	scanf("%d", &n);
	int cnt = 0, last;
	while(check()){
		for(int i = 1; i <= n; ++i){
			if(!vis[i]){
>>>>>>> e6800dba418aa3fa279aa43bae6599d8a379eaca
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
