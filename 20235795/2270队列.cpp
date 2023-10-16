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
#include<bitset>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
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
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 3100;
int n;
ll a[MAXN];
ll mx[MAXN][MAXN], mn[MAXN][MAXN];
int main(){
	n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n){
		mx[i][i] = a[i];
		mn[i][i] = -a[i];
	}
	rep(k, 2, n){
		rep(i, 1, n - k + 1){
			mx[i][i + k - 1] = max(mn[i][i + k - 2] + a[i + k - 1], mn[i + 1][i + k - 1] + a[i]);
			mn[i][i + k - 1] = min(mx[i][i + k - 2] - a[i + k - 1], mx[i + 1][i + k - 1] - a[i]);
		}
	}
	printf("%lld", mx[1][n]);
	return 0;
}
