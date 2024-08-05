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
ll a[MAXN];
map<ll, bool> disable;
map<ll, int> dis;
vector<ll>pos;
queue<ll> q;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n){
		cin >> a[i];
		dis[a[i]] = 0;
		disable[a[i]] = true;
	} 
	rep(i, 1, n){
		if(!disable[a[i] - 1]){
			q.push(a[i] - 1);
			dis[a[i] - 1] = 1;
		}
		if(!disable[a[i] + 1]){
			q.push(a[i] + 1);
			dis[a[i] + 1] = 1;
		}
	} 
	ll ans = 0;
	int cnt = 0;
	while(cnt < m){
		int now = q.front();
		q.pop();
		if(disable[now]){
			continue;
		}
		++cnt;
		int d = dis[now];
		ans += d;
		pos.push_back(now);
		disable[now] = true;
		if(!disable[now - 1]){
			q.push(now - 1);
			int dd = dis[now - 1];
			dis[now - 1] = min(dd == 0 ? 0x3f3f3f3f : dd, d + 1);
		}
		if(!disable[now + 1]){
			q.push(now + 1);
			int dd = dis[now + 1];
			dis[now + 1] = min(dd == 0 ? 0x3f3f3f3f : dd, d + 1);
		}
	}
	cout << ans << endl;
	rep(i, 1, m) cout << pos[i - 1]<< " ";
    return 0;
}
