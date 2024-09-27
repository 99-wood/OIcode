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
char s[MAXN];
int cnt[MAXN][30];
int n;
int pre(int i, int c){
	if(i <= 0) return 0;
	else return cnt[i][c];
}
int suf(int i, int c){
	if(i > n) return 0;
	if((n & 1) == (i & 1)) return cnt[n][c] - pre(i - 2, c);
	else return cnt[n - 1][c] - pre(i - 2, c);
}
signed main(){
//	freopen("P2909_2.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
//	cin >> t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("\n%s", s + 1);
		rep(i, 1, n){
			if(i <= 2){
				rep(j, 0, 25) cnt[i][j] = 0;
			}
			else{
				rep(j, 0, 25) cnt[i][j] = cnt[i - 2][j];
			}
			cnt[i][s[i] - 'a']++;
		}
		int ans = 0x3f3f3f3f;
		if(n & 1){
			rep(i, 1, n){
				int mx1 = 0, mx2 = 0;
				rep(j, 0, 25) mx1 = max(mx1, pre(i - 1, j) + suf(i + 2, j));
				rep(j, 0, 25) mx2 = max(mx2, pre(i - 2, j) + suf(i + 1, j));
				ans = min(ans, n - (mx1 + mx2));
			}
		}
		else{
			int mx1 = 0, mx2 = 0;
			rep(j, 0, 25) mx1 = max(mx1, cnt[n - 1][j]);
			rep(j, 0, 25) mx2 = max(mx2, cnt[n][j]);
			ans = min(ans, n - (mx1 + mx2));
		}
		cout << ans << endl;
	}
    return 0;
}
