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
const int MAXN = 110;
int n, m, root; 
struct edge{
	int u, v, w;
	edge(){}
	edge(int u, int v, int w) : u(u), v(v), w(w){}
};
vector<struct edge> e;
int in[MAXN], fa[MAXN];
int scc[MAXN];
int co[MAXN];
int solve(){
	int ans = 0;
	while(true){
		memset(in, 0x3f, sizeof(in));
		memset(fa, 0, sizeof(fa));
		memset(scc, 0, sizeof(scc));
		memset(co, 0, sizeof(co));
		for(auto x : e){
			if(x.v == root) continue;
			if(x.u != x.v && x.w < in[x.v]){
				in[x.v] = x.w;
				fa[x.v] = x.u;
			}
		}
		rep(i, 1, n){
			if(i == root) continue;
			if(!fa[i]) return -1;
		}
		rep(i, 1, n){
			if(i == root) continue;
			ans += in[i];
		}
		int cnt = 0;
		rep(i, 1, n){
			if(i == root){
				scc[i] = ++cnt;
				continue;
			}
			if(!scc[i]){
				int x = i;
				for(; x != root && co[x] != i && !scc[x]; x = fa[x]) co[x] = i;
				if(x != root && !scc[x]){
					++cnt;
					for(; !scc[x]; x = fa[x]) scc[x] = cnt;
				}
				if(!scc[i]) scc[i] = ++cnt;
			}
		}
		if(cnt == n) return ans;
		frep(i, 0, e.size()){
			e[i].w = e[i].w - in[e[i].v];
			e[i].v = scc[e[i].v];
			e[i].u = scc[e[i].u];
		}
		n = cnt;
		root = scc[root];
	}
}
int main(){
	n = read(), m = read(), root = read();
	rep(i, 1, m){
		int u = read(), v = read(), w = read();
		if(v == root) continue;
		e.push_back(edge(u, v, w));
	}
	printf("%d", solve());
	return 0;
}
/*
1
1000000000000000000
*/
