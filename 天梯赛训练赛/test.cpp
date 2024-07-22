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
#include<list>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
//#define mid ((l + r) >> 1)
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
const int MAXN = 200010;
ll a[MAXN << 2];
ll b[MAXN << 2];
ll c[MAXN];
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
void pushdown(int p, int l, int r){
	b[ls] += b[p];
	a[ls] -= b[p];
	b[rs] += b[p];
	a[rs] -= b[p];
	b[p] = 0;
	return;
}
void modify(int p, int l, int r, int x, int y, ll w){
	if(x <= l && r <= y){
		a[p] -= w;
		b[p] += w;
		return;
	}
	if(y < l || x > r) return;
	pushdown(p, l, r);
	modify(ls, l, mid, x, y, w);
	modify(rs, mid + 1, r, x, y, w);
	a[p] = min(a[ls], a[rs]);
	return;
}
void build(int p, int l, int r){
	if(l == r){
		a[p] = c[l];
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	a[p] = min(a[ls], a[rs]);
	return;
}
ll query(int p, int l, int r, int x, int y){
	if(x <= l && r <= y) return a[p];
	if(y < l || x > r) return 1e17;
	pushdown(p, l, r);
	return min(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
}
struct node{
	int l, r;
}q[MAXN];
bool cmp(const struct node & a, const struct node & b){
	return a.r == b.r ? a.l > b.l : a.r < b.r;
}
int main(){
	int n = read(), m = read();
	rep(i, 1, n - 1){
		c[i] = read();
	}
	build(1, 1, n - 1);
	rep(i, 1, m){
		q[i].l = read() + 1;
		q[i].r = read() + 1;
		if(q[i].l > q[i].r) swap(q[i].l, q[i].r);
	}
	sort(q + 1, q + m + 1, cmp);
	ll ans = 0;
	int last = 1;
	rep(i, 1, n - 1){
		while(q[last].r - 1 < i) ++last;
		if(q[last].r - 1 != i) continue;
		ll k = query(1, 1, n - 1, q[last].l, q[last].r - 1);
		ans += k;
		modify(1, 1, n, q[last].l, q[last].r - 1, k);
	}
	printf("%lld", ans);
	return 0;
} 
