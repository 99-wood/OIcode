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
//#include<unordered_map>
//#include<chrono>
#include<random>
#include<functional>
#include<unordered_set>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
//#define ls (p << 1)
//#define rs (p << 1 | 1)
//#define mid ((l + r) >> 1)
#define endl '\n'
using namespace std;
typedef long long ll;
const int MAXN = 1000010;
const int N = 200000;
#define int long long
int a[MAXN];
int pos[MAXN];
int fa[MAXN];
int cnt;
ll ans;
int siz[MAXN][2];
bool app[MAXN][2];
int findfa(int p){
	return fa[p] == p ? p : findfa(fa[p]);
}
pair<int, bool> getv(int p){
	p = findfa(p);
	if(siz[p][0] == siz[p][1]){
		if(app[p][0]) return pair<int, bool>(siz[p][0], app[p][0]);
		else return pair<int, bool>(siz[p][1], app[p][1]);
	}
	else if(siz[p][0] > siz[p][1]){
		return pair<int, bool>(siz[p][0], app[p][0]);
	}
	else{
		return pair<int, bool>(siz[p][1], app[p][1]);
	}
}
void update(int p){
	p = findfa(p);
	auto res = getv(p);
	ans += res.first;
	cnt += res.second;
	return;
}
void clear(int p){
	p = findfa(p);
	auto res = getv(p);
	ans -= res.first;
	cnt -= res.second;
	return;
}
void merge(int x, int y){
	int fx = findfa(x), fy = findfa(y);
	fa[fx] = fy;
	rep(i, 0, 1){
		siz[fy][i] += siz[fx][i];
		app[fy][i] |= app[fx][i];
	}
	return;
}
void solve(){
	cnt = ans = 0;
	int n;
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	a[n + 1] = 0;
	rep(i, 1, n){
		fa[i] = i;
		siz[i][i & 1] = 1;
		siz[i][(i & 1) ^ 1] = 0;
	}
	rep(i, 1, n) pos[i] = i;
	stable_sort(pos + 1, pos + n + 1, [&](int x, int y){
		return a[x] > a[y];
	});
	rep(i, 1, n){
		app[i][i & 1] = (a[i] == a[pos[1]]);
		app[i][(i & 1) ^ 1] = false;
	}
	ll res = 0;
	rep(i, 1, n){
		int p = pos[i];
		if(i > 1 && a[p + 1] >= a[pos[i - 1]] && a[p + 1] != a[p]) clear(p + 1);
		if(i > 1 && a[p - 1] >= a[pos[i - 1]]) clear(p - 1);
		if(i > 1 && a[p + 1] >= a[pos[i - 1]] && a[p + 1] != a[p]) merge(p, p + 1);
		if(i > 1 && a[p - 1] >= a[pos[i - 1]]) merge(p, p - 1);
		update(p);
		if(cnt) res = max(res, a[pos[1]] + ans + a[p]);
		else res = max(res, a[pos[1]] + ans - 1 + a[p]);
//		cout << p << " " << ans << " " << cnt << endl;
	}
	cout << res << endl;
	return;
}
signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
/*
1
10
3 3 3 3 4 1 2 3 5 4

*/
