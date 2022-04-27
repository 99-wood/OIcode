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
        _push(i, a[i]);
    }
    while (k--) {
        int a;
        ll b, c;
        scanf("%d%lld%lld", &a, &b, &c);
        if (a == 1) {
            _push(b, c);
        } else {
            printf("%lld\n", sum(c) - sum(b - 1));
        }
    }
    return 0;
}
