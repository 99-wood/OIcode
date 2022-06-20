#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<bitset>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
int mylog(int a) {
	int ans=0;
	if(a&0xffff0000) {
		ans+=16;
		a>>=16;
	}
	if(a&0x0000ff00) {
		ans+=8;
		a>>=8;
	}
	if(a&0x000000f0) {
		ans+=4;
		a>>=4;
	}
	if(a&0x0000000c) {
		ans+=2;
		a>>=2;
	}
	if(a&0x00000002) {
		ans+=1;
		a>>=1;
	}
	return ans;
}
inline int read() {
	register int a=0,b=0;
	register char c;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')b=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return b?-a:a;
}
const int MAXN = 3e6 + 10;
const int MAXX = 1e7 + 10;
int f[MAXX];
int a[MAXN];
int cnt[MAXX];
int main(){
	freopen("yist.in", "r", stdin);
	freopen("yist.out", "w", stdout);
	int n = read();
	rep(i, 1, n){
		a[i] = read();
		++cnt[a[i]];
	}
	sort(a + 1, a + 1 + n);
	rep(i, 1, n){
		rep(j, 1, i - 1){
			if(a[i] + a[j] > 1e7) break;
			++f[a[i] + a[j]];
		}
	}
	ll ans = 0;
	rep(i, 1, n){
		if(a[i] == a[i - 1] || cnt[a[i]] < 2) continue;
		int l = 1, r = n;
		ll cnt_ = 0;
		while(l < r){
			while(a[l] + a[r] > a[i] && l < r) --r;
			while(a[l] + a[r] < a[i] && l < r) ++l;
			while(a[r - 1] == a[r] && l < r) --r;
			while(a[l + 1] == a[l] && l < r) ++l;
			if(a[l] + a[r] == a[i] && l < r){
				ans += 1LL * cnt[a[i]] * (cnt[a[i]] - 1) / 2 * cnt[a[l]] * cnt[a[r]] * cnt_;
				ans += 1LL * cnt[a[i]] * (cnt[a[i]] - 1) / 2 * cnt[a[l]] * (cnt[a[l]] - 1) / 2 * cnt[a[r]] * (cnt[a[r]] - 1) / 2;
				cnt_ += cnt[a[l]] * cnt[a[r]];
				++l;
				--r;
			}
		}
		if(l == r && a[l] + a[r] == a[i]){
			ans += 1LL * cnt[a[i]] * (cnt[a[i]] - 1) / 2 * cnt[a[l]] * (cnt[a[r]] - 1) / 2 * cnt_;
			ans += 1LL * cnt[a[i]] * (cnt[a[i]] - 1) / 2 * cnt[a[l]] * (cnt[a[r]] - 1) * (cnt[a[r]] - 2) * (cnt[a[r]] - 3) / 24;
		}
	}
	rep(i, 1, n){
		if(a[i] == a[i - 1] || cnt[a[i]] < 3) continue;
		ll cnt_ = 0;
		rep(j, 1, i - 1){
			if(a[i] - a[j] > a[j]){
				if(a[i] - a[j] - a[j] == a[j]) cnt_ += f[a[i] - a[j]] - (cnt[a[i] - a[j] - a[j]] - 1);
				else cnt_ += f[a[i] - a[j]] - cnt[a[i] - a[j] - a[j]];
			}
			else cnt_ += f[a[i] - a[j]];
		}
		ans += 1LL * cnt[a[i]] * (cnt[a[i]] - 1) * (cnt[a[i]] - 2) / 6 * cnt_ / 3;
	}
	
	printf("%lld\n", ans);
	return 0;
}