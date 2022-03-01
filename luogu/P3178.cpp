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
const int MAXN = 100010;
vector<int> tree[MAXN];
int tim = 0;
int siz[MAXN], id[MAXN], dfn[MAXN], son[MAXN], fa[MAXN], top[MAXN], dep[MAXN];
int w[MAXN];
void dfs1(int p, int f){
	siz[p] = 1;
	fa[p] = f;
	int maxx = 0;
	frep(i,0,tree[p].size()){
		int x = tree[p][i];
		if(x == fa[p]) continue;
		dfs1(x,p);
		siz[p] += siz[x];
		if(siz[x] > maxx){
			son[p] = x;
			maxx = siz[x];
		}
	}
	return;
}
void dfs2(int p){
	dfn[p] = ++tim;
	id[dfn[p]] = p;
	dep[p] = dep[fa[p]] + 1;
	if(son[p]){
		top[son[p]] = top[p];
		dfs2(son[p]);
	}
	frep(i,0,tree[p].size()){
		int x = tree[p][i];
		if(x == fa[p] || x == son[p]) continue;
		dfs2(x);
	}
	return;
}

ll a[MAXN << 2], b[MAXN << 2];
void pushdown(int p, int l, int r){
	int m = (l + r) >> 1;
	a[p << 1] += b[p] * (m - l + 1);
	b[p << 1] += b[p];
	a[(p << 1) + 1] += b[p] * (r - m);
	b[(p << 1) + 1] += b[p];
	b[p] = 0;
	return;
}
void build(int p, int l, int r){
	if(l == r){
		a[p] = w[id[l]];
		return;
	}
	int m = (l + r) >> 1;
	build(p << 1, l, m);
	build((p << 1) + 1, m + 1, r);
	a[p] = a[p << 1] + a[(p << 1) + 1];
	return;
}
void modify(int p, int l, int r, int x, int y, ll v){
	if(x <= l && r <= y){
		b[p] += v;
		a[p] += v * (r - l + 1);
		return;
	}
	if(y < l || x > r) return;
	pushdown(p,l,r);
	int m = (l + r) >> 1;
	modify(p << 1, l, m, x, y, v);
	modify((p << 1) + 1, m + 1, r, x, y, v);
	a[p] = a[p << 1] + a[(p << 1) + 1];
	return;
}
ll getsum(int p, int l, int r, int x, int y){
	if(x <= l && r <= y){
		return a[p];
	}
	if(y < l || x > r) return 0;
	pushdown(p,l,r);
	int m = (l + r) >> 1;
	return getsum(p << 1, l, m, x, y) + getsum((p << 1) + 1, m + 1, r, x, y);
}
int main(){
	int n = read(), m = read();
	rep(i,1,n){
		w[i] = read();
		top[i] = i;
	}
	frep(i,1,n){
		int u = read(), v = read();
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1);
	build(1,1,n);
	rep(i,1,m){
		int op = read();
		switch(op){
			case 1:{
				int x = read(), v = read();
				modify(1, 1, n, dfn[x], dfn[x], v);
				break;
			}
			case 2:{
				int x = read(), v = read();
				modify(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, v);
				break;
			}
			case 3:{
				int x = read();
				ll ans = 0;
				while(top[x] != 1){
					ans += getsum(1, 1, n, dfn[top[x]], dfn[x]);
					x = fa[top[x]];
				}
				ans += getsum(1, 1, n, dfn[1], dfn[x]);
				printf("%lld\n",ans);
				break;
			}
		}
	}
	return 0;
}