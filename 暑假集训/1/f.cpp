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
int h[MAXN];
int mxl[MAXN], mxr[MAXN], mnl[MAXN], mnr[MAXN];
int cnt[MAXN];
stack<int> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n) cin >> h[i];
	rep(i, 1, n){
		mxr[i] = mnr[i] = n + 1;
		mxl[i] = mnl[i] = 0;
	}
	rep(i, 1, n){
		while(!q.empty() && h[q.top()] <= h[i]){
			mxr[q.top()] = i;
			q.pop();
		}
		q.push(i);
	}
	while(!q.empty()) q.pop();
	drep(i, n, 1){
		while(!q.empty() && h[q.top()] < h[i]){
			mxl[q.top()] = i;
			q.pop();
		}
		q.push(i);
	}
	while(!q.empty()) q.pop();
	rep(i, 1, n){
		while(!q.empty() && h[q.top()] >= h[i]){
			mnr[q.top()] = i;
			q.pop();
		}
		q.push(i);
	}
	while(!q.empty()) q.pop();
	drep(i, n, 1){
		while(!q.empty() && h[q.top()] > h[i]){
			mnl[q.top()] = i;
			q.pop();
		}
		q.push(i);
	}
	ll mx = 0, mn = 0;
	rep(i, 1, n){
		mx += (ll)(mxr[i] - i) * (i - mxl[i]) * h[i];
		mn += (ll)(mnr[i] - i) * (i - mnl[i]) * h[i];
	}
	cout << mx - mn;
    return 0;
}
