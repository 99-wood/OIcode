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
using namespace std;
typedef long long ll;
//ll lcm = 1000000007;
const int MAXN = 1000010;
vector<int> ans[MAXN];
int endd;
void Bitonic_sort(int n){
	for(int len = 1; len < n; len <<= 1){
		++endd;
		int p = 0;
		while(p < n){
			for(int i = 0; i < len; ++i){
				if(p + i < n && (p + (len << 1) - 1 - i) < n){
					ans[endd].push_back(p + i);
					ans[endd].push_back(p + (len << 1) - 1 - i);
				}
			}
			p += (len << 1);
		}
		int k = len;
		while(k >= 2){
			++endd;
			p = 0;
			while(p < n){
				for(int i = 0; i < (k >> 1); ++i){
					if(p + i < n && p + i + (k >> 1) < n){
						ans[endd].push_back(p + i);
						ans[endd].push_back(p + i + (k >> 1));
					}
				}
				p += k;
			}
			k >>= 1;
		}
	}
}
int main(){
//	freopen("P2909_2.in", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin >> n;
	Bitonic_sort(n);
	cout << endd << endl;;
	rep(i, 1, endd){
		cout << ans[i].size() / 2 << " ";
		for(auto x : ans[i]){
			cout << x << " ";
		}
		cout << endl;
	}
    return 0;
}
