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
vector<int> nxt[MAXN];
vector<int> leaf;
int w[MAXN];
int cc;
void dfs(int p, int fa){
	if(nxt[p].size() == 1 && p != 1){
		leaf.push_back(p);
		return;
	}
	if(p != 1 && w[p] == -1) ++cc;
	for(auto x : nxt[p]){
		if(x == fa) continue;
		dfs(x, p);
	}
	return;
}
signed main(){
//	freopen("P2909_2.in", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		rep(i, 1, n) nxt[i].clear();
		leaf.clear();
		rep(i, 1, n - 1){
			int x, y;
			cin >> x >> y;
			nxt[x].push_back(y);
			nxt[y].push_back(x);
		}
		rep(i, 1, n){
			char c;
			scanf("\n%c", &c);
			if(c == '?') w[i] = -1;
			else w[i] = c - '0';
		}
		cc = 0;
		dfs(1, 0);
		int cnt0 = 0, cnt1 = 0, cnt = 0;
		for(auto x : leaf){
			if(w[x] == -1) ++cnt;
			else if(w[x] == 1) ++cnt1;
			else ++cnt0;
		}
		if(w[1] == -1){
			int mx = max(cnt0, cnt1);
			int ans = mx + cnt / 2;
			if((cc & 1) && cnt0 == cnt1){
				if(cnt) ans = max(ans, cnt0 + (cnt - 1) / 2 + 1);
			}
			cout << ans << endl;
		}
		else{
			if(w[1] == 1){
				cout << cnt0 + (cnt - cnt / 2) << endl;
			}
			else{
				cout << cnt1 + (cnt - cnt / 2) << endl;
			}
		}
	}
    return 0;
}
