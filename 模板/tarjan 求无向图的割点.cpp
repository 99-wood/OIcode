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
const int MAXN = 2e5 + 10;

vector<int> nxt[MAXN];
vector<int> ans;
int dfn[MAXN], low[MAXN], endd;
int n, m;
void tarjan(int p, int fa){
	dfn[p] = low[p] = ++endd;
	bool flag = false;
	int cnt = 0;
	frep(i, 0, nxt[p].size()){
		int x = nxt[p][i];
		if(x == fa) continue;
		if(!dfn[x]){
			++cnt;
			tarjan(x, p);
			low[p] = min(low[p], low[x]);
			if(low[x] >= dfn[p]) flag = true;
		}
		else{
			low[p] = min(low[p], dfn[x]);
		}
	}
	if(fa == 0 && cnt > 1) ans.push_back(p);
	else if(fa != 0 && flag) ans.push_back(p);
}
int main(){
	n = read(), m = read();
	rep(i, 1, m){
		int x = read(), y = read();
		nxt[x].push_back(y);
		nxt[y].push_back(x);
	}
	rep(i, 1, n){
		if(!dfn[i]) tarjan(i, 0);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	frep(i, 0, ans.size()){
		printf("%d ", ans[i]);
	}
	return 0;
}
