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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll x, y, k;
		cin >> x >> y >> k;
		if(k & 1){
			cout << x << " " << y << endl;
			rep(i, 1, k / 2){
				cout << x + i << " " << y + i << endl;
				cout << x - i << " " << y - i << endl;
			}
		}
		else{
			rep(i, 1, k / 2){
				cout << x + i << " " << y + i << endl;
				cout << x - i << " " << y - i << endl;
			}
		}
	}
    return 0;
}
