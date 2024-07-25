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
#define ls tree[p].l
#define rs tree[p].r
#define mid ((l + r) >> 1)
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
const int MAXN = 2000010;
int a[MAXN];
deque<int> q;
int ans[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n){
		while(!q.empty() && q.front() < i - m + 1) q.pop_front();
		while(!q.empty() && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
		ans[i] = a[q.front()];
	}
	rep(i, m, n) cout << ans[i] << endl;
    return 0;
}
