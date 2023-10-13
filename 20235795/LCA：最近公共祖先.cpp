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
int n, q;
vector<int> tree[MAXN];
int dep[MAXN], top[MAXN], fa[MAXN], son[MAXN], siz[MAXN];
int a[MAXN];
void dfs1(int p, int f){
	fa[p] = f;
	dep[p] = dep[f] + 1;
	siz[p] = 1;
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		dfs1(x, p);
		siz[p] += siz[x];
		son[p] = siz[x] > siz[son[p]] ? x : son[p];
	}
	return;
}
void dfs2(int p){
	if(son[p]){
		top[son[p]] = top[p];
		dfs2(son[p]);
	}
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		if(x == son[p]) continue;
		dfs2(x);
	}
	return;
}
int main(){
	n = read();
	rep(i, 1, n) top[i] = i;
	rep(i, 1, n){
		int m = read();
		rep(j, 1, m){
			tree[i].push_back(read() + 1);
		}
	}
	dfs1(1, 0);
	dfs2(1);
	int q = read();
	while(q--){
		int x = read() + 1, y = read() + 1;
		while(top[x] != top[y]){
			if(dep[top[x]] > dep[top[y]]) x = fa[top[x]];
			else y = fa[top[y]];
		}
		printf("%d\n", dep[x] < dep[y] ? (x - 1) : (y - 1));
	}
	return 0;
}
