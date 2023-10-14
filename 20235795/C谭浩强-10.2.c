/*
* File: C-Ì·ºÆÇ¿-10.2.c
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
}str[MAXN];
int len(struct string a){ //×Ö·û´®½á¹¹Ìå 
	return strlen(a.s);
}
bool cmp (struct string a, struct string b){ //±È½Ï×Ö·û´®×ÖµäÐò 
	int len1 = len(a), len2 = len(b);
	int l = len1 < len2 ? len1 : len2;
	for(int i = 0; i < l; ++i){
		if(a.s[i] < b.s[i]) return true;
		else if(a.s[i] > b.s[i]) return false;
	}
	return len1 < len2;
}
int main(){
	int n = 3;
	for(int i = 1; i <= n; ++i){
		scanf("%s", str[i].s);
	}
	
	//Ã°ÅÝÅÅÐò 
	for(int i = 1; i <= n; ++i){
		for(int j = n; j > i; --j){ 
			if(cmp(str[j], str[j - 1])){
				struct string tmp;
				tmp = str[j];
				str[j] = str[j - 1];
				str[j - 1] = tmp;
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		printf("%s\n", str[i].s);
	}
	return 0; 
}
