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
#include<list>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls tree[p].l
#define rs tree[p].r
//#define mid ((l + r) >> 1)
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
const int MAXN = 5000020;
int trie[MAXN][2];
int mx[MAXN];
int endd;
void add(int x, int pos){
	int p = 0;
	drep(i, 29, 0){
		int to = (x >> i) & 1;
		if(!trie[p][to]){
			trie[p][to] = ++endd;
			trie[endd][0] = trie[endd][1] = mx[endd] = 0;
		}
		mx[trie[p][to]] = max(mx[trie[p][to]], pos);
		p = trie[p][to];
	}
	return;
}
int query(int x, int req){
	int p = 0;
	int ans = 0;
	drep(i, 29, 0){
		int to = (x >> i) & 1, q = (req >> i) & 1;
		if(q){
			if(trie[p][to]) ans = max(ans, mx[trie[p][to]]);
			if(trie[p][to ^ 1]) p = trie[p][to ^ 1];
			else return ans;
		}
		else{
			if(trie[p][to]){
				p = trie[p][to];
			}
			else{
				return ans;
			}
		}
	}
	ans = max(ans, mx[p]);
	return ans;
}
int n;
ll k;
int a[MAXN];
ll check(int req){
	trie[0][0] = trie[0][1] = 0;
	endd = 0;
	ll ans = 0;
	int pos = 0;
	rep(i, 1, n){
		pos = max(pos, query(a[i], req));
		ans += pos;
		add(a[i], i);
	}
	return ans;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		rep(i, 1, n) cin >> a[i];
		int l = 0, r = (1 << 30) - 1, ans = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(mid) >= k){
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << endl;
	}
    return 0;
}
