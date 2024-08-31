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

signed main(){
//	freopen("P2909_2.in", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, m;
//		cin >> n >> m;
		scanf("%d%d", &n, &m);
		int mx = 0;
		rep(i, 1, n){
			int a;
			scanf("%d", &a);
			mx = max(mx, a);
		}
		rep(i, 1, m){
			char c;
			scanf("\n%c", &c);
			int l, r;
			scanf("%d%d", &l, &r);
			if(c == '+'){
				if(l <= mx && mx <= r) ++mx;
			}
			else{
				if(l <= mx && mx <= r) --mx;
			}
			printf("%d ", mx);
		}
		printf("\n");
	}
    return 0;
}
