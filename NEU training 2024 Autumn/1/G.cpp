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
//#define mid ((l + r) >> 1)
using namespace std;
//typedef long long ll;
#define int long long 
void solve(){
	int x,L,R;
	cin>>x>>L>>R;
	vector<int> fac;
	int xx=x,y=1;
	for(int i=2;i*i<=xx;i++){
		if(xx%i==0){
			int cnt=0;
			while(xx%i==0){
				xx/=i;
				cnt++;
			}
			if(cnt%2==1){
				y*=i;
				x*=i;
			}
		}
	}
	if(xx!=1){
		y*=xx;
		x*=xx;
	}
//	cout<<x<<endl;
	int l=1,r=R/x;
	int ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(mid*mid<=R/x){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
//	cout<<ans<<endl;
	if(ans==-1){
		cout<<"-1\n";
		return ;
	}
	x*=ans*ans;
	y*=ans*ans;
	if(x>=L){
		cout<<y<<endl;
	}
	else cout<<"-1\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	for(auto p : prime) cout << p << " ";
//	cout << pri
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
