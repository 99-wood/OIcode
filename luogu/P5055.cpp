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
const int MAXN = 2e5 + 10;
struct node{
	int val, rnd, tag, siz, l, r;
	ll sum;
}tree[MAXN * 100];
int root[MAXN];
int endd;
int newnode(int w){
	++endd;
	tree[endd].val = w;
	tree[endd].sum = w;
	tree[endd].rnd = rand();
	tree[endd].tag = 0;
	tree[endd].siz = 1;
	tree[endd].l = 0;
	tree[endd].r = 0;
	return endd;
}
int clone(int p){
	if(!p) return 0;
	tree[++endd] = tree[p];
	return endd;
}
void pushdown(int p){
	if(tree[p].tag){
		tree[ls].tag ^= 1;
		tree[rs].tag ^= 1;
		tree[p].tag = 0;
	}
	return;
}
void upd(int p){
	if(!p) return;
	tree[p].siz = tree[ls].siz + tree[rs].siz + 1;
	tree[p].sum = tree[ls].sum + tree[rs].sum + tree[p].val;
	return;
}
void split(int p, int k, int &x, int &y){
	if(!p){
		x = y = 0;
		return;
	}
	p = clone(p);
	if(tree[p].tag){
		ls = clone(ls);
		rs = clone(rs);
		swap(ls, rs);
		pushdown(p);
	}
	if(tree[ls].siz + 1 <= k){
		x = p;
		split(rs, k - (tree[ls].siz + 1), rs, y);
	}
	else{
		y = p;
		split(ls, k, x, ls);
	}
	upd(p);
}
int merge(int x, int y){
	if(!x || !y) return x ^ y;
	if(tree[x].tag){
		tree[x].l = clone(tree[x].l);
		tree[x].r = clone(tree[x].r);
		swap(tree[x].l, tree[x].r);
		pushdown(x);
	}
	if(tree[y].tag){
		tree[y].l = clone(tree[y].l);
		tree[y].r = clone(tree[y].r);
		swap(tree[y].l, tree[y].r);
		pushdown(y);
	}
	if(tree[x].rnd < tree[y].rnd){
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
int add(int p, int k, int w){
	int a = newnode(w);
	int x, y;
	split(p, k, x, y);
	return merge(merge(x, a), y);
}
int del(int p, int k){
	int x, y, z;
	split(p, k - 1, x, y);
	split(y, 1, y, z);
	return merge(x, z);
}
int modify(int p, int l, int r){
	int x, y, z;
	split(p, l - 1, x, y);
	split(y, r - l + 1, y, z);
	tree[y].tag ^= 1;
	return merge(merge(x, y), z);
}
ll query(int p, int l, int r){
	int x, y, z;
	int tmp = endd;
	split(p, l - 1, x, y);
	split(y, r - l + 1, y, z);
	ll ans = tree[y].sum;
	endd = tmp;
	return ans;
}
int main(){
	int n = read();
	ll last = 0;
	rep(i, 1, n){
		int v = read(), op = read();
		switch(op){
			case 1:{
				int p = read(), x = read();
				p ^= last;
				x ^= last;
				root[i] = add(root[v], p, x);
				break;
			}
			case 2:{
				int p = read();
				p ^= last;
				root[i] = del(root[v], p);
				break;
			}
			case 3:{
				int x = read(), y = read();
				x ^= last;
				y ^= last;
				root[i] = modify(root[v], x, y);
				break;
			}
			case 4:{
				root[i] = root[v];
				int x = read(), y = read();
				x ^= last;
				y ^= last;
				last = query(root[i], x, y);
				printf("%lld\n", last);
				break;
			}
		}
	}
	return 0;
}