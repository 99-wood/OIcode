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
int s[MAXN];
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
		rep(i, 1, n){
			char c;
			scanf("\n%c", &c);
			s[i] = c - '0';
		}
		int m = sqrt(n);
		if(m * m != n){
			printf("No\n");
			continue;
		}
		bool flag = true;
		rep(i, 1, m) if(s[i] == 0){
			flag = false;
			break;
		}
		rep(i, 1, m) if(s[n - i + 1] == 0){
			flag = false;
			break;
		}
		rep(i, 2, m - 1){
			if(s[(i - 1) * m + 1] == 0 || s[i * m] == 0){
				flag = false;
				break;
			}
			rep(j, 2, m - 1){
				if(s[(i - 1) * m + j] == 1){
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}
