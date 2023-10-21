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
const int MAXN = 2e4 + 10;
int n;
struct node{
	int s, w, v;
}a[MAXN];
ll f[MAXN];
int main(){
	n = read();
	rep(i, 1, n){
		a[i].w = read();
		a[i].s = read();
		a[i].v = read();
	}
	sort(a + 1, a + 1 + n, [&](struct node a, struct node b){
		return a.s + a.w < b.s + b.w;
	});
	rep(i, 1, n){
		drep(j, a[i].s + a[i].w, a[i].w){
			f[j] = max(f[j], f[j - a[i].w] + a[i].v);
		}
	}
	ll ans = 0;
	rep(i, 1, 2e4) ans = max(ans, f[i]);
	printf("%lld", ans);
	return 0;
}
