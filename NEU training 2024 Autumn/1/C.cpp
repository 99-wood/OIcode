//#pragma GCC optimize(3, "Ofast", "inline")
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
//#include<numeric>
//#include<random>
//#include<unordered_map>
//#include<chrono>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define int long long 
using namespace std;
typedef long long ll;
const int MAXN = 200010;
int n;
string str;
struct node{
	int id, l, r, t;
}que[MAXN];
bool vis[MAXN];
int ans[MAXN];
bool enable(int p){
	return 1 <= p && p <= n && !vis[p];
}
int c[MAXN];
void add(int p){
	while(p <= n){
		c[p]++;
		p += (p & (-p));
	}
	return;
}
int ask(int p){
	int ans = 0;
	while(p){
		ans += c[p];
		p -= (p & (-p));
	}
	return ans;
}
void solve(){
	cin >> str;
	str = " " + str;
	n = str.size() - 1;
	rep(i, 0, n) c[i] = 0;
	int m;
	cin >> m;
	rep(i, 1, m) cin >> que[i].t >> que[i].l >> que[i].r;
	rep(i, 1, m) que[i].id = i;
	sort(que + 1, que + m + 1, [&](node a, node b){
		return a.t < b.t;
	});
	queue<int> q[2];
	rep(i, 1, n) if(str[i] == '1'){
		q[1].push(i);
		add(i);
		vis[i] = true;
	}
	int now = 1;
	int p = 1;
	while(p <= m){
		while(now < que[p].t){
			while(!q[now & 1].empty()){
				int pos = q[now & 1].front();
				q[now & 1].pop();
				if(enable(pos - 1)){
					vis[pos - 1] = true;
					add(pos - 1);
					q[(now + 1) & 1].push(pos - 1);
				}
				if(enable(pos + 1)){
					vis[pos + 1] = true;
					add(pos + 1);
					q[(now + 1) & 1].push(pos + 1);
				}
			}
			++now;
		}
		if(now > n) now = 1e9;
		ans[que[p].id] = ask(que[p].r) - ask(que[p].l - 1);
		++p;
	}
	rep(i, 1, m) cout << ans[i] << endl;
	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
