#include<bits/stdc++.h>
#include<vector>
#define endl '\n'
#define int long long
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
using namespace std;
const int MAXN = 2000020;
int mu[MAXN];
bool flg[MAXN];
vector<int> prime;
void init(){
	const int N = 2000000;
	mu[1] = 1;
	rep(i, 2, N){
		if(!flg[i]){
			prime.push_back(i);
			mu[i] = -1;
		}
		for(int j = 0; j < prime.size() && prime[j] * i <= N; ++j){
			int p = prime[j];
			flg[p * i] = true;
			if(i % p == 0){
				mu[p * i] = 0;
				break;
			}
			mu[i * p] = -mu[i];
		}
	}
}
void solve(){
	int n;
	cin >> n;
	int ans = 0;
	rep(d, 1, n){
		rep(q, 1, n / d){
			ans += mu[q] * (n / d / q) * (n / d / q - 1) * d;
		}
	}
	cout << ans / 2;
}
signed main(){
	init();
//	rep(i, 1, 100) cout << mu[i] << " ";
//    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int _t=1;
//    cin>>_t;
    //    cout<<fixed<<setprecision(20);
    for(int i=1;i<=_t;i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
