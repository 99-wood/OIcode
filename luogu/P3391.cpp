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
#define ls son[p][0]
#define rs son[p][1]
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
const int MAXN = 100010;
int siz[MAXN], rnd[MAXN], val[MAXN], son[MAXN][2], tag[MAXN], endd, root;
void upd(int p){
	if(!p) return;
	siz[p] = siz[son[p][0]] + siz[son[p][1]] + 1;
	return;
}
void pushdown(int p){
	if(!p) return;
	tag[ls] ^= tag[p];
	tag[rs] ^= tag[p];
	tag[p] = 0;
	return;
}
void split(int p, int k, int &x, int &y){
	if(!p){
		x = 0;
		y = 0;
		return;
	}
	if(tag[p]){
		pushdown(p);
		swap(ls, rs);
	}
	if(siz[ls] + 1 <= k){
		x = p;
		split(rs, k - siz[ls] - 1, son[x][1], y);
	}
	else{
		y = p;
		split(ls, k, x, son[y][0]);
	}
	upd(p);
	return;
}
int merge(int x, int y){
	if(!x || !y) return x + y;
	if(tag[x]){
		pushdown(x);
		swap(son[x][0], son[x][1]);;
	}
	if(tag[y]){
		pushdown(y);
		swap(son[y][0], son[y][1]);;
	}
	if(rnd[x] <= rnd[y]){
		son[x][1] = merge(son[x][1], y);
		upd(x);
		return x;
	}
	else{
		son[y][0] = merge(x, son[y][0]);
		upd(y);
		return y;
	}
}
void add(int w){
	++endd;
	siz[endd] = 1;
	rnd[endd] = rand();
	val[endd] = w;
	root = merge(root, endd);
}
void modify(int x, int y){
	int a = 0, b = 0, c = 0;
	split(root, x - 1, a, b);
	split(b, y - x + 1, b, c);
	tag[b] ^= 1;
	root = merge(a, merge(b, c));
}
void print(int p){
	if(!p) return;
	if(tag[p]){
		pushdown(p);
		swap(ls, rs);
	}
	print(ls);
	printf("%d ", val[p]);
	print(rs);
	return;
}
int main(){
	int n = read();
	int q = read();
	rep(i, 1, n){
		add(i);
	}
	while(q--){
		int x = read(), y = read();
		modify(x, y);
	}
	print(root);
	return 0;
}