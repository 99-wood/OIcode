#include<stdio.h>
void fun(char *s, char c);
int main()
{ 
    char str[50],c;
    gets(str);
    scanf("%c", &c);
    fun(str, c);
    return 0;
}  
#include<string.h>
void fun(char *s,  char c){
    int flag = 1;
    int len = strlen(s);
    for(int i = 0; i < len; ++i){
        if(s[i] == c){
            flag = 0;
        }
    }
    if(flag){ //未出现该字符
        printf("%c not exist in\n",c);
        printf("%s", s);
        return;
    }
    else{//出现该字符
        for(int i = 0; i < len; ++i){
            if(s[i] == c){//出现该字符
                continue;
            }
            putchar(s[i]);
        }
        return;
    }
} 

