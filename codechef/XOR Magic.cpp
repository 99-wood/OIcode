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
using namespace std;
typedef long long ll;
const int MAXN = 100010;
ll f[40][MAXN];
int sum[40][MAXN];
int a[MAXN];
const int N = 30;
int ask(int d, int l, int r){
	return sum[d][r] - sum[d][l - 1];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("in.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		rep(i, 1, n) cin >> a[i];
		rep(d, 0, N){
			rep(i, 1, n){
				sum[d][i] = sum[d][i - 1] + ((a[i] >> d) & 1);
			}
		}
		for(int i = 1; i + 1 <= n; ++i){
			f[1][i] = ask(0, i, i) + (1 - ask(0, i + 1, i + 1));
		}
		rep(d, 2, N){
			ll w = (1ll << d);
			for(int i = 1; i + w - 1 <= n; ++i){
				f[d][i] = f[d - 1][i] + f[d - 1][i + w / 2]
					+ (1ll << (d - 1)) * (ask(d - 1, i, i + w / 2 - 1) + (w / 2 - ask(d - 1, i + w / 2, i + w - 1)));
			}
		}
		while(m--){
			int l, r;
			cin >> l >> r;
			ll ans = 0;
			int p = l;
			drep(k, N, 1){
				if(p + (1ll << k) - 1 <= r){
					ans += f[k][p];
					p += (1ll << k);
				}
				ll w = (1ll << k);
				if(p + w / 2 - 1 <= r){
					int cnt = 0;
					cnt += ask(k - 1, p, p + w / 2 - 1);
					cnt += (r - (p + w / 2) + 1) - ask(k - 1, p + w / 2, r);
					ans += cnt * (1ll << (k - 1));
				}
				else{
					int cnt = ask(k - 1, p, r);
					ans += cnt * (1ll << (k - 1));
				}
			}
			cout << ans << endl;
		}
	}	
	return 0;
}
