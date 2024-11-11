#include<bits/stdc++.h>
#include<vector>
#include<set>
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
int sum[MAXN];
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
	rep(i, 1, N) sum[i] = sum[i - 1] + mu[i];
	return;
}
int ask(int n, int m, int d){
	int a = n / d, b = m / d;
	int ans = 0;
	int l = 1, r = 1;
	while(l <= min(a, b)){
		r = min(a / (a / l), b / (b / l));
		ans += (sum[r] - sum[l - 1]) * (a / l) * (b / l);
		l = r + 1;
	}
	return ans;
}
void solve(){
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	cout << ask(b, d, k) - ask(a - 1, d, k) - ask(b, c - 1, k) + ask(a - 1, c - 1, k) << endl;
}
signed main(){
	init();
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int _t=1;
    cin>>_t;
    //    cout<<fixed<<setprecision(20);
    for(int i=1;i<=_t;i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}

