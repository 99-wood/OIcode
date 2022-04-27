#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define ll long long
using namespace std;
int n,m;
long long C[1<<13][1<<13];
void add(int x,int y,int k){
	for(int i=x;i<=n;i+=i&(-i)){
		for(int j=y;j<=m;j+=j&(-j)){
			C[i][j]+=k;
		}
	}
	return;
}
long long ask(int x,int y){
	long long ans=0;
	for(int i=x;i>0;i-=i&(-i)){
		for(int j=y;j>0;j-=j&(-j)){
			ans+=C[i][j];
		}
	}
	return ans;
}
int main() {
//	freopen("11.in","r",stdin);
	scanf("%d%d",&n,&m);
	int a;
	while(scanf("%d",&a)!=EOF){
		if(a==1){
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			add(x,y,k);
		}
		else{
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%lld\n",ask(x2,y2)-ask(x2,y1-1)-ask(x1-1,y2)+ask(x1-1,y1-1));
		}
	}
    return 0;
}
