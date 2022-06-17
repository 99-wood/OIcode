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
const int MAXN = 210;
int prime[MAXN], c[MAXN * 10], endd;
void init(){
	for(int i = 2; endd < 100; ++i){
		if(!c[i]){
			c[i] = i;
			prime[++endd] = i;
		}
		for(int j = 1; j <= endd && prime[j] <= c[i] && prime[j] * i < MAXN * 10; ++j){
			c[prime[j] * i] = prime[j];
		}
	}
}
ll e[MAXN];
int main(){
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
	init();
	int t = read();
	while(t--){
		int m = read();
		ll ans = 0;
		rep(i, 1, m){
			scanf("%lld", &e[i]);
			ans = max(ans, e[i] * prime[i]);
		}
		printf("%lld\n", ans);
		
	}
	return 0;
}