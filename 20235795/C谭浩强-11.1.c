/*
* File: C-̷��ǿ-11.1.c
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

#define MAXN 100010
#define mid ((l + r) >> 1)

struct date{
	int y, m, d;
}a;
int f(struct date a){ //������ 
	bool flag = (a.y % 400 == 0 || (a.y % 100 != 0 && a.y % 4 == 0)); //�Ƿ�Ϊ���� 
	int cnt = 0;
	for(int i = 1; i < a.m; ++i){
		if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) cnt += 31; //���� 
		else if(i == 4 || i == 6 || i == 9 ||i == 11) cnt += 30; //С�� 
		else{
			cnt += flag ? 29 : 28; //���� 
		}
	}
	cnt += a.d;
	return cnt; 
}
int main(){
	scanf("%d%d%d", &a.y, &a.m, &a.d);
	printf("%d", f(a));	//������ 
	return 0; 
}
