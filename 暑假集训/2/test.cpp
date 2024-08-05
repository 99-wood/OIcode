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
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls tree[p].l
#define rs tree[p].r
#define mid ((l + r) >> 1)
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
const int MAXN = 50;
//map<ll, int> mp1;
vector<ll> s1;
vector<ll> s2;
ll w[MAXN];
ll dp[1 << 22];
//int lowbit(int x){
//	return x & (-x);
//}
ll highbit(ll x){
	ll res = 1 << 23;
	while((res & x) == 0){
		res >>= 1;
	}
	return res;
}
int len;
int n;
ll m;
void f1(int p, ll v){
	if(p > len){
		if(v <= m) s1.push_back(v);
		return;
	}
	f1(p + 1, v + w[p]);
	f1(p + 1, v);
}
void f2(int p, ll v){
	if(p > n){
		if(v <= m) s2.push_back(v);
		return;
	}
	f2(p + 1, v + w[p]);
	f2(p + 1, v);
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	ll m;
	cin >> n >> m;
	rep(i, 1, n) cin >> w[i];
	len = n / 2;
//	dp[0] = 0;
//	s1.push_back(0);
//	frep(i, 1, 1 << len){
//		dp[i] = dp[i - highbit(i)] + w[(ll)log2(highbit(i))];
//		if(dp[i] <= m) s1.push_back(dp[i]);
//	}
//	dp[0] = 0;
//	s2.push_back(0);
//	frep(i, 1, 1 << (n - len)){
////		cout << (((ll)log2(highbit(i << 1))) << len) << " ";
//		dp[i] = dp[(i - highbit(i))] + w[((ll)log2(highbit(i << 1))) << len];
//		if(dp[i] <= m)s2.push_back(dp[i]);
//	}
	f1(1, 0);
	f2(len + 1, 0);
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	ll ans = 0;
	frep(i, 0, s2.size()){
		ll now = s2[i];
		int p = lower_bound(s1.begin(), s1.end(), m - now + 1) - s1.begin();
		ans += p;
//		cout << now << " "<< s1[p] << endl;
	}
//	int p1 = 0, p2 = s2.size() - 1;
//	ll ans = 0;
//	while(p2 >= 0){
//		ll cnt = 0;
//		while(p1 < s1.size() && s1[p1] <= m - s2[p2]){
//			++p1;
//			++cnt;
//		}
//		if(cnt == 0){
//			ll now = s2[p2];
//			--p2;
//			while(p2 >= 0 && s2[p2] == now) --p2;
//		}
//		else{
//			ll cnt2 = 0;
//			ll now = s2[p2];
//			while(p2 >= 0 && s2[p2] == now){
//				++cnt2;
//				--p2;
//			}
//			ans += cnt * cnt2;
//		}
//	}
	cout << ans;
    return 0;
}
