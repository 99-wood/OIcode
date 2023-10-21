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
const int MAXN = 20;
ll f[1 << MAXN];
//ll w[1 << MAXN];
int a[MAXN][MAXN];
bool vis[1 << MAXN];
int n;
ll solve(int now){
	if(vis[now]) return f[now];
	vis[now] = true;
	for(int i = now; i; i = (i - 1) & now){
		f[now] = max(f[now], f[now ^ i] + solve(i));
	}
	return f[now];
}
int main(){
	n = read();
	frep(i, 0, n){
		frep(j, 0, n){
			a[i][j] = read();
		}
	}
	frep(i, 1, 1 << n){
		frep(j, 0, n){
			if(i & (1 << j)) continue;
			if(vis[i | (1 << j)]) continue;
			f[i | (1 << j)] = f[i];
			vis[i | (1 << j)] = true;
			frep(k, 0, n){
				if(i & (1 << k)){
					f[i | (1 << j)] += a[j][k];
				}
			}
		}
	}
	memset(vis, false, sizeof(vis));
	vis[0] = true;
	printf("%lld", solve((1 << n) - 1));
	return 0;
}
