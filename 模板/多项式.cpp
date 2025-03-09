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
template <int MOD>
struct Modular {
    int value;
    static const int MOD_value = MOD;

    Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

    Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

    Modular& operator++() {++value; if(value == MOD) value = 0; return *this;}
    Modular& operator--() {if(value == 0) value = MOD - 1; else --value; return *this;}
#ifdef int long long
#undef int
    Modular operator++(int) {Modular res = *this; ++value; if(value == MOD) value = 0; return res;}
    Modular operator--(int) {Modular res = *this; if(value == 0) value = MOD - 1; else --value; return res;}
#define int long long
#else
    Modular operator++(int) {Modular res = *this; ++value; if(value == MOD) value = 0; return res;}
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
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define mid ((l + r) >> 1)
const int MAXN = 310;
const int MOD = 998244353;
const int INF = 1e16;
using M = Modular<MOD>;
namespace polynom{
    const int g = 3;
    using Poly = vector<M>;
    M ksm(M x, int k) {
        M ans = 1;
        while(k){
            if(k & 1) ans *= x;
            x *= x;
            k >>= 1;
        }
        return ans;
    }
    vector<int> rev;
    vector<M> rt;
    void init(int n) {
        rev.resize(n);
        rev[0] = 0;
        rep(i, 1, n) rev[i] = rev[i / 2] >> 1 | (i & 1 ? n >> 1 : 0);
        static int len = 1;
        if(len <= n){
            rt.resize(n + 1);
            while(len <= n){
                rt[len] = ksm(g, (MOD - 1) / len);
                len *= 2;
            }
        }
    }
    void ntt(Poly& f, int n) {
        f.resize(n);
        init(n);
        frep(i, 0, n) if(rev[i] < i) swap(f[i], f[rev[i]]);
        for(int len = 2; len <= n; len *= 2){
            for(int s = 0; s < n; s += len){
                M w = 1;
                frep(i, 0, len >> 1) {
                    M x = f[s + i], y = f[s + i + (len >> 1)];
                    f[s + i] = x + w * y;
                    f[s + i + (len >> 1)] = x - w * y;
                    w *= rt[len];
                }
            }
        }
    }
    void intt(Poly& f, int n) {
        f.resize(n);
        init(n);
        frep(i, 0, n) if(rev[i] < i) swap(f[i], f[rev[i]]);
        for(int len = 2; len <= n; len *= 2){
            M W = 1 / rt[len];
            for(int s = 0; s < n; s += len){
                M w = 1;
                frep(i, 0, len >> 1) {
                    M x = f[s + i], y = f[s + i + (len >> 1)];
                    f[s + i] = x + w * y;
                    f[s + i + (len >> 1)] = x - w * y;
                    w *= W;
                }
            }
        }
        M tmp = 1 / M(n);
        frep(i, 0, n) f[i] *= tmp;
    }
    Poly operator* (Poly f, Poly g) {
        int n = f.size() + g.size() - 1;
        int len = 1;
        while(len < n) len <<= 1;
        ntt(f, len);
        ntt(g, len);
        frep(i, 0, len) f[i] *= g[i];
        intt(f, len);
        f.resize(n);
        return f;
    }
}
using Poly = polynom::Poly;
using polynom::operator*;
void solve(){
    Poly f, g;
    int n, m;
    cin >> n >> m;
    f.resize(n + 1);
    g.resize(m + 1);
    rep(i, 0, n) cin >> f[i];
    rep(i, 0, m) cin >> g[i];
    Poly ans = f * g;
    rep(i, 0, n + m) cout << ans[i] << " ";
    return;
}
void init(){
    return;
}
signed main(){
    // int size(256<<20);  // 256M
    // __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while(_t--){
        solve();
    }
    return 0;
}
