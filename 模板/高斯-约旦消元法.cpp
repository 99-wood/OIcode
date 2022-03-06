#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
int mylog(int a) {
	int ans=0;
	if(a&0xffff0000) {
		ans+=16;
		a>>=16;
	}
	if(a&0x0000ff00) {
		ans+=8;
		a>>=8;
	}
	if(a&0x000000f0) {
		ans+=4;
		a>>=4;
	}
	if(a&0x0000000c) {
		ans+=2;
		a>>=2;
	}
	if(a&0x00000002) {
		ans+=1;
		a>>=1;
	}
	return ans;
}
inline int read() {
	register int a=0,b=0;
	register char c;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')b=1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 310;
double a[MAXN][MAXN];
int main(){
	int n = read();
	rep(i, 1, n){
		rep(j, 1, n + 1){
			scanf("%lf", &a[i][j]);
		}
	}
	rep(i, 1, n){
		int pos = i;
		rep(j, i + 1, n){
			if(fabs(a[j][i]) >= fabs(a[pos][i])) pos = j;
		}
		rep(j, 1, n + 1){
			swap(a[i][j], a[pos][j]);
		}
		if(!a[i][i]){
			//系数全为0先跳过，假装已经完成第i列
			continue;
		}
		rep(j, 1, n){
			if(j != i){
				double tmp = a[j][i] / a[i][i];
				rep(k, i, n + 1){
					a[j][k] -= tmp * a[i][k];
				}
			}
		}
	}
	bool flag = false;
	rep(i, 1, n){
		if(!a[i][i]){
			if(a[i][n + 1]){
				//优先无解
				printf("%d", -1);
				return 0;
			}
			else{
				flag = 1;
			}
		}
	}
	if(flag){
		printf("%d", 0);
		return 0;
	}
	rep(i, 1, n){
		printf("x%d=%.2lf\n", i, fabs(a[i][n + 1] / a[i][i]) < 0.005 ? 0 : a[i][n + 1] / a[i][i]);
	}
	return 0;
}