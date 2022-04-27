#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define ll long long
using namespace std;
int n, k;
ll a[1000010];
ll c[1000010];
void _push(int p, ll w) {
    while (p <= n) {
        c[p] += w;
        p += p & -p;
    }
    return;
}
ll sum(int p) {
    long long ans = 0;
    while (p >= 1) {
        ans += c[p];
        p -= p & -p;
    }
    return ans;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        _push(i, a[i] - a[i - 1]);
    }
    while (k--) {
        int a, l, r;
        ll x;
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%lld", &l, &r, &x);
            _push(l, x);
            _push(r + 1, -x);
        } else {
            scanf("%d", &l);
            printf("%lld\n", sum(l));
        }
    }
    return 0;
}
