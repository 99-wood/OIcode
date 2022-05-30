#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define ls tree[p].l
#define rs tree[p].r
#define mid ((l + r) >> 1)
using namespace std;
int read(){
    char c = getchar();
    bool b = false;
    while(c < '0' || c > '9'){
        if(c == '-') b = true;
        c = getchar();
    }
    int ans = 0;
    while(c >='0' && c <= '9'){
        ans = (ans << 3) + (ans << 1) + (c - '0');
        c = getchar();
    }
    return b ? -ans : ans;
}
const int MAXN = 1e5 + 10;
int n, m, k;
int root[MAXN];
int dfn[MAXN], top[MAXN], siz[MAXN], son[MAXN], fa[MAXN], end1;
vector<int> id[MAXN];
vector<int> nxt[MAXN];
int ask[MAXN];
vector<int> s[MAXN];
void dfs1(int p, int f){
    fa[p] = f;
    siz[p] = 1;
    int maxx = 0;
    frep(i, 0, nxt[p].size()){
        int x = nxt[p][i];
        if(x == fa[p]) continue;
        dfs1(x, p);
        if(siz[x] > maxx){
            maxx = siz[x];
            son[p] = x;
        }
        siz[p] += siz[x];
    }
    return;
}
void dfs2(int p){
    dfn[p] = ++end1;
    if(son[p]){
        top[son[p]] = p;
        dfs2(son[p]);
    }
    frep(i, 0, nxt[p].size()){
        int x = nxt[p][i];
        if(x == fa[p] || x == son[p]) continue;
        dfs2(x);
    }
    return;
}

struct node{
    int l, r, w;
};
struct node tree[MAXN * 25];
int end2;
void build(int p, int l, int r){
    if(l == r) return;
    ls = ++end2;
    rs = ++end2;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    return;
}
int clone(int p){
    tree[++end2] = tree[p];
    return end2;
}
int modify(int r1, int r2, int l, int r, int x, int y){
    if(tree[r1].w - tree[r2].w == 1) return r1;
    if(x <= l && r <= y){
        r1 = clone(r1);
        tree[r1].w = tree[r2].w + 1;
        return r1;
    }
    if(y < l || x > r) return 0;
    modify(tree[r1].l, tree[r2].l, l, mid, x, y);
    modify(tree[r1].r, tree[r2].r, mid + 1, r, x, y);
    return r1;
}
int main(){
    n = read(), m = read(), k = read();
    rep(i, 1, n - 1){
        int x = read(), y = read();
        id[x].push_back(i);
        nxt[i].push_back(y);
        id[y].push_back(i);
        nxt[y].push_back(x);
    }
    rep(i, 1, m){
        ask[i] = read();
    }
    rep(i, 1, m){
        rep(j, 0, ask[i]){
            s[i].push_back(read());
        }
    }
    dfs1(1, 0);
    dfs2(1);
    build(0, 1, n);
    return 0;
}