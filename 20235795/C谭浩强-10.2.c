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

#define MAXN 100
#define mid ((l + r) >> 1)

char t[MAXN][MAXN];

struct string{
	char s[MAXN];
	
	void get(){
		scanf("%s", s);
		return
	}
	int len(){
		return strlen(s);
	}
	operator [](int a){
		return s[a];
	}
	bool operator < (struct string b){
		int len1 = len(), len2 = b.len();
		int len = (len1 < len1) ? len1 : len2;
		for(int i = 0; i < len; ++i){
			if(s[i] < b[i]) return true;
			else if(s[i] > b[i]) return false;
		}
		return len1 < len2;
	}
}a[MAXN];

int main(){
	int n = 3;
	for(int i = 1; i <= n; ++i){
	}
//	sort(str, 1, n);
	for(int i = 1; i <= n; ++i){
	}
	return 0; 
}
