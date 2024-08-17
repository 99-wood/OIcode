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
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
//#define ls (p << 1)
//#define rs (p << 1 | 1)
//#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;
const int MAXN = 200010;
struct node{
	ll a, b;
}in[MAXN];
vector<int> a;
vector<int> b;
ll n, m;
bool check(vector<node> &r, ll w){
	int n = r.size();
	int req = (n + 1) / 2;
	req = (n - (req - 1));
	int cnt = 0;
	ll now = m;
	drep(i, n - 1, 0){
		if(r[i].a >= w) ++cnt;
		else{
			if(w - r[i].a <= now){
				now -= w - r[i].a;
				++cnt;
			}
		}
		if(cnt >= req) return true;
	}
	return cnt >= req;
}
ll solve(int p){
	if(p == 0) return -1;
	vector<node> b;
	rep(i, 1, n){
		if(i == p) continue;
		b.push_back(a[i]);
	}
	ll l = 0, r = 3e9;
	ll ans = 0;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(b, mid)){
			l = mid + 1;
			ans = mid;
		}
		else{
			r = mid - 1;
		}
	}
	return ans;
}
signed main(){
//	freopen("P2909_2.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		ll ans = 0;
		rep(i, 1, n) cin >> in[i].a;
		rep(i, 1, n) cin >> in[i].b;
		a.clear();
		b.clear();
		rep(i, 1, n){
			if(a[i].b) b.push_back(a[i].a);
			else a.push_back(a[i].a);
		}
		sort(a.begin(), a.end());
		sort(b.back(), b.end());
		ll ans = 0;
		int l = 
	}
    return 0;
}
