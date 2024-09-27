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
//#define ls tree[p].l
//#define rs tree[p].r
//#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;
const int MAXN = 400010;
int a[MAXN];
int cnt[MAXN];
int sum[MAXN];
int ans[MAXN];
int n;
int ask(int l, int r){
	return r > n ? sum[n] - sum[max(0, l - 1)] : sum[r] - sum[max(0, l - 1)];
}
int check(int p, int m){
	int res = 0;
	for(int k = 0; m * k <= n; ++k){
		res += ask(m * k, m * k + p);
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int q;
		cin >> n >> q;
		int p = (n & 1) ? (n + 1) / 2 : (n + 2) / 2;
		rep(i, 0, n){
			cnt[i] = 0;
			ans[i] = -1;
		}
		rep(i, 1, n){
			cin >> a[i];
			++cnt[a[i]];
		}
		rep(i, 1, n) sum[i] = sum[i - 1] + cnt[i];
		while(q--){
			int x;
			cin >> x;
			if(ans[x] != -1){
				cout << ans[x] << " ";
				continue;
			}
			int l = 0, r = x - 1;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(check(mid, x) < p) l = mid + 1;
				else{
					ans[x] = mid;
					r = mid - 1;
				}
			}
			cout << ans[x] << " ";
		}
		cout << endl;
	}
	return 0;
}
