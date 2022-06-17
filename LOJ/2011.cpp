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
const int MAXN = 2e5 + 10;
vector<int> nxt[MAXN];
int root[MAXN];
#define ls tree[p].l
#define rs tree[p].r
#define mid ((l + r) >> 1)
struct node{
	int l, r, w;
}tree[MAXN * 50];
int endd;
void build(int p, int l, int r){
	if(l == r) return;
	ls = ++endd;
	rs = ++endd;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	return;
}
int clone(int p){
	++endd;
	tree[endd] = tree[p];
	return endd;
}
int modify(int p, int l, int r, int x){
	p = clone(p);
	if(l == r){
		++tree[p].w;
		return p;
	}
	if(x <= mid) ls = modify(ls, l, mid, x);
	else rs = modify(rs, mid + 1, r, x);
	++tree[p].w;
	return p;
}
int query(int p, int l, int r, int x, int y){
	if(x <= l && r <= y) return tree[p].w;
	if(r < x || l > y) return 0;
	return query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
}
#undef ls
#undef rs
#undef mid
int fa[MAXN], top[MAXN], id[MAXN], dfn[MAXN], siz[MAXN], son[MAXN], dep[MAXN], end1, r;
void dfs1(int p){
	dep[p] = dep[fa[p]] + 1;
	siz[p] = 1;
	for(auto x : nxt[p]){
		dfs1(x);
		siz[p] += siz[x];
		if(siz[x] > siz[son[p]]) son[p] = x;
	}
	return;
}
void dfs2(int p){
	dfn[p] = ++end1;
	if(son[p]){
		top[son[p]] = top[p];
		dfs2(son[p]);
	}
	for(auto x : nxt[p]){
		if(x == son[p]) continue;
		dfs2(x);
	}
	return;
}
int main(){
	int n = read();
	rep(i, 1, n) top[i] = i;
	rep(i, 1, n){
		fa[i] = read();
		if(!fa[i]) r = i;
		else nxt[fa[i]].push_back(i);
	}
	dfs1(r);
	dfs2(r);
	int m = read();
	build(0, 1, n);
	rep(t, 1, m){
		root[t] = root[t - 1];
		int op = read();
		if(op == 1){
			int x = read(), y = read(), d = read();
			d = t - d - 1;
			int ans = 0, cnt = 0;;
			while(top[x] != top[y]){
				if(dep[top[x]] < dep[top[y]]) swap(x, y);
				ans += query(root[d], 1, n, dfn[top[x]], dfn[x]);
				cnt += dfn[x] - dfn[top[x]] + 1;
				x = fa[top[x]];
			}
			if(dep[x] > dep[y]) swap(x, y);
			ans += query(root[d], 1, n, dfn[x], dfn[y]);
			cnt += dfn[y] - dfn[x] + 1;
			printf("%d %d\n", cnt, ans);
		}
		else{
			int x = read();
			root[t] = modify(root[t], 1, n, dfn[x]);
		}
	}
	return 0;
}