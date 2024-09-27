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
const int MAXN = 200010;
int a[MAXN];
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
//	scanf("%d", &t);
	while(t--){
		int n;
		ll k;
		cin >> n >> k;
		rep(i, 1, n) cin >> a[i];
		if(n == 1){
			if(a[1] <= k - 1) cout << k << endl;
			else cout << k - 1 << endl;
			continue;
		}
		ll gc = 0;
		rep(i, 1, n) gc = gcd(gc, a[i]);
		--n;
		if(gc == 1){
			cout << n + k << endl;
		}
		else{
			if(n * (gc - 1) < k){
				k -= n * (gc - 1);
				cout << n * gc + k << endl;
			}
			else{
				int cnt = k / (gc - 1);
				k %= (gc - 1);
				if(k == 0) cout << cnt * gc - 1 << endl;
				else cout << cnt * gc + k << endl;
			}
		}
	}
    return 0;
}
