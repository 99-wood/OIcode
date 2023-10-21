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
const int MAXN = 2e5 + 10;
const int MOD  = 1e9 + 7;
int jc[MAXN];
int jcinv[MAXN];
int ksm(int a, int k){
	int ans = 1, now = a;
	while(k){
		if(k & 1) ans = ((ll) ans * now) % MOD;
		now = ((ll)now * now) % MOD;
		k >>= 1;
	}
	return ans;
}
struct point{
	int x, y;
}bar[MAXN];
int f[MAXN];
int getans(int x, int y){
	int d = ((ll)jcinv[x] * jcinv[y]) % MOD;
	return ((ll)jc[x + y] * d) % MOD;
}
int main(){
	jc[0] = 1;
	rep(i, 1, 2e5 + 5) jc[i] = ((ll)jc[i - 1] * i) % MOD;
	jcinv[200000] = ksm(jc[200000], MOD - 2);
	drep(i, 200000 - 1, 0) jcinv[i] = ((ll)jcinv[i + 1] * (i + 1)) % MOD;
	int h = read(), w = read();
	int n = read();
	rep(i, 1, n){
		bar[i].x = read();
		bar[i].y = read();
	}
	++n;
	bar[n].x = h;
	bar[n].y = w; 
	sort(bar + 1, bar + n + 1, [&](struct point a, struct point b){
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	});
	rep(i, 1, n){
		int x = bar[i].x, y = bar[i].y;
		f[i] = getans(x - 1, y - 1);
		rep(j, 1, i - 1){
			if(bar[j].x <= x && bar[j].y <= y){
				f[i] = (f[i] - (((ll)f[j] * getans(x - bar[j].x, y - bar[j].y)) % MOD) + MOD) % MOD;
			}
		}
	}
	printf("%d", f[n]);
	return 0;
}
