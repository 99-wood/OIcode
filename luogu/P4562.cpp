#include<iostream>
#include<cstdio>
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
const int MAXN = 1e7 + 10;
const int MOD = 1e9 + 7;
bool vis[MAXN];
ll fac[MAXN];
ll finv[MAXN];
ll quick_pow(int a, int p){
	ll now = a, ans = 1;
	for(int i = 0; p >> i; ++i){
		if((p >> i) & 1) ans = (ans * now) % MOD;
		now = (now * now) % MOD;
	}
	return ans;
}
ll inv(int a){
	return quick_pow(a % MOD, MOD - 2);
}
int main(){
	int l = read(), r = read();
	int cnt = 0;
	rep(i, l, r){
		if(vis[i]) continue;
		++cnt;
		int k = i;
		for(int j = i; j <= r; j += k){
			vis[j] = true;
		}
	}
	int n = (r - l + 1), m = cnt;
	fac[0] = 1;
	rep(i, 1, n) fac[i] = (fac[i- 1] * i) % MOD;
	finv[n] = inv(fac[n]);
	drep(i, n - 1, 0) finv[i] = finv[i + 1] * (i + 1) % MOD;
	ll ans = 0;
	rep(i, m, n){
		ll tmp = ((ll)m * fac[i - 1] % MOD) * (fac[n - m] * finv[n - i] % MOD * finv[i - m] % MOD) % MOD * fac[n - i] % MOD * i % MOD;
		ans = (ans + tmp) % MOD;
	}
	printf("%lld", ans);
	return 0;
}