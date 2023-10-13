/*
* File: C-谭浩强-11.5.c
* Author: 99_wood
* Date: 2023-10-13
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//补充 bool 类型 
enum bool {false = 0, true = 1};
#define bool int

#define MAXN 110
#define mid ((l + r) >> 1)

struct Student{
	char num[MAXN], name[MAXN];
	int score1, score2, score3, sumScore;
}student[MAXN];
int main(){
	int n;
	scanf("%d", &n);
	int maxx = 1; //最高分下标 
	double avg1 = 0, avg2 = 0, avg3 = 0; //平均分 
	for(int i = 1; i <= n; ++i){
		scanf("%s%s%d%d%d", student[i].num, student[i].name, &student[i].score1, &student[i].score2, &student[i].score3);
		student[i].sumScore = (student[i].score1 + student[i].score2 + student[i].score3);
		if(student[i].sumScore > student[maxx].sumScore) maxx = i;
		avg1 += student[i].score1;
		avg2 += student[i].score2;
		avg3 += student[i].score3; 
	}
	avg1 /= n;
	avg2 /= n;
	avg3 /= n;
	printf("%.0lf %.0lf %.0lf\n", avg1, avg2, avg3);
	printf("%s %s %d %d %d\n", student[maxx].num, student[maxx].name, student[maxx].score1, student[maxx].score2, student[maxx].score3); 
	return 0; 
}
