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
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;
const int MAXN = 100;
int g[MAXN][MAXN];
int f[3000];
int a[MAXN][MAXN];
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	rep(i, 1, n){
		rep(j, 1, m){
			char c;
			scanf("\n%c", &c);
			a[i][j] = c - '0';
		}
		int f[MAXN][MAXN];
		memset(f, 0, sizeof(f));
		f[1][0] = 0;
		f[1][1] = 1;
		rep(j, 2, m){
			f[j][0] = 0;
			rep(k, 1, j){
				f[j][k] = f[j - 1][k];
				int cnt = 0;
				drep(p, j, 1){
					if(a[i][p] == a[i][j]) ++cnt;
					f[j][k] = max(f[j][k], f[p - 1][k - 1] + cnt);
				}
			}
		}
		rep(j, 0, m){
			g[i][j] = f[m][j];
		}
	}
	int ans = 0;
	rep(i, 1, n){
		drep(j, t, 0){
			rep(k, 0, j){
				f[j] = max(f[j], f[j - k] + g[i][k]);
				ans = max(ans, f[j]);
			}
		}
	}
	cout << ans;
	return 0 ;
}
