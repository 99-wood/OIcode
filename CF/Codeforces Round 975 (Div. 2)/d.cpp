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
#include<complex>
//#include<unordered_map>
//#include<chrono>
#include<random>
#include<unordered_set>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define endl '\n'
using namespace std;
typedef long long ll;
const int MAXN = 300000;
int a[MAXN];
//bool no[MAXN];
//#define int long long
void solve(){
	int n;
	cin >> n;
	rep(i, 1, n) cin >> a[i];
//	rep(i, 1, n + 1) no[i] = false;
//	rep(i, 1, n){
//		no[min(i + a[i], n + 1)] = true;
//	}
	set<int> s;
	set<int> s_;
	rep(i, 1, n) s.insert(i);
	int r = 1;
	int pos = 1;
	rep(i, 1, n){
//		if(no[i]) break;
		int to = a[i];
		if(!s_.empty()){
			to = *s.begin();
			--to;
		}
		if(to == 0) break;
		if(to > a[i]) to = a[i];
		s_.insert(to);
		auto p = s.lower_bound(to);
		s.erase(p);
		if(to >= pos){
			p = s.lower_bound(pos);
			if(p == s.begin()){
				pos = 0;
			}
			else{
				--p;
				pos = *p;
			}
		}
		while(r + 1 <= n){
			int t = a[r + 1];
			auto p = s.upper_bound(pos);
		}
	}
	cout << 0 << endl;
}
signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int _t = 1;
	cin >> _t;
	while(_t--){
		solve();
	}
	return 0;
}

