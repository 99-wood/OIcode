#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define drep(i, a, b) for(int i = a; i >= (b); --i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
	char c = 0;
	int res = 0;
	bool b = 0;
	while(c < '0' || c > '9'){
		if(c == '-') b = true;
		c = getchar();
	}
	while(c >= '0' && c <='9'){
		res = (res << 3) + (res << 1) + (c - '0');
		c = getchar();
	}
	return b ? -res : res;
}
const int MAXN = 1e5 + 10;
vector<int> nxt[MAXN];
int n, m;
int dfn[MAXN], low[MAXN], endd;
struct edge{
	int u, v;
	edge(){
	}
	edge(int u, int v) : u(min(u, v)), v(max(u, v)){
	}
	bool operator < (edge b){
		return u == b.u ? v < b.v : u < b.u;
	}
};
vector<struct edge> ans;
void tarjan(int p, int fa){
	dfn[p] = low[p] = ++endd;
	bool flag = false;
	for(auto x : nxt[p]){
		if(x == fa) continue;
		if(dfn[x]) low[p] = min(low[p], dfn[x]);
		else{
			tarjan(x, p);
			if(low[x] > dfn[p]) ans.push_back(edge(p, x));
			low[p] = min(low[p], low[x]);
		}
	}
	return;
}
int main(){
	n = read(), m = read();
	rep(i, 1, m){
		int u = read() + 1, v = read() + 1;
		nxt[u].push_back(v);
		nxt[v].push_back(u);
	}
	tarjan(1, 0);
	sort(ans.begin(), ans.end());
	for(auto x : ans) printf("%d %d\n", x.u - 1, x.v - 1);
	return 0;
}

