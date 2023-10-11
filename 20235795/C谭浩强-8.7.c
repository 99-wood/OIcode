/*
* File: C-谭浩强-8.7.c
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
char str[MAXN], ans[MAXN];
int endd = 0;
int main(){
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; ++i){
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || 
			str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
			if(str[i] >= 'a' && str[i] <= 'z'){ //小写 
				ans[endd++] = str[i];
			}
			else{ //大写 
				ans[endd++] = 'a' + (str[i] - 'A');
			}
		}
	}
	printf("%s", ans);
	return 0; 
}
