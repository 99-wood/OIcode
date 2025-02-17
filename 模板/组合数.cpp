#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> //??tree
#include <utility>
using namespace std;
namespace pbds = __gnu_pbds;
template<typename T>
using pbdstree = pbds::tree<T,pbds::null_type,less<T>,pbds::rb_tree_tag,pbds::tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
using ll = long long;
template <typename T>
using Qmin = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using Qmax = priority_queue<T>;
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define drep(i, a, b) for(int i = a; i >= (b); --i)
const int MAXN = 2000010;
//const int MOD = 998244353;
const int MOD = 1e9 + 7;
const int INF = 1e15;
int ksm(int x, int k){
    int ans = 1, now = x;
    while(k){
        if(k & 1) ans = ans * now % MOD;
        now = now * now % MOD;
        k >>= 1;
    }
    return ans;
}
int inv(int x){
    return ksm(x, MOD - 2);
}
int fac[MAXN], invf[MAXN];
int C(int n, int m){
    if(m < 0 || m > n) return 0;
    return fac[n] * invf[m] % MOD * invf[n - m] % MOD;
}
void solve(){
    int n, m;
    cin >> n >> m;
    cout << C(n, m) << endl;
    return;
}
void init(){
    const int n = 1000000;
    fac[0] = 1;
    rep(i, 1, n) fac[i] = fac[i - 1] * i % MOD;
    invf[n] = inv(fac[n]);
    drep(i, n - 1, 0) invf[i] = invf[i + 1] * (i + 1) % MOD;
    return;
}
signed main(){
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << setprecision(20);
    int _t = 1;
    cin >> _t;
    while(_t--){
        solve();
    }
    return 0;
}
