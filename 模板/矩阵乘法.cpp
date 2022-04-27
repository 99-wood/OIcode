#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define ll long long
using namespace std;
ll mod = 1e9 + 7;
ll a[510][510], b[510][510], ans[510][510];
int main() {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%lld", &a[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            scanf("%lld", &b[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                ll temp = a[i][k] * b[k][j];
                temp %= mod;
                ans[i][j] += temp;
                ans[i][j] %= mod;
            }
            if (ans[i][j] < 0)
                ans[i][j] = mod + ans[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            printf("%lld ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}