#define int long long
namespace H{
    using hv = pair<int, int>;
    static const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    static const int base = 233;
    static vector<hv> pow(1, make_pair(1, 1));
    hv operator* (const hv& x, int w){
        return make_pair(x.first * w % mod1, x.second * w % mod2);
    }
    hv operator* (const hv& x, const hv& y){
        return make_pair(x.first * y.first % mod1, x.second * y.second % mod2);
    }
    hv operator+ (const hv& x, int w){
        return make_pair((x.first + w) % mod1, (x.second + w) % mod2);
    }
    hv operator- (const hv& x, int w){
        return make_pair((x.first - w + mod1) % mod1, (x.second - w + mod1) % mod2);
    }
    hv operator- (const hv& x, const hv& y){
        return make_pair((x.first - y.first + mod1) % mod1, (x.second - y.second + mod1) % mod2);
    }
    struct Hash{
        const int n;
        vector<hv> pre;
        Hash(const string& s) : pre(s.length() + 1), n(s.length()){
            pre[0] = make_pair(0, 0);
            rep(i, 1, n){
                pre[i] = pre[i - 1] * base + (int)s[i - 1];
            }
            while(pow.size() <= n) pow.push_back(pow.back() * base);
        }
        hv get(int l, int r){
            assert(r <= n);
            return pre[r] - pre[l - 1] * pow[r - l + 1];
        }
    };
}
using namespace H;



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
const int MAXN = 200010;
const int MOD = 998244353;
//const int MOD = 1e9 + 7;
const int INF = 1e15;
namespace H{
    using hv = pair<int, int>;
    static const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    static const int base = 233;
    static vector<hv> pow(1, make_pair(1, 1));
    hv operator* (const hv& x, int w){
        return make_pair(x.first * w % mod1, x.second * w % mod2);
    }
    hv operator* (const hv& x, const hv& y){
        return make_pair(x.first * y.first % mod1, x.second * y.second % mod2);
    }
    hv operator+ (const hv& x, int w){
        return make_pair((x.first + w) % mod1, (x.second + w) % mod2);
    }
    hv operator- (const hv& x, int w){
        return make_pair((x.first - w + mod1) % mod1, (x.second - w + mod1) % mod2);
    }
    hv operator- (const hv& x, const hv& y){
        return make_pair((x.first - y.first + mod1) % mod1, (x.second - y.second + mod1) % mod2);
    }
    struct Hash{
        const int n;
        vector<hv> pre;
        Hash(const string& s) : pre(s.length() + 1), n(s.length()){
            pre[0] = make_pair(0, 0);
            rep(i, 1, n){
                pre[i] = pre[i - 1] * base + (int)s[i - 1];
            }
            while(pow.size() <= n) pow.push_back(pow.back() * base);
        }
        hv get(int l, int r){
            assert(r <= n);
            return pre[r] - pre[l - 1] * pow[r - l + 1];
        }
    };
}
using namespace H;
string str;
bool f[15][MAXN];
int mn[15];
vector<int> pos;
void solve(){
    cin >> str;
    int n = str.length();
    Hash strh(str);
    str = " " + str;
    int last = -1;
    pos.push_back(0);
    rep(i, 1, n){
        if(str[i] == '*' || str[i] == '?'){
            if(last == -1 && i != 1 || last != -1){
                pos.push_back(i - 1);
            }
            last = i;
        }
    }
    pos.push_back(n);
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        Hash sh(s);
        int m = s.length();
        s = " " + s;
        int h = pos.size() - 1;
        rep(k, 0, h){
            rep(i, 0, m){
                f[k][i] = false;
            }
            mn[k] = m + 1;
        }
        f[0][0] = true;
        mn[0] = 0;
        rep(k, 1, h){
            rep(i, 0, m){
                int l = pos[k - 1] + 1, r = pos[k];
                if(str[l] == '*'){
                    int len = r - l;
                    if(i >= len && strh.get(l + 1, r) == sh.get(i - len + 1, i)){
                        if(mn[k - 1] <= i - len){
                            f[k][i] = true;
                            mn[k] = min(mn[k], i);
                        }
                    }
                }
                else if(str[l] == '?'){
                    int len = r - l;
                    if(i >= len + 1 && strh.get(l + 1, r) == sh.get(i - len + 1, i)){
                        if(f[k - 1][i - len - 1]){
                            f[k][i] = true;
                            mn[k] = min(mn[k], i);
                        }
                    }
                }
                else{
                    int len = pos[k] - pos[k - 1];
                    if(i >= len && strh.get(l, r) == sh.get(i - len + 1, i)){
                        if(f[k - 1][i - len]){
                            f[k][i] = true;
                            mn[k] = min(mn[k], i);
                        }
                    }
                }
            }
        }
        if(f[h][m]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return;
}
signed main(){
//    freopen("input.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << setprecision(20);
    int _t = 1;
//    cin >> _t;
    while(_t--){
        solve();
    }
    return 0;
}
