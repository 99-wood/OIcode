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
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 2e5;
int root[MAXN], dfn[MAXN], nxt[MAXN][26], fail[MAXN], fa[MAXN], siz[MAXN];
int dfn_[MAXN], dep[MAXN];
vector<int> tree[MAXN];
int end1, end2, end3, end4;
struct node{
	int id, x, y, ans;
}ask[MAXN];
bool cmp1(struct node a, struct node b){
	return dfn_[root[a.y]] < dfn_[root[b.y]];
}
bool cmp2(struct node a, struct node b){
	return a.id < b.id;
}
int c[MAXN];
void modify(int p, int w){
	while(p <= end3){
		c[p] += w;
		p += p & -p;
	}
	return;
}
int query(int p){
	int ans = 0;
	while(p){
		ans += c[p];
		p -= p & -p;
	}
	return ans;
}
void dfs(int p){
	dfn[p] = ++end3;
	siz[p] = 1;
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		dfs(x);
		siz[p] += siz[x];
	}
	return;
}
void dfs_(int p){
	dfn_[p] = ++end4;
	rep(i, 0, 25){
		if((!p && nxt[p][i]) || (nxt[p][i] && fa[nxt[p][i]] == p)){
			//判断需要详细
			int x = nxt[p][i];
			dep[x] = dep[p] + 1;
			dfs_(x);
		}
	}
	return;
}
void build(){
	queue<int> q;
	rep(i, 0, 25){
		if(nxt[0][i]){
			q.push(nxt[0][i]);
			tree[0].push_back(nxt[0][i]);
		};
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		rep(i, 0, 25){
			if(nxt[now][i]){
				fail[nxt[now][i]] = nxt[fail[now]][i];
				tree[fail[nxt[now][i]]].push_back(nxt[now][i]);
				q.push(nxt[now][i]);
			}
			else{
				nxt[now][i] = nxt[fail[now]][i];
			}
		}
	}
	dfs(0);
	dfs_(0);
	return;
}
void inil(){
	int c = getchar();
	int now = 0;
	while(c == 'B' || c == 'P' || (c >= 'a' && c <= 'z')){
		if(c == 'B'){
			now = fa[now];
		}
		else if(c == 'P'){
			root[++end1] = now;
		}
		else{
			if(nxt[now][c - 'a']){
				now = nxt[now][c - 'a'];
			}
			else{
				nxt[now][c - 'a'] = ++end2;
				fa[nxt[now][c - 'a']] = now;
				now = nxt[now][c - 'a'];
			}
		}
		c = getchar();
	}
	build();
	return;
}
int main(){
	inil();
	int n = read();
	rep(i, 1, n){
		ask[i].id = i;
		ask[i].x = read();
		ask[i].y = read();
	}
	sort(ask + 1, ask + 1 + n, cmp1);
	int last = 0;
	rep(i, 1, n){
		int x = ask[i].x, y = ask[i].y;
		if(y != last){
			int a = root[last], b = root[y];
			while(dep[a] > dep[b]){
				modify(dfn[a], -1);
				a = fa[a];
			}
			while(dep[b] > dep[a]){
				modify(dfn[b], 1);
				b = fa[b];
			}
			while(a != b){
				modify(dfn[a], -1);
				a = fa[a];
				modify(dfn[b], 1);
				b = fa[b];
			}
			last = y;
		}
		ask[i].ans = query(dfn[root[x]] + siz[root[x]] - 1) - query(dfn[root[x]] - 1);
	}
	sort(ask + 1, ask + 1 + n, cmp2);
	rep(i, 1, n){
		printf("%d\n", ask[i].ans);
	}
	return 0;
}