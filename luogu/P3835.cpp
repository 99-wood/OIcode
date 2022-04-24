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
const int MAXN = 5e5 + 10;
int root[MAXN], endd;
struct node{
	int val, rnd, siz, l, r;
}tree[MAXN * 50];
int newnode(int w){
	++endd;
	tree[endd].val = w;
	tree[endd].rnd = rand();
	tree[endd].siz = 1;
	tree[endd].l = 0;
	tree[endd].r = 0;
	return endd;
}
int clone(int p){
	tree[++endd] = tree[p];
	return endd;
}
void upd(int p){
	if(!p) return;
	tree[p].siz = tree[ls].siz + tree[rs].siz + 1;
	return;
}
void split1(int p, int k, int &x, int &y){
	if(!p){
		x = 0;
		y = 0;
		return;
	}
	p = clone(p);
	if(tree[ls].siz + 1 <= k){
		x = p;
		split1(rs, k - (tree[ls].siz + 1), rs, y);
	}
	else{
		y = p;
		split1(ls, k, x, ls);
	}
	upd(p);
	return;
}
void split2(int p, int w, int &x, int &y){
	if(!p){
		x = 0;
		y = 0;
		return;
	}
	p = clone(p);
	if(tree[p].val <= w){
		x = p;
		split2(rs, w, rs, y);
	}
	else{
		y = p;
		split2(ls, w, x, ls);
	}
	upd(p);
	return;
}
int merge(int x, int y){
	if(!x || !y) return x + y;
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
int add(int p, int w){
	int a = newnode(w);
	int x, y;
	split2(p, w, x, y);
	return merge(x, merge(a, y));
}
int del(int p, int w){
	int x, y, z;
	split2(p, w - 1, x, y);
	split2(y, w, y, z);
	return merge(merge(x, merge(tree[y].l,tree[y].r)), z);
}
int rnk(int p, int w){
	int x, y;
	int tag = endd;
	split2(p, w - 1, x, y);
	int re = tree[x].siz + 1;
	endd = tag;
	return re;
}
bool er;
int mx(int p){
	if(!p){
		er = true;
		return -1;	
	}
	while(rs) p = rs;
	return p;
}
int mn(int p){
	if(!p){
		er = true;
		return -1;	
	}
	while(ls) p = ls;
	return p;
}
int kth(int p, int k){
	int x, y;
	int tag = endd;
	split1(p, k, x, y);
	int re = tree[mx(x)].val;
	endd = tag;
	return re;
}
int pre(int p, int w){
	int x, y;
	int tag = endd;
	split2(p, w - 1, x, y);
	er = false;
	int re = mx(x);
	endd = tag;
	if(er) return (1 << 31) + 1;
	else return tree[re].val;
}
int nxt(int p, int w){
	int x, y;
	int tag = endd;
	split2(p, w, x, y);
	er = false;
	int re = mn(y);
	endd = tag;
	if(er) return ~(1 << 31);
	else return tree[re].val;
}
int main(){
	freopen("P3835_19.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int q = read();
	rep(i, 1, q){
		int v = read(), op = read(), x = read();
		if(op == 1){
			root[i] = add(root[v], x);
		}
		else if(op == 2){
			root[i] = del(root[v], x);
		}
		else if(op == 3){
			root[i] = root[v];
			printf("%d\n", rnk(root[v], x));
		}
		else if(op == 4){
			root[i] = root[v];
			printf("%d\n", kth(root[v], x));
		}
		else if(op == 5){
			root[i] = root[v];
			printf("%d\n", pre(root[v], x));
		}
		else{
			root[i] = root[v];
			printf("%d\n", nxt(root[v], x));
		}
	}
	return 0;
}