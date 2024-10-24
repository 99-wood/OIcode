n//#pragma GCC optimize(3, "Ofast", "inline")
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
#define endl '\n'
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
const int N = 1e5+10;
//const int sq=1e3+10;
struct Block{
	int l,r,add,q;
}b[N];
int h[N];
void update(int idx){
	int l=b[idx].l,r=b[idx].r;
	int res=0;
	for(int i=l;i<=r;i++) h[i]+=b[idx].add;
	b[idx].add=0;
	for(int i=l+1;i<=r;i++){
		res+=max(0ll,h[i]-h[i-1]);
	}
	b[idx].q=res;
//	cout<<"update"<<idx<<" "<<res<<endl;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>h[i];
	int len=sqrt(n);
	if(len*len!=n) len++;
	int cnt=1;
//	cout<<n<<" "<<m<<endl;
	while(1){
		b[cnt].l=(cnt-1)*len+1;
		b[cnt].r=cnt*len;
//		cout<<b[cnt].l<<" "<<b[cnt].r<<endl;
		if(b[cnt].r>=n){
			b[cnt].r=n;
			break;
		}
		cnt++;
	}
	for(int i=1;i<=cnt;i++) update(i);
//	cout<<cnt<<endl;
//	return ;
	while(m--){
		int t,l,r,k;
		cin>>t>>l>>r;
		if(t==1){
			cin>>k;
			for(int i=1;i<=cnt;i++){
				if(l>b[i].r || r<b[i].l) continue;
				if(l<=b[i].l && b[i].r<=r) b[i].add+=k;
				else{
					for(int j=b[i].l;j<=b[i].r;j++){
						if(l<=j && j<=r) h[j]+=k;
					}
					update(i);
				}
			}
		}
		else{
			int res=0,lasth=0;
			for(int i=1;i<=cnt;i++){
				if(l>b[i].r || r<b[i].l) continue;
				if(l<=b[i].l && b[i].r<=r){
					res+=b[i].q;
					res+=max(h[b[i].l]+b[i].add-lasth,0ll);
					lasth=h[b[i].r]+b[i].add;
//					cout<<"a";
				}
				else{
					update(i);
					for(int j=b[i].l;j<=b[i].r;j++){
						if(l<=j && j<=r) {
							res+=max(h[j]-lasth,0ll);
							lasth=h[j];
						}
					}
//					cout<<"b";
				}
//				cout<<res<<" ";
			}
			cout<<res<<endl;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
/*
5 2
1 3 1 4 5
1 3 4 2
2 2 4
*/
