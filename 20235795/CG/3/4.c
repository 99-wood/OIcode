#include<stdio.h>
#include <string.h>
typedef struct student
{
     int num, sum, score[10];
     double avg;
     char name[10];
}STU;
int main()
{
    STU s[100];
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       //输入
                   scanf("%d%s%d%d%d%d", &s[i].num, s[i].name, &s[i].score[0], &s[i].score[1], &s[i].score[2], &s[i].score[3]);
    }
    for(i=0;i<n;i++)
    {     
                   //计算总分       
                   s[i].sum = 0;    
                   for(int j = 0; j < 4; ++j){
                       s[i].sum += s[i].score[j];
                   }
                   //计算平均分
                   s[i].avg = s[i].sum / 4.0;
    }
    for(i=0;i<n;i++)
    {
        printf("%ld  %s  %d  %0.2lf\n",s[i].num,s[i].name,s[i].sum,s[i].avg);

    }
}

