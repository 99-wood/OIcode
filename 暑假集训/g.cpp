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
const int MAXN = 2000010;
ll a[MAXN];
int n;

ll sum[MAXN];
ll q[MAXN * 2];

ll b[MAXN];
int w;
void add(int p, ll v){
	while(p <= w){
		b[p] += v;
		p += (p & (-p));
	}
}
ll ask(int p){
	ll sum = 0;
	while(p){
		sum += b[p];
		p -= (p & (-p));
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> w;
	while(n--){
		int m;
		cin >> m;
		rep(i, 1, m) cin >> a[i];
		int l = 1, r = 0;
		int len = w - m + 1;
		rep(i, 1, m){
			while((l <= r) && q[l] < i - len + 1) ++l;
			while((l <= r) && a[q[r]] <= a[i]) --r;
			q[++r] = i;
			if(a[q[l]] < 0 && i <= w - m);
			else sum[i] += a[q[l]];
		}
		int now = m + 1;
		while(now <= w){
			while((l <= r) && q[l] < now - len + 1) ++l;
			if(a[q[l]] <= 0) break;
			add(now, a[q[l]]);
			add(w - (m - q[l]) + 1, -a[q[l]]);
			now = w - (m - q[l]) + 1;
//			++l;
		}
	}
	rep(i, 1, w) cout << sum[i] + ask(i) << " ";
    return 0;
}
