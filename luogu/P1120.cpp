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
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls tree[p].l
#define rs tree[p].r
//#define mid ((l + r) >> 1)
typedef long long ll;
typedef unsigned long long ull;
#define Maxq priority_queue<int,vector<int>,greater<int> >
using namespace std;
const int MAXN = 210;
//int cnt;
int a[100];
bool used[MAXN];
int n, sum, expect;
int nxt[MAXN];
bool dfs(int p, int last, int need){
	if(p > sum / expect) 
		return true;
	int l = last + 1, r = n;
	int s = l + 1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(a[mid] > need){
			l = mid + 1;
		}
		else{
			r = mid - 1;
			s = mid;
		}
	}
	rep(i, s, n){
		if(used[i] || a[i] > need) continue;
		used[i] = true;
		bool flag = false;
		if(need == a[i]) flag = dfs(p + 1, 0, expect);
		else flag = dfs(p, i, need - a[i]);
		used[i] = false;
		if(flag) return true;
		else{
			if((need - a[i]) * 2 == expect) return false;
			if(need == expect || need - a[i] == 0) return false;
			i = nxt[i] - 1;
		}
	}
	return false;
}
bool cmp(int a, int b){
	return a > b;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	freopen("test.out", "w", stdout);
//	int n;
//	int sum = 0;
	while((cin >> n) && n){
		int mx = 0;
		rep(i, 1, n){
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		sum = 0;
		rep(i, 1, n) sum += a[i];
		sort(a + 1, a + n + 1, cmp);
		nxt[n] = n + 1;
		drep(i, n - 1, 1){
			if(a[i] == a[i + 1]) nxt[i] = nxt[i + 1];
			else nxt[i] = i + 1;
		}
		bool flag = false;
		rep(i, mx, sum / 2){
			if(sum % i == 0){
//				memset(ton, 0, sizeof(ton));
				expect = i;
				if(dfs(1, 0, i)){
					cout << i << endl;
					flag = true;
					break;
				}
			}
		}
		if(!flag) cout << sum << endl;
		break;
	}
    return 0;
}
