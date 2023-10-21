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
int n, m;
struct block{
	int l, r, w;
}s[MAXN];
struct node{
	ll ans, tag;
}tree[MAXN << 2];
void pushdown(int p, int l, int r){
	tree[ls].ans += tree[p].tag;
	tree[rs].ans += tree[p].tag;
	tree[ls].tag += tree[p].tag;
	tree[rs].tag += tree[p].tag;
	tree[p].tag = 0;
	return;
}
void pushup(int p, int l, int r){
	tree[p].ans = max(tree[ls].ans, tree[rs].ans);
	return;
}
void modify(int p, int l, int r, int x, int y, ll w){
	if(x <= l && r <= y){
		tree[p].tag += w;
		tree[p].ans += w;
		return;
	}
	if(y < l || r < x) return;
	pushdown(p, l, r);
	modify(ls, l, mid, x, y, w);
	modify(rs, mid + 1, r, x, y, w);
	pushup(p, l, r);
	return;
}
ll query(int p, int l, int r, int x, int y){
	if(x <= l && r <= y) return tree[p].ans;
	if(y < l || r < x) return 0;
	pushdown(p, l, r);
	ll res = max(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
	pushup(p, l, r);
	return res;
}
int main(){
	n = read(), m = read();
	rep(i, 1, m){
		s[i].l = read();
		s[i].r = read();
		s[i].w = read();
	}
	sort(s + 1, s + 1 + m, [&](struct block a, struct block b){
		return a.r < b.r;
	});
	int last = 1;
	rep(i, 1, n){
		modify(1, 1, n, i, i, max(query(1, 1, n, 1, i - 1), (ll)0));
		while(s[last].r == i){
			modify(1, 1, n, s[last].l, i, s[last].w);
			++last;
		}
	}
	printf("%lld", max(query(1, 1, n, 1, n), (ll)0));
	return 0;
}
