#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define ll long long
#define ull unsigned long long
using namespace std;
int l[100010];
int mapp[100010];
int ans[100010]={0x3f3f3f3f};
int size=1;
int bs(int l,int r,int a){
	int re=r;
	while(l<r){
		int m=(l+r)>>1;
		if(ans[m]>a){
			re=m;
			r=m;
		}
		else{
			l=m+1;
		}
	}
	return re;
}
int main(){
	int n;
	scanf("%d",&n);
	if(n==0){
		printf("0");
		return 0;
	}
	for(int i=0;i<n;++i){
		int temp;
		scanf("%d",&temp);
		mapp[temp]=i;
	}
	for(int i=0;i<n;++i){
		int temp;
		scanf("%d",&temp);
		l[i]=mapp[temp];
	}
	for(int i=0;i<n;++i){
		if(l[i]>ans[size-1]){
			ans[size++]=l[i];
		}
		else{
			int p=bs(0,size,l[i]);
			ans[p]=l[i];
		}
	}
	printf("%d",size);
	return 0;
}
