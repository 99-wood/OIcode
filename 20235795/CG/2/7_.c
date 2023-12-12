#include  <stdio.h>
#include  <string.h>
#include <stdlib.h>
void  print_words(char  s[]){
    int len = strlen(s);
    char* str = (char*)malloc(sizeof(char) * (len + 10));
    memset(str, 0, sizeof(char) * (len + 10));
    int endd = 0;
    for(int i = 0; i < len; ++i){
        if(s[i] == ' '){
            if(i && s[i - 1] != ' '){
                //找到一段空格的第一个，变为换行
                str[endd++] = '\n';
            }
        }
        else{
            str[endd++] = s[i];
        }
    }
    printf("%s", str);
    free(str);
    return;
}
int  main()
{
        char  s[1000];
        gets(s);
        print_words(s);
        return  0;
}