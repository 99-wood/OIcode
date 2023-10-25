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
#define ls tree[p].l
#define rs tree[p].r
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
const int MAXN = 2e5;

struct node{
	int l, r, w, dis, fa;
}tree[MAXN];
bool d[MAXN];
int n, q;
int findfa(int p){
	return tree[p].fa == p ? p : tree[p].fa = findfa(tree[p].fa);
}
void pushup(int p){
	if(ls) tree[ls].fa = p;
	if(rs) tree[rs].fa = p;
	if(tree[rs].dis > tree[ls].dis) swap(ls, rs);
	tree[p].dis = tree[rs].dis + 1;
	return;
}
int merge(int x, int y){
	if(!x || !y) return x ^ y;
	if(x > y) swap(x, y);
	if(tree[x].w > tree[y].w) swap(x, y);
	tree[x].r = merge(tree[x].r, y);
	pushup(x);
	return x;
}
int del(int p){
	if(ls) tree[ls].fa = ls;
	if(rs) tree[rs].fa = rs;
	return tree[p].fa = merge(ls, rs);
}
int main(){
	n = read(), q = read();
	tree[0].dis = -1;
	rep(i, 1, n) tree[i].fa = i;
	rep(i, 1, n) tree[i].w = read();
	while(q--){
		int op = read();
		if(op == 1){
			int x = read(), y = read();
			if(d[x] || d[y] || findfa(x) == findfa(y)) continue;
			merge(findfa(x), findfa(y));
		}
		else{
			int x = read();
			if(d[x]){
				printf("-1\n");
				continue;
			}
			int f = findfa(x);
			printf("%d\n", tree[f].w);
			del(f);
			d[f] = true;
		}
	}
	return 0;
}
