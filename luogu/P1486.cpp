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
const int MAXN = 1e6;
struct node{
	int rnd, val, tag, l, r;
	node(int val, int rnd, int tag, int l, int r) : val(val), rnd(rnd), tag(tag), l(l), r(r){}
	node() : rnd(), val(), tag(), l(), r(){}
}tree[MAXN];
int root, endd, siz[MAXN];
int newnode(int a){
	tree[++endd] = node(a, rand(), 0, 0, 0);
	siz[endd] = 1;
	return endd;
}
void upd(int p){
	if(!p) return;
	siz[p] = siz[ls] + siz[rs] + 1;
	return;
}
void pushdown(int p){
	if(tree[p].tag){
		tree[ls].tag += tree[p].tag;
		tree[rs].tag += tree[p].tag;
		tree[ls].val += tree[p].tag;
		tree[rs].val += tree[p].tag;
		tree[p].tag = 0;
	}
	return;
}
void split1(int p, int k, int &x, int &y){
	if(!p){
		x = y = 0;
		return;
	}
	pushdown(p);
	if(siz[ls] + 1 <= k){
		x = p;
		split1(rs, k - (siz[ls] + 1), rs, y);
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
		x = y = 0;
		return;
	}
	pushdown(p);
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
	pushdown(x);
	pushdown(y);
	if(tree[x].rnd < tree[y].rnd){
		tree[x].r = merge(tree[x].r, y);
		upd(x);
		return x;
	}
	else{
		tree[y].l = merge(x, tree[y].l);
		upd(y);
		return y;
	}
}
int find(int p){
	if(p == 0) return -1;
	if(rs) return find(rs);
	else return tree[p].val;
}
int main(){
	int n = read(), m = read();
	int cnt = 0;
	rep(i, 1, n){
		char op;
		scanf("\n%c", &op);
		int k = read();
		switch(op){
			case 'I':
				if(k < m) break;
				++cnt;
				newnode(k);
				int x, y;
				split2(root, k, x, y);
				root = merge(x, merge(newnode(k), y));
				break;
			case 'A':
				tree[root].val += k;
				tree[root].tag += k;
				break;
			case 'S':
				tree[root].val += -k;
				tree[root].tag += -k;
				int tmp;
				split2(root, m - 1, tmp, root);
				break;
			case 'F':{
				int x, y;
				split1(root, siz[root] - k + 1, x, y);
				printf("%d\n", find(x));
				root = merge(x, y);
				break;
			}
		}
	}
	printf("%d", cnt - siz[root]);
	return 0;
}