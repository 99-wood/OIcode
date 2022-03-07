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
	while(c>='0'&&c<='9') {
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 4e6;
int m,n;

struct node{
	int w,l,r,sum;
};
struct node tree[MAXN];
int root[MAXN];
int endd;
struct ty{
	int ty,t,k;
}sub[MAXN];
bool cmp1(const struct ty a, const struct ty b){
	return a.k < b.k;
}
bool cmp2(const struct ty a, const struct ty b){
	return a.t < b.t;
}
void buildtree(int p, int l, int r){
	if(l == r) return;
	int m = (l + r) >> 1;
	tree[p].l = ++endd;
	tree[p].r = ++endd;
	buildtree(tree[p].l, l, m);
	buildtree(tree[p].r, m + 1, r);
	return;
}
int clone(int p){
	tree[++endd] = tree[p];
	return endd;
}
int add(int p, int l, int r, int pp, int w){
	p = clone(p);
	tree[p].w += w;
	if(l == r) tree[p].sum += pp * w;
	int m = (l + r) >> 1;
	if(pp <= m)
		tree[p].l = add(tree[p].l, l, m, pp, w);
	else
		tree[p].r = add(tree[p].r, m + 1, r, pp, w);
	tree[p].sum = tree[tree[p].l].sum + tree[tree[p].r].sum;
	return p;
}
int main(){
	n = read(), m = read();
	frep(i,0,n){
		int pp = i << 1;
		sub[pp].ty = 1;
		sub[pp + 1].ty = 0;
		sub[pp].t = read();
		sub[pp + 1].t = read();
		sub[pp].k = sub[pp + 1].k = read();
	}
	sort(sub, sub + (n << 1),cmp1);
	int last = sub[0].k;
	sub[0].k = 1;
	frep(i,1,n << 1){
		if(sub[i].k == last){
			last = sub[i].k;
			sub[i].k = sub[i - 1].k;
		}
		else{
			last = sub[i].k;
			sub[i].k = sub[i - 1].k + 1;
		}
	}
	buildtree(0,1,n);
	sort(sub, sub + (n << 1),cmp2);
	int now = 0;
	rep(i,1,n){
		root[i] = root[i - 1];
		while(sub[now].t == i){
			if(sub[now].ty){
				root[i] = add(root[i],1,n,sub[now].k,1)
			}
			else{
				
			}
			
			++now;
		}
	}
}
