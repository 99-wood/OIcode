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
#include<random>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
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

int n, m, k;
set<int> pos[MAXN];
int tree[MAXN << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
void modify(int p, int l, int r, int x, int w){
	if(x == -1 || w == -1) return;
	if(l == r){
		tree[p] = w;
		return;
	}
	if(x <= mid) modify(ls, l, mid, x, w);
	else modify(rs, mid + 1, r, x, w);
	tree[p] = min(tree[ls], tree[rs]);
	return;
}
int query(int p, int l, int r, int x, int y){
	if(x <= l && r <= y) return tree[p];
	if(y <= mid) return query(ls, l, mid, x, y);
	else if(x > mid) return query(rs, mid + 1, r, x, y);
	else return min(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
}
int a[MAXN];
int bef(int w, int p){
	if(!pos[w].size()) return -1;
	auto pp = pos[w].lower_bound(p);
	if(pp == pos[w].begin()) return -1;
	--pp;
	return *pp;
}
int nxt(int w, int p){
	if(!pos[w].size()) return -1;
	auto pp = pos[w].lower_bound(p);
	if(pp == pos[w].end()) return -1;
	return *pp;
}
void del(int w, int p){
	pos[w].erase(pos[w].find(p));
	return;
}
void add(int w, int p){
	pos[w].insert(p);
	return;
}
void upd(int w, int p){
	if(p == -1) return;
	modify(1, 1, n, p, 0x3f3f3f3f);
	int nx = nxt(k - w, p);
	if(nx != -1){
		modify(1, 1, n, bef(w, nx), nx);
	}
	return;
}
int main(){
	memset(tree, 0x3f, sizeof(tree));
	n = read(), m = read(), k = read();
	rep(i, 1, n){
		a[i] = read();
		pos[a[i]].insert(i);
	}
	drep(i, n, 1){
		int p = bef(k - a[i], i);
		if(p != -1) modify(1, 1, n, p, i);
	}
	int cnt = 0;
	while(m--){
		int op = read();
		if(op == 1){
			int x = read(), w = read();
			del(a[x], x);
			add(w, x);
			upd(w, x);
			upd(a[x], bef(a[x], x));
			upd(k - a[x], bef(k - a[x], x));
			upd(k - w, bef(k - w, x));
			a[x] = w;
		}
		else{
			int x = read() ^ cnt, y = read() ^ cnt;
			if(query(1, 1, n, x, y) <= y){
				++cnt;
				printf("Yes\n");
			}
			else printf("No\n");
		}
	}
	return 0;
}