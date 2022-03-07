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
int num[MAXN];
struct DS{
	int a[MAXN << 2][2];
	int tag[MAXN << 2];
	void build(int p, int l, int r, int k){
		if(l == r){
			a[p][num[l] >> k & 1] = 1;
			return;
		}
		build(ls, l, mid, k);
		build(rs, mid + 1, r, k);
		a[p][0] = a[ls][0] + a[rs][0];
		a[p][1] = a[ls][1] + a[rs][1];
		return;
	}
	void pushdown(int p){
		if(tag[p]){
			tag[ls] ^= tag[p];
			tag[rs] ^= tag[p];
			tag[p] = 0;
			swap(a[ls][0], a[ls][1]);
			swap(a[rs][0], a[rs][1]);
		}
		return;
	}
	void modify(int p, int l, int r, int x, int y){
		if(x <= l && r <= y){
			swap(a[p][0], a[p][1]);
			tag[p] ^= 1;
			return;
		}
		if(y < l || r < x) return;
		pushdown(p);
		modify(ls, l, mid, x, y);
		modify(rs, mid + 1, r, x, y);
		a[p][0] = a[ls][0] + a[rs][0];
		a[p][1] = a[ls][1] + a[rs][1];
		return;
	}
	int ask(int p, int l, int r, int x, int y){
		if(x <= l && r <= y){
			return a[p][1];
		}
		if(y < l || r < x) return 0;
		pushdown(p);
		return ask(ls, l, mid, x, y) + ask(rs, mid + 1, r, x, y);
	}
}tree[30];
int main(){
	int n = read();
	rep(i, 1, n) num[i] = read();
	int B = mylog(1000000) + 1;
	rep(k, 0, B){
		tree[k].build(1, 1, n, k);
	}
	int m = read();
	rep(i, 1, m){
		int op = read();
		if(op == 1){
			ll ans = 0;
			int x = read(), y = read();
			rep(k, 0, B){
				ans += (ll)tree[k].ask(1, 1, n, x, y) << k;
			}
			printf("%lld\n", ans);
		}
		else{
			int x = read(), y = read(), a = read();
			rep(k, 0, B){
				if(a >> k & 1) tree[k].modify(1, 1, n, x, y);
			}
		}
	}
	return 0;
}