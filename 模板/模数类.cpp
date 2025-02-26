#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> //ÓÃtree
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
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define mid ((l + r) >> 1)
const int MAXN = 2000010;
const int MOD = 1000000007;
const int INF = 1e15;
template <int MOD=998'244'353>
struct Modular {
    int value;
    static const int MOD_value = MOD;

    Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

    Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

    Modular& operator++() {++value; if(value == MOD) value = 0; return *this;}
#ifdef int long long
#undef int long long
    Modular operator++(int) {Modular res = *this; ++value; if(value == MOD) value = 0; return res;}
    Modular& operator--() {if(value == 0) value = MOD - 1; else --value; return *this;}
    Modular operator--(int) {Modular res = *this; if(value == 0) value = MOD - 1; else --value; return res;}
#define int long long
#else
    Modular operator++(int) {Modular res = *this; ++value; if(value == MOD) value = 0; return res;}
    Modular& operator--() {if(value == 0) value = MOD - 1; else --value; return *this;}
    Modular operator--(int) {Modular res = *this; if(value == 0) value = MOD - 1; else --value; return res;}
#endif
    friend Modular ksm(Modular a, long long e) {
        Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
        return res;
    }
    friend Modular inv(Modular a) { return ksm(a, MOD - 2); }

    Modular& operator/=(Modular const& b) { return *this *= inv(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
    friend std::istream& operator>>(std::istream& os, Modular& a) {os >> a.value; a.value %= MOD; if(a.value < 0) a.value += MOD; return os;}
    friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
    friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};
using M = Modular<>;
void solve(){
    M a = -1;
    cin >> a;
    ++a;
    cout << a;
    return;
}
signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while(_t--){
        solve();
    }
    return 0;
}
