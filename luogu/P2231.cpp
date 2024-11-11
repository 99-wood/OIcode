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
int ksm(int a, int k){
	int ans = 1, now = a;
	while(k){
		if(k & 1) ans = ans * now;
		now = now * now;
		k >>= 1;
	}
	return ans;
}
int n, m;
vector<int> p;
int ans = 0;
void work(int pos, int cnt, int now){
	if(pos >= p.size()){
		ans += (cnt & 1 ? -1 : 1) * ksm(m / now, n);
		return;
	}
	work(pos + 1, cnt + 1, now * p[pos]);
	work(pos + 1, cnt, now);
	return;
}
void solve(){
	cin >> n >> m;
	int tmp = m;
	for(int i = 2; i * i <= tmp; ++i){
		if(tmp % i == 0){
			p.push_back(i);
			while(tmp % i == 0) tmp /= i;
		}
	}
	if(tmp > 1) p.push_back(tmp);
	work(0, 0, 1);
	cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int _t=1;
//    cin>>_t;
    //    cout<<fixed<<setprecision(20);
    for(int i=1;i<=_t;i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}

