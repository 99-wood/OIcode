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
const int MAXN = 1e6;
int n, m;
int a[MAXN];

#define ls (p << 1)
#define rs (p << 1| 1)
#define mid ((l + r) >> 1)
struct node{
	bool tag;
	int lc, rc;
	ll w, lw, rw;
}tree[MAXN];
void pushup(int p, int l, int r){
	tree[p].lc = tree[ls].lc;
	tree[p].rc = tree[rs].rc;
	tree[p].w = tree[ls].w + tree[rs].w + (tree[ls].rc != tree[rs].lc ? tree[ls].rw * tree[rs].lw : 0);
	tree[p].lw = (tree[ls].lw == (mid - l + 1) ? 
		(tree[ls].rc != tree[rs].lc ? tree[ls].lw + tree[rs].lw : tree[ls].lw) :
		tree[ls].lw);
	tree[p].rw = (tree[rs].rw == (r - mid) ? 
		(tree[ls].rc != tree[rs].lc ? tree[rs].rw + tree[ls].rw : tree[rs].rw) :
		tree[rs].rw);
	return;
}
void pushdown(int p, int l, int r){
	if(!tree[p].tag) return;
	tree[p].tag = false;
	tree[ls].lc ^= 1;
	tree[ls].rc ^= 1;
	tree[rs].lc ^= 1;
	tree[rs].rc ^= 1;
	tree[ls].tag ^= 1;
	tree[rs].tag ^= 1;
	return;
}
void build(int p, int l, int r){
	if(l == r){
		tree[p].lc = tree[p].rc = a[l];
		tree[p].w = tree[p].lw = tree[p].rw = 1;
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p, l, r);
	return;
}
void modify(int p, int l, int r, int x, int y){
	if(x <= l && r <= y){
		tree[p].tag ^= 1;
		tree[p].lc ^= 1;
		tree[p].rc ^= 1;
		return;
	}
	if(l > y || r < x) return;
	pushdown(p, l, r);
	modify(ls, l, mid, x, y);
	modify(rs, mid + 1, r, x, y);
	pushup(p, l, r);
	return;
}
struct node query(int p, int l, int r, int x, int y){
	if(x <= l && r <= y){
		return tree[p];
	}
	pushdown(p, l, r);
	if(y <= mid) return query(ls, l, mid, x, y);
	else if(x > mid)  return query(rs, mid + 1, r, x, y);
	else{
		struct node la = query(ls, l, mid, x, y);
		struct node ra = query(rs, mid + 1, r, x, y);
		struct node ans;
		ans.lc = la.lc;
		ans.rc = ra.rc;
		ans.w = la.w + ra.w + (la.rc != ra.lc ? la.rw * ra.lw : 0);
		ans.lw = (la.lw == (mid - max(l, x) + 1) ? 
			(la.rc != ra.lc ? la.lw + ra.lw : la.lw) :
			la.lw);
		ans.rw = (ra.rw == (min(y, r) - mid) ? 
			(la.rc != ra.lc ? ra.rw + la.rw : ra.rw) :
			ra.rw);
		return ans;
	}
}
int main(){
	n = read(), m = read();
	rep(i, 1, n) a[i] = read();
	build(1, 1, n);
	while(m--){
		int op = read();
		if(op == 1){
			int x = read(), y = read();
			modify(1, 1, n, x, y);
		}
		else{
			int x = read(), y = read();
			struct node ans = query(1, 1, n, x, y);
			printf("%lld\n", ans.w);
		}
	}
	return 0;
}