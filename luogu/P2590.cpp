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
int a[MAXN << 2], b[MAXN << 2];
void build(int p, int l, int r){
	if(l == r){
		b[p] = a[p] = w[id[l]];
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	a[p] = a[ls] + a[rs];
	b[p] = max(b[ls], b[rs]);
	return;
}
void modify(int p, int l, int r, int x, int w){
	if(l == r){
		a[p] = b[p] = w;
		return;
	}
	if(x <= mid)modify(ls, l, mid, x, w);
	else modify(rs, mid + 1, r, x, w);
	a[p] = a[ls] + a[rs];
	b[p] = max(b[ls], b[rs]);
	return;
}
int getsum(int p, int l, int r, int x, int y){
	if(x <= l && y >= r){
		return a[p];
	}
	if(x > r || y < l) return 0;
	return getsum(ls, l, mid, x, y) + getsum(rs, mid + 1, r, x, y);
}
int getmax(int p, int l, int r, int x, int y){
	if(x <= l && y >= r){
		return b[p];
	}
	if(x > r || y < l) return -1000000;
	return max(getmax(ls, l, mid, x, y), getmax(rs, mid + 1, r, x, y));
}
int main(){
	int n = read();
	frep(i,1,n){
		int x = read(), y = read();
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	rep(i,1,n){
		top[i] = i;
		w[i] = read();
	}
	dfs1(1,0);
	dfs2(1);
	build(1, 1, n);
	int q = read();
	while(q--){
		char op[10];
		scanf("\n%s", op);
		switch(op[0] + op[1]){
			case 'C' + 'H' :{
				int x = read(), w = read();
				modify(1, 1, n, dfn[x], w);
				break;
			}
			case 'Q' + 'S' :{
				int x = read(), y = read();
				int ans = 0;
				while(top[x] != top[y]){
					if(dep[top[x]] < dep[top[y]]) swap(x, y);
					ans += getsum(1, 1, n, dfn[top[x]], dfn[x]);
					x = fa[top[x]];
				}
				if(dep[x] < dep[y]) swap(x, y);
				ans += getsum(1, 1, n, dfn[y], dfn[x]);
				printf("%d\n", ans);
				break;
			}
			case 'Q' + 'M' :{
				int x = read(), y = read();
				int ans = -1000000;
				while(top[x] != top[y]){
					if(dep[top[x]] < dep[top[y]]) swap(x, y);
					ans = max(ans, getmax(1, 1, n, dfn[top[x]], dfn[x]));
					x = fa[top[x]];
				}
				if(dep[x] < dep[y]) swap(x, y);
				ans = max(ans, getmax(1, 1, n, dfn[y], dfn[x]));
				printf("%d\n", ans);
				break;
			}
		}
	}
	return 0;
}