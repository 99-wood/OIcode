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
const int MAXN = 2e5 + 10;

int n, m;
struct node{
	int l, r, fa, dep;
}tree[MAXN * 25];
int root[MAXN];
int endd;
int clone(int p){
	++endd;
	tree[endd] = tree[p];
	return endd;
}
void build(int p, int l, int r){
	if(l == r){
		tree[p].fa = l;
		tree[p].dep = 1;
		return;
	}
	ls = ++endd;
	rs = ++endd;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	return;
}
int modify(int p, int l, int r, int x, int f, int d){
	p = clone(p);
	if(l == r){
		tree[p].fa = f;
		tree[p].dep = d;
		return p;
	}
	if(x <= mid) ls = modify(ls, l, mid, x, f, d);
	else rs = modify(rs, mid + 1, r, x, f, d);
	return p;
}
int query1(int p, int l, int r, int x){
	if(l == r) return tree[p].fa;
	if(x <= mid) return query1(ls, l, mid, x);
	else return query1(rs, mid + 1, r, x);
}
int query2(int p, int l, int r, int x){
	if(l == r) return tree[p].dep;
	if(x <= mid) return query2(ls, l, mid, x);
	else return query2(rs, mid + 1, r, x);
}
int findfa(int v, int p){
	int fa = query1(root[v], 1, n, p);
	if(fa == p) return p;
	else return findfa(v, fa);
}
int main(){
	n = read(), m = read();
	build(0, 1, n);
	rep(i, 1, m){
		int op = read();
		switch(op){
			case 1:{
				root[i] = root[i - 1];
				int x = read(), y = read();
				int fx = findfa(i, x), fy = findfa(i, y);
				int dx = query2(root[i], 1, n, fx), dy = query2(root[i], 1, n, fy);
				if(dx > dy){
					swap(fx, fy);
					swap(dx, dy);
				}
				root[i] = modify(root[i], 1, n, fx, fy, dx);
				if(dx == dy) root[i] = modify(root[i], 1, n, fy, fy, dy + 1);
				break;
			}
			case 2:{
				int v = read();
				root[i] = root[v];
				break;
			}
			case 3:{
				root[i] = root[i - 1];
				int x = read(), y = read();
				int fx = findfa(i, x), fy = findfa(i, y);
				if(fx == fy) printf("1\n");
				else printf("0\n");
				break;
			}
		}
	}
	return 0;
}