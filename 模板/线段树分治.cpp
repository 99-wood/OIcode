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
#include<numeric>
//#include<unordered_map>
#include<chrono>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;
using ll = long long;
const int MAXN = 500010;
vector<pair<int, int>> s[MAXN * 4];
int n;
int fa[MAXN], siz[MAXN];
void modify(int p, int l, int r, int x, int y, const pair<int, int>& a){
	if(x <= l && r <= y){
		s[p].push_back(a);
		return;
	}
	if(y < l || r < x) return;
	modify(ls, l, mid, x, y, a);
	modify(rs, mid + 1, r, x, y, a);
	return;
}
int findfa(int p){
	return fa[p] == p ? p : findfa(fa[p]);
}
int merge(int x, int y){
	if(siz[x] > siz[y]) swap(x, y);
	siz[y] += siz[x];
	fa[x] = y;
	return x;
}
void split(int x){
	siz[fa[x]] -= siz[x];
	fa[x] = x;
	return;
}
void query(int p, int l, int r){
	stack<int> st;
	bool enable = true;
	for(auto [x, y] : s[p]){
		int fx = findfa(x), fy = findfa(y);
		int fx_ = findfa(x + n), fy_ = findfa(y + n);
		if(fx == fy || fx_ == fy_){
			enable = false;
			break;
		}
		st.push(merge(fx, fy_));
		st.push(merge(fy, fx_));
	}
	if(l == r){
		if(enable) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else{
		if(enable){
			query(ls, l, mid);
			query(rs, mid + 1, r);
		}
		else{
			rep(i, l, r) cout << "No" << endl;
		}
	}
	while(!st.empty()){
		int p = st.top();
		st.pop();
		split(p);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m, k;
	cin >> n >> m >> k;
	iota(fa + 1, fa + n * 2 + 1, 1);
	fill(siz + 1, siz + n * 2 + 1, 1);
	rep(i, 1, m){
		int x, y, s, t;
		cin >> x >> y >> s >> t;
		++s;
		modify(1, 1, k, s, t, pair<int, int>(x, y));
	}
	query(1, 1, k);
	return 0;
}
