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
const int MAXN = 1e5 + 10;
#define ls tree[p].l
#define rs tree[p].r
struct node{
	int w, siz, rnd, l, r;
}tree[MAXN * 200];
int endd;
int newnode(int a){
	++endd;
	tree[endd].w = a;
	tree[endd].rnd = rand();
	tree[endd].siz = 1;
	return endd;
}
void upd(int p){
	if(!p) return;
	tree[p].siz = tree[ls].siz + tree[rs].siz + 1;
	return;
}
int clone(int p){
	++endd;
	tree[endd] = tree[p];
	return endd;
}
void split1(int p, int k, int &x, int &y){
	x = y = 0;
	if(!p) return;
	p = clone(p);
	if(tree[p].w < k){
		x = p;
		split1(rs, k, rs, y);
	}
	else{
		y = p;
		split1(ls, k, x, ls);
	}
	upd(p);
	return;
}
void split2(int p, int k, int &x, int &y){
	x = y = 0;
	if(!p) return;
	p = clone(p);
	if(tree[ls].siz + 1 == tree[p].w - k + 1){
		x = p;
		split2(rs, tree[p].w + 1, rs, y);
	}
	else{
		y = p;
		split2(ls, k, x, ls);
	}
	upd(p);
	return;
}
int merge(int x, int y){
	if(!x || !y) return x ^ y;
	if(tree[x].siz < tree[y].siz){
		x = clone(x);
		tree[x].r = merge(tree[x].r, y);
		upd(x);
		return x;
	}
	else{
		y = clone(y);
		tree[y].l = merge(x, tree[y].l);
		upd(y);
		return y;
	}
}
int add(int root, int a){
	int x, y, z;
	split1(root, a, x, y);
	split2(y, a, y, z);
	int p = newnode(a + tree[y].siz);
	return merge(merge(x, p), z);
}
int a[MAXN], B;
struct T{
	int id, l, r;
}ask[MAXN * 10];
int ans[MAXN * 10];
bool cmp(struct T a, struct T b){
	return a.l / B == b.l / B ? a.r < b.r : a.l < b.l;
}
int main(){
//	freopen("two.in", "r", stdin);
//	freopen("two.out", "w", stdout);
	int n = read(), m = read();
	B = n / sqrt(m);
	rep(i, 1, n) a[i] = read();
	rep(i, 1, m){
		ask[i].id = i;
		ask[i].l = read();
		ask[i].r = read();
	}
	sort(ask + 1, ask + 1 + m, cmp);
	int root = 0, l = 1, r = 0, b = -1, now = 1;
	while(now <= m){
		if(ask[now].l / B == ask[now].r / B){
			++now;
			continue;
		}
		if(ask[now].l / B != b){
			b = ask[now].l / B;
			l = min(((b + 1) * B), n + 1);
			r = l - 1;
			root = 0;
		}
		l = min(((b + 1) * B), n + 1);
		while(r < ask[now].r) root = add(root, a[++r]);
		int tmp = root;
		while(l > ask[now].l) tmp = add(tmp, a[--l]);
		ans[ask[now].id] = tree[tmp].siz;
		++now;
	}
	now = 1;
	while(now <= m){
		if(ask[now].l / B == ask[now].r / B){
			root = 0;
			rep(j, ask[now].l, ask[now].r){
				root = add(root, a[j]);
			}
			ans[ask[now].id] = tree[root].siz;
		}
		++now;
	}
	rep(i, 1, m) printf("%d\n", ans[i]);
	return 0;
}