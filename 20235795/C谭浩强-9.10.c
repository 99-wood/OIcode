/*
* File: C-̷��ǿ-9.10.c
* Author: 99_wood
* Date: 2023-10-11
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//���� bool ���� 
enum bool {false = 0, true = 1};
#define bool int

#define MAXN 10010
#define mid ((l + r) >> 1)

int main(){
	char c = getchar();
	while(c != '\n' && c!= EOF){
		if(c >= 'a' && c <= 'z'){ //Сд��ĸ 
			printf("%c", 'a' + ((c - 'a' + 1) % ('z' - 'a' + 1))); //�ַ�ת�� 
		}
		else printf("%c", c);
		c = getchar();
	}
	return 0; 
}
