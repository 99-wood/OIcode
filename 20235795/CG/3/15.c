#include  <stdio.h>
#include  <string.h>
int  main()
{
          void  trim(char  *str);
        char  s[1000];
        gets(s);
        trim(s);
        puts(s);
        return  0;
}
/*在下面编写函数void  trim(char  *str)的代码*/
void trim(char * str){
    int len = strlen(str);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < len; ++i){ //统计抬头空格
        if(str[i] != ' '){
            cnt1 = i;
            break;
        }
    }
    for(int i = len - 1; i >= 0; --i){ //统计末尾空格
        if(str[i] != ' '){
            cnt2 = len - i - 1;
            break;
        }
    }
    for(int i = 0; i + cnt1 < len - cnt2; ++i){ //调整位置
        str[i] = str[i + cnt1];
    }
    str[len - cnt2 - cnt1] = '\0'; //结尾
    return;
}