#include  <stdio.h>
int  countfreq(char  *t,  char  p);
int  main(){
        char  pattern;
        char  *text  =  "youth  is  not  a  time  of  life;  it  is  a  state  of  mind;  it  is  not  a  matter  of  rosy  cheeks,  red  lips  and  supple  knees;  it  is  a  matter  of  the  will,  a  quality  of  the  imagination,  a  vigor  of  the  emotions;  it  is  the  freshness  of  the  deep  springs  of  life.";
        
        //a在ASCII表中的十进制编号为97
        //A在ASCII表中的十进制编号为65
        scanf("\n%c", &pattern);
        int  count  =  countfreq(text,  pattern);
        printf("%d",  count);
        return  0;
}

int  countfreq(char  *t,  char  p){
    //转化成小写
    if(p >= 'A' && p <= 'Z'){
        p = p + ('a' - 'A');
    }
    int len = strlen(t);
    int cnt = 0;
    for(int i = 0; i < len; ++i){
        cnt += (t[i] == p ||t[i] == p + ('A' - 'a')); //统计
    }
    return cnt;
}