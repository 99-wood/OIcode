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
const int MAXN = 4e5 + 10;
ll tree[MAXN << 2];
void modify(int p, int l, int r, int x, ll w){
	if(l == r){
		tree[p] = w;
		return;
	}
	if(x <= mid) modify(ls, l, mid, x, w);
	else modify(rs, mid + 1, r, x, w);
	tree[p] = max(tree[ls], tree[rs]);
	return;
}
ll query(int p, int l, int r, int x, int y){
	if(x > r || y < l) return 0;
	if(x <= l && r <= y) return tree[p];
	return max(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
}
struct node{
	int h;
	ll w;
}a[MAXN];
ll f[MAXN];
int main(){
	int n = read();
	rep(i, 1, n) a[i].h = read();
	rep(i, 1, n) a[i].w = read();
	rep(i, 1, n){
		ll res = query(1, 1, n, 1, a[i].h - 1);
		f[i] = res + a[i].w;
		modify(1, 1, n, a[i].h, f[i]);
	}
	ll ans = 0;
	rep(i, 1, n) ans = max(ans, f[i]);
	printf("%lld", ans);
	return 0;
}
