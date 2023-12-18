#include<stdio.h>
#include<string.h>
int  main()
{
        void  str_bin(char  *str1,  char  *str2);
        char  s1[100],s2[100];
        gets(s1);
        gets(s2);
        str_bin(s1,  s2);
        puts(s1);
        return  0;
}
/*在下面编写函数void  str_bin(char  *str1,  char  *str2)的程序代码*/
#include<stdlib.h>
void str_bin(char * str1, char * str2){
    int len1 = strlen(str1), len2 = strlen(str2);
    char * str = (char *)malloc(sizeof(char) * (len1 + len2)); //申请临时数组
    int i = 0, j = 0, k = 0;
    while(i < len1 && j < len2){ //比较
        if(str1[i] < str2[j]){
        	if(k && str1[i] == str[k - 1]){ //去重
        		++i;
			}
            else{
            	str[k++] = str1[i++];
			}
        }
        else{
        	if(k && str2[j] == str[k - 1]){
        		++j;
			}
            else{
            	str[k++] = str2[j++];
			}
        }
    }
    while(i < len1){ //处理剩余
        if(k && str1[i] == str[k - 1]){
    		++i;
		}
        else{
        	str[k++] = str1[i++];
		}
    }
    while(j < len2){
        if(k && str2[j] == str[k - 1]){
    		++j;
		}
        else{
        	str[k++] = str2[j++];
		}
    }
    for(int kk = 0; kk < k; ++kk){
        str1[kk] = str[kk];
    }
    str1[k] = '\0';
    free(str);
    return;
}