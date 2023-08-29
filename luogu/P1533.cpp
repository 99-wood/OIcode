#include<iostream>
#include<cstdio>
#include<cstdlib>
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
#define ls tree[p].l
#define rs tree[p].r
#define mid ((l + r) >> 1)
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
int mylog(int a){
	int ans=0;
	if(a&0xffff0000){
		ans+=16;
		a>>=16;
	}
	if(a&0x0000ff00){
		ans+=8;
		a>>=8;
	}
	if(a&0x000000f0){
		ans+=4;
		a>>=4;
	}
	if(a&0x0000000c){
		ans+=2;
		a>>=2;
	}
	if(a&0x00000002){
		ans+=1;
		a>>=1;
	}
	return ans;
}
inline int read(){
	register int a=0,b=0;
	register char c;
	c=getchar();
	while(c<'0'||c>'9'){
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
const int MAXSIZE = 1e7, MAXN = 3e5 + 10;
int n, m;
struct node{
	int l, r, cnt;
}tree[MAXSIZE];
int endd;
int clone(int p){
	tree[++endd] = tree[p];
	return endd;
}
int root[MAXN];
void build(int p, int l, int r){
	if(l == r) return;
	ls = ++endd;
	rs = ++endd;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	return;
}
int add(int p, int l, int r, int x){
	p = clone(p);
	tree[p].cnt++;
	if(l == r) return p;
	if(x <= mid) ls = add(ls, l, mid, x);
	else rs = add(rs, mid + 1, r, x);
	return p;
}
int query(int p1, int p2, int l, int r, int k){
	if(l == r) return l;
	if(tree[tree[p2].l].cnt - tree[tree[p1].l].cnt >= k) return query(tree[p1].l, tree[p2].l, l, mid, k);
	else return query(tree[p1].r, tree[p2].r, mid + 1, r, k - (tree[tree[p2].l].cnt - tree[tree[p1].l].cnt));
}
int a[MAXN], b[MAXN];
int main(){
	n = read(), m = read();
	rep(i, 1, n) b[i] = a[i] = read();
	sort(b + 1, b + n + 1);
	build(0, 1, n);
	rep(i, 1, n){
		int pos = lower_bound(b + 1, b + n + 1, a[i]) - b;
		root[i] = add(root[i - 1], 1, n, pos);
	}
	while(m--){
		int x = read(), y = read(), k = read();
		int pos = query(root[x - 1], root[y], 1, n, k);
		printf("%d\n", b[pos]);
	}
	return 0;
}