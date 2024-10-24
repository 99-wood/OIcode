//#pragma GCC optimize(3, "Ofast", "inline")
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
//#include<numeric>
//#include<random>
//#include<unordered_map>
//#include<chrono>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define int long long 
using namespace std;
typedef long long ll;
const int N=110;
bool vis[N];
void solve(){
	int n,t;
	cin>>n>>t;
	vis[1]=1;
	for(int i=1;i<=t;i++){
		int x,y;
		cin>>x>>y;
		if(y!=-1 && vis[y]) vis[x]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(vis[i]) ans++;
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		if(vis[i]) cout<<i<<" ";
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	Euler();
//	for(auto p : prime) cout << p << " ";
//	cout << pri
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
