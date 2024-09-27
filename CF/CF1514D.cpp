#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
//#include<unordered_map>
#include<chrono>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls tree[p].l
#define rs tree[p].r
#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;
const int MAXN = 300010;
int a[MAXN];
struct node{
	int cnt;
	int l, r;
}tree[MAXN * 20];
int endd = 0;
int clone(int p){
	++endd;
	tree[endd] = tree[p];
	return endd;
}
int modify(int p, int l, int r, int x, int w){
	p = clone(p);
		tree[p].cnt += w;
	if(l == r) return p;
	if(x <= mid) ls = modify(ls, l, mid, x, w);
	else rs = modify(rs, mid + 1, r, x, w);
	return p;
}
int query(int p1, int p2, int l, int r){
	if(l == r) return tree[p2].cnt - tree[p1].cnt;
	int cntl = tree[tree[p2].l].cnt - tree[tree[p1].l].cnt, cntr = tree[tree[p2].r].cnt - tree[tree[p1].r].cnt;
	if(cntl > cntr) return query(tree[p1].l, tree[p2].l, l, mid);
	else return query(tree[p1].r, tree[p2].r, mid + 1, r);
}
int rt[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n){
			rt[i] = modify(rt[i - 1], 1, n, a[i], 1);
		}
		while(q--){
			int x, y;
			cin >> x >> y;
			int len = (y - x + 1);
			int cnt = query(rt[x - 1], rt[y], 1, n);
			if(cnt <= (len + 1) / 2) cout << 1 << endl;
			else cout << cnt * 2 - len << endl;
		}
	}
	return 0;
}
