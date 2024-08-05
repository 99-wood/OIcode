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
const int MAXN = 200010;
ll js(ll m, ll n){
	if(n * n - 4 * m < 0) return -1;
	ll ans = (n + sqrt(n * n - 4 * m)) / 2;
	if(ans * (n - ans) == m) return ans;
	else return -1;
}
int n;
ll q[MAXN];
ll ans[MAXN];
bool dfs(int p, ll sum){
	if(p == 1){
		if(q[1] - sum <= 0) return false;
		ans[p] = q[1] - sum;
		return true;
	}
	ll a = js(q[p] - sum, q[p - 1] - sum);
	if(a == -1) return false;
	if(dfs(p - 1, sum + a)){
		ans[p] = a;
		return true;
	}
	else if(dfs(p - 1, sum + q[p] / a)){
		ans[p] = q[p] / a;
		return true;
	}
	else false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> q[i];
//	rep(i, 1)
	if(dfs(n, 0)){
		rep(i, 1, n) cout << ans[i] << " ";
		cout << endl;
		rep(i, 1, n - 1) cout << i << endl;
	}
	else{
		cout << -1;
	}
	
    return 0;
}
