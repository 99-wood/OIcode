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
//#define ls (p << 1)
//#define rs (p << 1 | 1)
//#define mid ((l + r) >> 1)
#define int long long 
using namespace std;
typedef long long ll;
const int N = 1e7+5e6+10;
const int M=998244353;
int fac[N],inv[N];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%M;
		a=a*a%M;
		b>>=1;
	}
	return res;
}
void init(){
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%M;
	inv[N-1]=ksm(fac[N-1],M-2);
	for(int i=N-2;i>=1;i--) inv[i]=inv[i+1]*(i+1)%M;
}
int C(int n,int m){
	if(m==0 || n==m) return 1;
	return fac[n]*inv[n-m]%M*inv[m]%M;
}
int cal(int a,int b){
	int res=0;
	for(int i=0;i<=min(a,b);i++){
		res+=C(a,i)*C(b,i)%M*fac[i]%M;
		if(res>=M) res-=M;
	}
	return res;
}
void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	int ans=1;
	ans=ans*cal(a,b)%M;
	ans=ans*cal(b,c)%M;
	ans=ans*cal(a,c)%M;
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
//	for(int i=1;i<=100;i++) cout<<fac[i]<<" ";
//	cout<<endl;
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
