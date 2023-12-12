#include  <stdio.h>
#include  <string.h>
int  strtoint(char  s[]){
    int len = strlen(s);
    int ans = 0;
    for(int i = 0; i < len; ++i){
        if(s[i] >= '0' && s[i] <= '9'){ //判断是否为数字
            ans = (ans * 10) + (s[i] - '0');
        }
    }
    return ans;
}
int  main()
{
        char  str[1000];
        int  k;
        gets(str);
        k=strtoint(str);
        printf("%d",k);
        return  0;
}