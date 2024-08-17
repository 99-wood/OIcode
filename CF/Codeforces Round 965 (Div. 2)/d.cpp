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
//#define ls (p << 1)
//#define rs (p << 1 | 1)
//#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;
const int MAXN = 200010;
vector<int> nxt[MAXN];
vector<int> pre[MAXN];
int u[MAXN], v[MAXN];
int dis[MAXN];
int a[MAXN];
signed main(){
//	freopen("P2909_2.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		rep(i, 1, n){
			nxt[i].clear();
			pre[i].clear();
			dis[i] = i - 1;
			a[i] = 0;
		}
		rep(i, 1, m){
			cin >> u[i] >> v[i];
			nxt[u[i]].push_back(v[i]);
			pre[v[i]].push_back(u[i]);
		}
//		dis[1] = 0;
		rep(i, 2, n){
			for(auto x : pre[i]){
				dis[i] = min(dis[i], dis[x] + 1);
			}
			dis[i] = min(dis[i], dis[i - 1] + 1);
		}
		rep(i, 1, m){
			int d = dis[u[i]] + 1;
			int r = v[i] - 1 - d;
			if(u[i] + 1 <= r){
				a[u[i] + 1]++;
				a[r + 1]--;
			}
		}
		rep(i, 1, n){
			a[i] = a[i - 1] + a[i];
		}
		rep(i, 1, n - 1){
			if(a[i]) cout << 0;
			else cout << 1;
		}
		cout << endl;
	}
    return 0;
}
/*
1
6 1
2 6
*/
