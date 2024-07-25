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
int a[MAXN], b[MAXN];
int len(int a){
	return floor(log10(a)) + 1;
}
int ton[20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	rep(i, 1, 1000){
//		cout << i << " " << log10(i) << endl;
//
//	}
	int t;
	cin >> t;
	while(t--){
		memset(ton, 0, sizeof(ton));
		int n;
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) cin >> b[i];
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		int p1 = n, p2 = n;
		int cnt = 0;
		while(p1 && p2){
			if(a[p1] == b[p2]){
				--p1; --p2;
			}
			else if(a[p1] > b[p2]){
				if(a[p1] >= 10) ton[len(a[p1])]++, ++cnt;
				else ton[a[p1]]++;
				--p1;
			}
			else{
				if(b[p2] >= 10) ton[len(b[p2])]--, ++cnt;
				else ton[b[p2]]--;
				--p2;
			}
		}
		while(p1){
			if(a[p1] >= 10) ton[len(a[p1])]++, ++cnt;
				else ton[a[p1]]++;
				--p1;
		}
		while(p2){
			if(b[p2] >= 10) ton[len(b[p2])]--, ++cnt;
				else ton[b[p2]]--;
				--p2;
		}
		rep(i, 2, 9) cnt += abs(ton[i]);
		cout << cnt << endl;;
	}
    return 0;
}
