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
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
const int MAXN = 2000010;
ll tag[MAXN], sum[MAXN];
void pushdown(int p, int l, int r){
	if(tag[p] == -1) return;
	tag[ls] = tag[rs] = tag[p];
	tag[p] = -1;
	sum[ls] = tag[ls] * (mid - l + 1);
	sum[rs] = tag[rs] * (r - mid);
	return;
}
void modify(int p, int l, int r, int x, int y, ll w){
	if(x <= l && r <= y){
		tag[p] = w;
		sum[p] = w * (r - l + 1);
		return;
	}
	if(y < l || r < x) return;
	pushdown(p, l, r);
	modify(ls, l, mid, x, y, w);
	modify(rs, mid + 1, r, x, y, w);
	sum[p] = sum[ls] + sum[rs];
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(tag, -1, sizeof(tag));
	int n, m;
	cin >> n >> m;
	rep(i, 1, n){
		int a;
		cin >> a;
		modify(1, 1, n, i, i, a);
	}
	rep(i, 1, m){
		int op;
		cin >> op;
		if(op == 1){
			int p, w;
			cin >> p >> w;
			modify(1, 1, n, p, p, w);
		}
		else{
			int w;
			cin >> w;
			modify(1, 1, n, 1, n, w);
		}
		cout << sum[1] << endl;
	}
    return 0;
}
