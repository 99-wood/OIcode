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
const int MAXN = 2e6;
int n;
int nxt[MAXN][2], fail[MAXN];
bool tail[MAXN], vis[MAXN];
char s[MAXN];
bool ans;
vector<int> tree[MAXN];
int end1, end2;
void dfs(int p, bool v){
	v = (v || tail[p]);
	vis[p] = v;
	frep(i, 0, tree[p].size()){
		int x = tree[p][i];
		dfs(x, v);
	}
	return;
}
void dfs2(int p){
	if(ans[p]) return;
}
void build(){
	queue<int> q;
	rep(i, 0, 1){
		if(nxt[0][i]){
			q.push(nxt[0][i]);
			tree[0].push_back(nxt[0][i]);
		};
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		rep(i, 0, 1){
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
	return;
}
void solve(){
	rep(i, 1, n){
		int now = 0;
		scanf("%s", s);
		int len = strlen(s);
		frep(j, 0, len){
			char c = s[j];
			if(nxt[now][c - '0']){
				now = nxt[now][c - '0'];
			}
			else{
				nxt[now][c - '0'] = ++end2;
				now = nxt[now][c - '0'];
			}
		}
		tail[now] = true;
	}
	build();
	dfs(0, false);
	dfs2(0);
	return;
}
int main(){
	n = read();
	solve();

	return 0;
}