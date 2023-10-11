/*
* File: C-Ì·ºÆÇ¿-9.10.c
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

#define MAXN 10010
#define mid ((l + r) >> 1)

int main(){
	char c = getchar();
	while(c != '\n' && c!= EOF){
		if(c >= 'a' && c <= 'z'){ //Ð¡Ð´×ÖÄ¸ 
			printf("%c", 'a' + ((c - 'a' + 1) % ('z' - 'a' + 1))); //×Ö·û×ª»» 
		}
		else printf("%c", c);
		c = getchar();
	}
	return 0; 
}
