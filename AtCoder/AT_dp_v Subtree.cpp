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
int MOD;
int n;
vector<int> tree[MAXN];
int siz[MAXN];
int f[MAXN];
int ff[MAXN];
void dfs1(int p, int fa){
	siz[p] = 1;
	f[p] = 1;
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		if(x == fa) continue;
		dfs1(x, p);
		siz[p] += siz[x];
		f[p] = ((ll)(f[x] + 1) * f[p]) % MOD;
	}
	return;
}
void dfs2(int p, int fa, int w){
	int pre[tree[p].size() + 2], suf[tree[p].size() + 2];
	ff[p] = ((ll)(w + 1) * f[p]) % MOD;
	pre[0] = 1;
	frep(i, 0, tree[p].size()){
		pre[i + 1] = pre[i];
		int x = tree[p][i];
		if(x == fa) continue;
		pre[i + 1] = ((ll)pre[i + 1] * (f[x] + 1)) % MOD;
	}
	suf[tree[p].size() + 1] = 1;
	drep(i, tree[p].size() - 1, 0){
		suf[i + 1] = suf[i + 2];
		int x = tree[p][i];
		if(x == fa) continue;
		suf[i + 1] = ((ll)suf[i + 1] * (f[x] + 1)) % MOD;
	}
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		if(x == fa) continue;
		int tmp = ((ll)pre[i] * suf[i + 2]) % MOD;
		dfs2(x, p, ((ll)tmp * (w + 1)) % MOD);
	}
}
int main(){
	n = read(); MOD = read();
	rep(i, 1, n - 1){
		int x = read(), y = read();
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	rep(i, 1, n){
		printf("%d\n", ff[i]);
	}
	return 0;
}
