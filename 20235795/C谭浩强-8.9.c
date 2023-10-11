/*
* File: C-谭浩强-8.9.c
* Author: 99_wood
* Date: 2023-10-10
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//补充 bool 类型 
enum bool {false = 0, true = 1};
#define bool int

#define MAXN 10010
#define mid ((l + r) >> 1)
int main(){
	char c = getchar();
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0; // 字母，数字，空格，其他 
	while(c != '\n' && c != EOF){
		if((c >= 'A' && c <='Z') || (c >= 'a' && c <= 'z')) ++cnt1;
		else if(c >= '0' && c <= '9') ++cnt2;
		else if(c == ' ') ++cnt3;
		else ++cnt4;
		c = getchar();
	}
	printf("%d %d %d %d", cnt1, cnt2, cnt3, cnt4);
	return 0; 
}
