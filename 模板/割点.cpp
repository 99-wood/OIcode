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
vector<int> ans;
void tarjan(int p, int fa){
	dfn[p] = low[p] = ++endd;
	int cnt = 0;
	bool flag = false;
	for(auto x : nxt[p]){
		if(x == fa) continue;
		if(dfn[x]) low[p] = min(low[p], dfn[x]);
		else{
			++cnt;
			tarjan(x, p);
			if(low[x] >= dfn[p]) flag = true;
			low[p] = min(low[p], low[x]);
		}
	}
	if(flag){
		if((dfn[p] == 1 && cnt > 1) || dfn[p] > 1) ans.push_back(p);
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
	for(auto x : ans) printf("%d\n", x - 1);
	return 0;
}

