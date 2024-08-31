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
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;
const int MAXN = 100010;
ll c[MAXN];
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}
signed main(){
//	freopen("P2909_2.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		int x, y;
		cin >> n >> x >> y;
		int k = gcd(x, y);
		rep(i, 1, n) cin >> c[i];
		rep(i, 1, n) c[i] %= k;
		sort(c + 1, c + n + 1);
		ll ans = c[n] - c[1];
		rep(i, 2, n) ans = min(ans, c[i - 1] + k - c[i]);
		cout << ans << endl;
	}
    return 0;
}
