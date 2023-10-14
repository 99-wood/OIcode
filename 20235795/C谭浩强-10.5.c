/*
* File: C-Ì·ºÆÇ¿-10.5.c
* Author: 99_wood
* Date: 2023-10-12
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//²¹³ä bool ÀàÐÍ 
enum bool {false = 0, true = 1};
#define bool int

#define MAXN 10000010
#define mid ((l + r) >> 1)

int vis[MAXN], n;
bool check(){
	for(int i = 1; i <= n; ++i){
		if(!vis[i]) return true;
	}
	return false;
}
int main(){
	int last = 0;
	int cnt = 0;
	scanf("%d", &n);
	while(check()){
		for(int i = 1; i <= n; ++i){
			if(!vis[i]){ //Î´ 
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
