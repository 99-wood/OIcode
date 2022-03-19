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


int w[MAXN * 100], trie[MAXN * 100][2], root[MAXN], end2;
int clone(int p){
	++end2;
	trie[end2][0] = trie[p][0];
	trie[end2][1] = trie[p][1];
	w[end2] = w[p];
	return end2;
}
int add(int p, int h, int a){
	if(p == 0) p = ++end2;
	else p = clone(p);
	++w[p];
	if(h) trie[p][a >> (h - 1) & 1] = add(trie[p][a >> (h - 1) & 1], h - 1, a);
	return p;
}
int ask(int p1, int p2, int h, int a){
	if(!h) return 0;
	int res = 0;
	if(w[trie[p2][a >> (h - 1) & 1 ^ 1]] - w[trie[p1][a >> (h - 1) & 1 ^ 1]]){
		res = 1 << (h - 1);
		res += ask(trie[p1][a >> (h - 1) & 1 ^ 1], trie[p2][a >> (h - 1) & 1 ^ 1], h - 1, a);
	}
	else{
		res += ask(trie[p1][a >> (h - 1) & 1], trie[p2][a >> (h - 1) & 1], h - 1, a);
	}
	return res;
}

int a[MAXN], dep[MAXN], dfn[MAXN], siz[MAXN], son[MAXN], top[MAXN], fa[MAXN], end1;
vector<int> tree[MAXN];
void dfs1(int p, int f){
	fa[p] = f;
	dep[p] = dep[fa[p]] + 1;
	siz[p] = 1;
	int maxx = 0;
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		if(x == fa[p]) continue;
		dfs1(x, p);
		siz[p] += siz[x];
		if(siz[x] > maxx){
			maxx = siz[x];
			son[p] = x;
		}
	}
	return;
}
void dfs2(int p){
	dfn[p] = ++end1;
	root[dfn[p]] = add(root[dfn[p] - 1], 31, a[p]);
	if(son[p]){
		top[son[p]] = top[p];
		dfs2(son[p]);
	};
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		if(x == fa[p] || x == son[p]) continue;
		dfs2(x);
	}
	return;
}

int main(){
	int n = read(), q = read();
	rep(i, 1, n){
		top[i] = i;
		a[i] = read();
	}
	frep(i, 1, n){
		int x = read(), y = read();
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(1);
	while(q--){
		int op = read();
		if(op == 1){
			int x = read(), z = read();
			int ans = ask(root[dfn[x] - 1], root[dfn[x] + siz[x] - 1], 31, z);
			printf("%d\n", ans);
		}
		else{
			int x = read(), y = read(), z = read();
			int ans = 0;
			while(top[x] != top[y]){
				if(dep[top[x]] < dep[top[y]]) swap(x, y);
				ans = max(ans, ask(root[dfn[top[x]] - 1], root[dfn[x]], 31, z));
				x = fa[top[x]];
			}
			if(dep[x] < dep[y]) swap(x, y);
			ans = max(ans, ask(root[dfn[y] - 1], root[dfn[x]], 31, z));
			printf("%d\n", ans);
		}
	}
	return 0;
}
