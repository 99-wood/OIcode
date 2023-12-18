#include  <stdio.h>
#include  <string.h>
int  main()
{        void  sta(char  *s,  int  *a);
        char  s[100];
        int  i,  a[4];
        gets(s);
        sta(s,  a);
        for(i=0;  i<4;  i++)
                printf("%3d",  a[i]);
        return  0;
}
/*在下面编写函数void  sta(char  *s,  int  *a)的代码*/
void sta(char * s, int * a){
    int len = strlen(s);
    memset(a, 0, sizeof(a));
    for(int i = 0; i < len; ++i){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){ //字母
            ++a[0];
        }
        else if(s[i] >= '0' && s[i] <= '9'){ //数组
            ++a[1];
        }
        else if(s[i] == ' '){ //空格
            ++a[2];
        }
        else{ //其他
            ++a[3];
        }
    }
    return;
}