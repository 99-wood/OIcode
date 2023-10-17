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
#define ls (p << 1)
#define rs (p << 1 | 1)
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
const int MAXN = 1e5 + 10;
int to[30][30], fail[MAXN];
char str[30];
int len;
struct node{
	queue<int> q;
	int now, cnt;
}tree[MAXN << 2];
void build(int p, int l, int r){
	tree[p].cnt = 0;
	tree[p].now = -1;
	if(l == r) return;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	return;
}
void pushdown(int p, int l, int r){
	if(tree[p].now != -1){
		tree[ls].now = tree[rs].now = tree[p].now;
		while(!tree[p].q.empty()){
			if(tree[ls].q.size() >= len) tree[ls].q.pop();
			if(tree[rs].q.size() >= len) tree[rs].q.pop();
			int x = tree[p].q.front();
			tree[p].q.pop();
			tree[ls].q.push(x);
			tree[rs].q.push(x);
		}
	}
	else{
		while(!tree[p].q.empty()){
			if(tree[ls].q.size() >= len) tree[ls].q.pop();
			if(tree[rs].q.size() >= len) tree[rs].q.pop();
			int x = tree[p].q.front();
			tree[p].q.pop();
			tree[ls].q.push(x);
			if(tree[ls].now != -1) tree[ls].now = to[tree[ls].now][x];
			tree[rs].q.push(x);
			if(tree[rs].now != -1) tree[rs].now = to[tree[rs].now][x];
		}
		if(tree[ls].q.size() >= len && tree[ls].now == -1){
			tree[ls].now = 0;
			rep(i, 1, len){
				int x = tree[ls].q.front();
				tree[ls].q.pop();
				tree[ls].q.push(x);
				tree[ls].now = to[tree[ls].now][x];
			}
		}
		if(tree[rs].q.size() >= len && tree[rs].now == -1){
			tree[rs].now = 0;
			rep(i, 1, len){
				int x = tree[rs].q.front();
				tree[rs].q.pop();
				tree[rs].q.push(x);
				tree[rs].now = to[tree[rs].now][x];
			}
		}
	}
	if(tree[ls].now == len) tree[ls].cnt = (mid - l + 1);
	else if(tree[ls].now != -1) tree[ls].cnt = 0;
	else tree[ls].cnt = -1;
	if(tree[rs].now == len) tree[rs].cnt = (r - mid);
	else if(tree[rs].now != -1) tree[rs].cnt = 0;
	else tree[rs].cnt = -1;
	return;
}
void pushup(int p, int l, int r){
	if(tree[ls].now == tree[rs].now) tree[p].now = tree[ls].now;
	else tree[p].now = -1;
	tree[p].cnt = (tree[ls].cnt < 0 || tree[rs].cnt < 0) ? -1 :tree[ls].cnt + tree[rs].cnt;
	return;
}
void add(int p, int l, int r, int x, int y, queue<int> s){
	if(x <= l && r <= y){
		if(tree[p].now != -1){
			while(!s.empty()){
				if(tree[p].q.size() >= len) tree[p].q.pop();
				int x = s.front();
				s.pop();
				tree[p].q.push(x);
				tree[p].now = to[tree[p].now][x];
			}
		}
		else{
			while(!s.empty()){
				if(tree[p].q.size() >= len) tree[p].q.pop();
				int x = s.front();
				s.pop();
				tree[p].q.push(x);
			}
			if(tree[p].q.size() >= len){
				tree[p].now = 0;
				rep(i, 1, len){
					int x = tree[p].q.front();
					tree[p].q.pop();
					tree[p].q.push(x);
					tree[p].now = to[tree[p].now][x];
				}
			}
		}
		if(tree[p].now == len) tree[p].cnt = (r - l + 1);
		else if(tree[p].now != -1) tree[p].cnt = 0;
		else tree[p].cnt = -1;
		return;
	}
	if(y < l || x > r) return;
	pushdown(p, l, r);
	add(ls, l, mid, x, y, s);
	add(rs, mid + 1, r, x, y, s);
	pushup(p, l, r);
	return;
}
int query(int p, int l, int r, int x, int y){
	if(x <= l && r <= y && tree[p].cnt >= 0) return tree[p].cnt;
	if(y < l || x > r) return 0;
	pushdown(p, l, r);
	int res = query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
	pushup(p, l, r);
	return res;
}
int main(){
	scanf("%s", str + 1);
	len = strlen(str + 1);
	fail[0] = -1;
	rep(i, 1, len){
		for(int j = fail[i - 1]; j != -1; j = fail[j]){
			if(str[j + 1] == str[i]){
				fail[i] = j + 1;
				break;
			}
		}
	}
	rep(i, 1, len){
		rep(c, 'a', 'z'){
			if(c == str[i]){
				to[i - 1][c - 'a'] = i;
			}
			else{
				to[i - 1][c - 'a'] = to[fail[i - 1]][c - 'a'];
			}
		}
	}
	rep(c, 'a', 'z'){
		to[len][c - 'a'] = to[fail[len]][c - 'a'];
	}
	int n = read(), q = read();
	while(q--){
		int op = read();
		if(op == 1){
			int x = read(), y = read();
			char str[30];
			queue<int> q; 
			scanf("%s", str);
			int l = strlen(str);
			frep(i, 0, l){
				q.push(str[i] - 'a');
			}
			add(1, 1, n, x, y, q);
		}
		else{
			int x = read(), y = read();
			int ans = query(1, 1, n, x, y);
			printf("%d\n", ans);
		}
	}
	return 0;
}
