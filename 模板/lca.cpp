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
const int N = 20;
vector<int> nxt[MAXN];
int dep[MAXN];
int fa[MAXN][30];
int n;
void dfs(int p, int f){
	fa[p][0] = f;
	dep[p] = dep[f] + 1;
	rep(i, 1, N) fa[p][i] = fa[fa[p][i - 1]][i - 1];
	for(auto x : nxt[p]) dfs(x, p);
}
int query(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	drep(i, N, 0){
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if(x == y) return x;
	drep(i, N, 0){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main(){
	n = read();
	rep(i, 1, n){
		int m = read();
		while(m--){
			int x = read() + 1;
			nxt[i].push_back(x);
		}
	}
	dfs(1, 0);
	int q = read();
	while(q--){
		int x = read() + 1, y = read() + 1;
		printf("%d\n", query(x, y) - 1);
	}
	return 0;
}
