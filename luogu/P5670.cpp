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
#include<bitset>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define tmp(a, b) (tmp[a] >> (n - (b)) & 1)
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
typedef bitset<1024> bit1024;
typedef bitset<512> bit512;
const int MAXN = 100010;
int n, m, q;
int a[MAXN];
int tag[MAXN << 2];
bit1024 tree[MAXN << 2];
void build(int p, int l, int r){
	if(l == r){
		tree[p][a[l]] = 1;
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	tree[p] = tree[ls] ^ tree[rs];
	return;
}
void pushdown(int p, int l, int r){
	tag[p] %= 1 << m;
	tree[ls] = ((tree[ls] << tag[p]) | (tree[ls] >> ((1 << m) - tag[p])));
	tree[rs] = ((tree[rs] << tag[p]) | (tree[rs] >> ((1 << m) - tag[p])));
	tag[ls] += tag[p];
	tag[rs] += tag[p];
	tag[p] = 0;
	return;
}
void modify(int p, int l, int r, int x, int y, int w){
	if(x <= l && r <= y){
		tag[p] += w;
		tag[p] %= 1 << m;
		tree[p] = ((tree[p] << w) | (tree[p] >> ((1 << m) - w)));
		return;
	}
	pushdown(p, l, r);
	if(x <= mid) modify(ls, l, mid, x, y, w);
	if(y > mid) modify(rs, mid + 1, r, x, y, w);
	tree[p] = tree[ls] ^ tree[rs];
	return;
}
bit1024 ask(int p, int l, int r, int x, int y){
	if(x <= l && r <= y){
		return tree[p];
	}
	pushdown(p, l, r);
	bit1024 res;
	res.reset();
	if(x <= mid) res ^= ask(ls, l, mid, x, y);
	if(y > mid) res ^= ask(rs, mid + 1, r, x, y);
	return res;
}

int tag_[MAXN << 2];
bit512 tree_[MAXN << 2];
void build_(int p, int l, int r){
	if(l == r){
		tree_[p][a[l]] = 1;
		return;
	}
	build_(ls, l, mid);
	build_(rs, mid + 1, r);
	tree_[p] = tree_[ls] ^ tree_[rs];
	return;
}
void pushdown_(int p, int l, int r){
	tag_[p] %= 1 << m;
	tree_[ls] = ((tree_[ls] << tag_[p]) | ((tree_[ls] << (512 - (1 << m))) >> ((1 << m) - tag_[p] + (512 - (1 << m)))));
	tree_[rs] = ((tree_[rs] << tag_[p]) | ((tree_[rs] << (512 - (1 << m))) >> ((1 << m) - tag_[p] + (512 - (1 << m)))));
	tag_[ls] += tag_[p];
	tag_[ls] %= 1 << m;
	tag_[rs] += tag_[p];
	tag_[rs] %= 1 << m;
	tag_[p] = 0;
	return;
}
void modify_(int p, int l, int r, int x, int y, int w){
	if(x <= l && r <= y){
		tag_[p] += w;
		tag_[p] %= 1 << m;
		tree_[p] = ((tree_[p] << w) | ((tree_[p] << (512 - (1 << m))) >> ((1 << m) - w + (512 - (1 << m)))));
		return;
	}
	pushdown_(p, l, r);
	if(x <= mid) modify_(ls, l, mid, x, y, w);
	if(y > mid) modify_(rs, mid + 1, r, x, y, w);
	tree_[p] = tree_[ls] ^ tree_[rs];
	return;
}
bit512 ask_(int p, int l, int r, int x, int y){
	if(x <= l && r <= y){
		return tree_[p];
	}
	pushdown_(p, l, r);
	bit512 res;
	res.reset();
	if(x <= mid) res ^= ask_(ls, l, mid, x, y);
	if(y > mid) res ^= ask_(rs, mid + 1, r, x, y);
	return res;
}

int main(){
	n = read(), m = read(), q = read();
	rep(i, 1, n){
		a[i] = read();
	}
	if(m == 10){
		build(1, 1, n);
		while(q--){
			int op = read();
			if(op == 1){
				int x = read(), y = read(), w = read();
				modify(1, 1, n, x, y, w % (1 << m));
			}
			else{
				int x = read(), y = read();
				bit1024 ans = ask(1, 1, n, x, y);
				int res = 0;
				frep(i, 0, 1 << m){
					res ^= (ans[i] & 1) ? i : 0;
				}
				printf("%d\n", res);
			}
		}
	}
	else{
		build_(1, 1, n);
		while(q--){
			int op = read();
			if(op == 1){
				int x = read(), y = read(), w = read();
				modify_(1, 1, n, x, y, w % (1 << m));
			}
			else{
				int x = read(), y = read();
				bit512 ans = ask_(1, 1, n, x, y);
				int res = 0;
				frep(i, 0, 1 << m){
					res ^= (ans[i] & 1) ? i : 0;
				}
				printf("%d\n", res);
			}
		}
	}
	return 0;
}