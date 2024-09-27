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
//#define endl '\n'
using namespace std;
typedef long long ll;
const int MAXN = 200010;
ll a[MAXN];
struct node{
	ll h;
	int cnt;
	node(ll h = 0, int cnt = 0) : h(h), cnt(cnt){
	}
};
void solve(){
	int n;
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	stack<node> s;
	drep(i, n, 1){
		ll x = a[i];
		int cnt = 1;
		ll h = x / cnt + (x % cnt ? 1 : 0);
		if(!s.empty() && h >= s.top().h){
			node tp = s.top();
			s.pop();
			x += tp.h * tp.cnt;
			cnt += tp.cnt;
		}
		if(x % cnt){
			s.push(node(h, x % cnt));
			s.push(node(h - 1, x - x % cnt * cnt));
		}
		else{
			s.push(node(h, cnt));
		}
	}
	ll mn = s.top().h;
	ll mx = mn;
	while(!s.empty()){
		mx = max(mx, s.top().h);
		s.pop();
	}
	cout << mx - mn << endl;
	return;
}
int main(){
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int _t = 1;
	cin >> _t;
	while(_t--){
		solve();
//		cout << "!!";
	}
	return 0;
}

