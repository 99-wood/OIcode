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
#include<chrono>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls tree[p].l
#define rs tree[p].r
#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;
const int MAXN = 400010;
int a[MAXN];
int b[MAXN];
int st[20][MAXN];
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}
int ask(int l, int r){
	int k = log2(r - l + 1);
	return gcd(st[k][l], st[k][r - (1 << k) + 1]);
}
bool check(int n){
    return n > 0 && (n & (n - 1)) == 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		int m = n - 1;
		rep(i, 1, m) b[i] = abs(a[i + 1] - a[i]);
		rep(i, 1, m) st[0][i] = b[i];
		for(int k = 1; (1 << k) <= m; ++k){
			for(int i = 1; i + (1 << k) - 1 <= m; ++i){
				st[k][i] = gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
			}
		}
		ll ans = n;
		int l = 1, r = 1;
		while(l <= m){
			int cnt = 0;
			while(r < l) ++r;
			while(r < m && !check(ask(l, r))) ++r;
			if(check(ask(l, r))){
				ans += (m - r + 1);
//				cout << l << " " << r + 1 << endl;
			}
			++l;
		}
		ll cnt = 1;
		rep(i, 1, m){
			if(b[i] == 0){
				++cnt;
			}
			else{
				ans += (cnt * (cnt - 1)) / 2;
				cnt = 1;
			}
		}
		ans += (cnt * (cnt - 1)) / 2;
		cout << ans << endl;
	}
	return 0;
}
