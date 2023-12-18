#include  <stdio.h>
#include  <string.h>
int  str_r_index(char  *s,  char  *t);
int  main()
{        
        char  s[100],  t[100];
        gets(s);
        gets(t);
        printf("%d",  str_r_index(s,  t));
        return  0;
}
/*在下面编写函数int  str_r_index(char  *s,  char  *t)的代码*/
#include<stdlib.h>
int str_r_index(char *s, char *t){
    int len1 = strlen(s), len2 = strlen(t);
    //KMP 算法
    int * pre = (int *)malloc(sizeof(int) * len2); //数组用于存放 t 前缀的最后位置
    memset(pre, -1, sizeof(int) * len2);
    for(int i = 1; i < len2; ++i){
        int last = pre[i - 1];
        while(last != -1 && t[last + 1] != t[i]){
            last = pre[last];
        }
        if(t[last + 1] == t[i]){
            pre[i] = last + 1;
        }
    }
    int ans = -1;
    int j = -1;
    for(int i = 0; i < len1; ++i){
        while(j != -1 && s[i] != t[j + 1]){
            j = pre[j];
        }
        if(s[i] == t[j + 1]){
            ++j;
        }
        if(j == len2 - 1){
            ans = i - len2 + 1;
        }
    }
    return ans;
}