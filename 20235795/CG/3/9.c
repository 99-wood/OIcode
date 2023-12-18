#include  <stdio.h>
#include  <string.h>
int  main()
{
        void  sn(char  *s);
        char  str[1000];
        char  *p=str;
        int  k;
        gets(str);
        sn(p);
        return  0;
}
void sn(char *s){
    int cnt = 0;
    int len = strlen(s);
    for(int i = 0; i < len; ++i){
        if(i && s[i] != s[i - 1]){ //与上一个字符不同
            printf("%c#%d", s[i - 1], cnt);
            cnt = 1;
        }
        else{
            ++cnt; //计数
        }
    }
    printf("%c#%d", s[len - 1], cnt);
    return;
}