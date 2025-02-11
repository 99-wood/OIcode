#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> //??tree
using namespace std;
namespace pbds = __gnu_pbds;
template<typename T>
using pbdstree = pbds::tree<T,pbds::null_type,less<T>,pbds::rb_tree_tag,pbds::tree_order_statistics_node_update>;
#define int long long
using ll = long long;
template <typename T>
using Qmin = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using Qmax = priority_queue<T>;
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define drep(i, a, b) for(int i = a; i >= (b); --i)
const int MAXN = 200010;
const int MOD = 998244353;
const int INF = 1e18;
//const int MOD = 1e9 + 7;
int f[MAXN], h[MAXN], sum[MAXN], w[MAXN];
#define mid ((l + r) >> 1)
using point = pair<int, int>;
using vec = pair<int, int>;
int operator* (const vec& a, const vec& b){
    if(a.second >= 1e9 && b.first >= 1e9){
        cout << "!";
    }
    return (double)a.first * b.second - (double)a.second * b.first;
}
vec operator- (const vec& a, const vec& b){
    return make_pair(a.first - b.first, a.second - b.second);
}
void cdq(int l, int r){
    if(l == r) return;
    cdq(l, mid);
    vector<point> s;
    rep(i, l, mid){
        s.push_back(make_pair(2 * h[i], h[i] * h[i] - sum[i] + f[i]));
    }
    std::sort(s.begin(), s.end(), [&](point a, point b){
       return a.first == b.first ? a.second > b.second : a.first < b.first;
    });
    vector<point> q;
    for(auto p : s){
        while(q.size() > 1 && ((q[q.size() - 1] - q[q.size() - 2]) * (p - q[q.size() - 1]) <= 0)) q.pop_back();
        q.push_back(p);
    }
    vector<int> id(r - mid);
    frep(i, 0, r - mid) id[i] = mid + i + 1;
    std::sort(id.begin(), id.end(), [&](int x, int y){
       return h[x] < h[y];
    });
    int pos = 0;
    for(auto i : id){
        while(pos + 1 < q.size() && (q[pos + 1] - q[pos]) * make_pair(1, h[i]) >= 0) ++pos;
        f[i] = min(f[i], q[pos].second - q[pos].first * h[i] + sum[i - 1] + h[i] * h[i]);
    }
    cdq(mid + 1, r);
}
void solve(){
    int n;
    cin >> n;
    f[1] = 0;
    rep(i, 1, n) cin >> h[i];
    rep(i, 1, n) cin >> w[i];
    rep(i, 1, n) sum[i] = sum[i - 1] + w[i];
    rep(i, 2, n) f[i] = (h[i] - h[1]) * (h[i] - h[1]) + sum[i - 1] - sum[1];
    cdq(1, n);
    cout << f[n] << endl;
    return;
}
signed main(){
//    freopen("input.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _t = 1;
//    cin >> _t;
    while(_t--){
        solve();
    }
    return 0;
}
