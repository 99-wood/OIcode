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
ll sum[1000010];
ll c1[1000010];
ll c2[1000010];
void add1(int p, ll w) {
    while (p <= n) {
        c1[p] += w;
        p += p & -p;
    }
    return;
}
ll ask1(int p) {
    long long ans = 0;
    while (p >= 1) {
        ans += c1[p];
        p -= p & -p;
    }
    return ans;
}
void add2(int p, ll w) {
    while (p <= n) {
        c2[p] += w;
        p += p & -p;
    }
    return;
}
ll ask2(int p) {
    long long ans = 0;
    while (p >= 1) {
        ans += c2[p];
        p -= p & -p;
    }
    return ans;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    while (k--) {
        int a, l, r;
        ll x;
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%lld", &l, &r, &x);
            add1(l, x);
            add1(r + 1, -x);
            add2(l, l * x);
            add2(r + 1, -(r + 1) * x);
        } else {
            scanf("%d%d", &l, &r);
            printf("%lld\n",
                   sum[r] + (r + 1) * ask1(r) - ask2(r) - (sum[l - 1] + l * ask1(l - 1) - ask2(l - 1)));
        }
    }
    return 0;
}
