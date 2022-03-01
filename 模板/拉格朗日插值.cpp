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
const int MAXN = 2010;
const int MOD = 998244353;

ll quick_pow(int a, int p){
	ll ans = 1, now = a;
	while(p){
		if(p & 1) ans = (ans * now) % MOD;
		now = (now * now) % MOD;
		p >>= 1;
	}
	return ans;
}
ll inv(ll a){
	return quick_pow(a, MOD - 2);
}
int x[MAXN], y[MAXN];
int f[MAXN];
int main(){
	int n = read(), m = read();
	rep(i, 1, n){
		x[i] = read();
		y[i] = read();
	}
	ll ans = 0;
	rep(i, 1, n){
		ll s1 = 1, s2 = 1;
		rep(j, 1, n){
			if(i == j) continue;
			s1 = s1 * (m - x[j]) % MOD;
			s2 = s2 * (x[i] - x[j]) % MOD;
		}
		ans = (ans + y[i] * s1 % MOD * inv(s2) % MOD + MOD * 2) % MOD;
	}
	printf("%lld", ans);
	
	return 0;
}