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
const int MAXN = 200000;
ll a[MAXN];
void solve(){
	int n, m;
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	map<ll, ll> cnt;
	ll last = -1;
	rep(i, 1, n){
		ll l = i - 1, r = (n - i);
		++cnt[l * r + (n - 1)];
		if(last != -1){
			cnt[l * (n - l)] += (a[i] - last - 1);
		}
		last = a[i];
	}
	while(m--){
		ll k;
		cin >> k;
		cout << cnt[k] << " ";
	}
	cout << endl;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int _t = 1;
	cin >> _t;
	while(_t--){
		solve();
	}
	return 0;
}

