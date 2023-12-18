#include  <stdio.h>
#include  <string.h>
int  main()
{        void  spe_copy(char  *s,  char  *t);
        char  s[100],  t[100];
        gets(s);
        spe_copy(s,  t);
        puts(t);
        return  0;
}
/*在下面编写函数void  spe_copy(char  *s,  char  *t)的代码*/
void spe_copy(char *s,  char *t){
    int last = 0;
    int len = strlen(s);
    for(int i = 0; i < len; ++i){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            t[last++] = s[i];
        }
    }
    t[last] = '\0';
    return;
}