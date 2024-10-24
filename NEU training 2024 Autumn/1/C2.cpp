//#pragma GCC optimize(3, "Ofast", "inline")
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
//#include<numeric>
//#include<random>
//#include<unordered_map>
//#include<chrono>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define int long long 
using namespace std;
typedef long long ll;
const int MAXN = 200010;
int n;
string s;
struct node{
	int id, l, r, t;
}que[MAXN];
bool vis[MAXN];
int ans[MAXN];
pair<int,int> dis[MAXN];
bool enable(int p){
	return 1 <= p && p <= n && !vis[p];
}
int c[MAXN];
void add(int p){
	while(p <= n){
		c[p]++;
		p += (p & (-p));
	}
	return;
}
int ask(int p){
	int ans = 0;
	while(p){
		ans += c[p];
		p -= (p & (-p));
	}
	return ans;
}
bool cmp(const node &a,const node &b){
	return a.t<b.t;
}
void solve(){
	cin >> s;
	s = " " + s;
	n = s.size() - 1;
	int m;
	cin>>m;
	fill(c+1,c+1+n,0);
	for(int i=1;i<=m;i++) {
		cin>>que[i].t>>que[i].l>>que[i].r;
		que[i].id=i;
	}
	sort(que+1,que+1+m,cmp);
	int idx=-1;
	for(int i=1;i<=n;i++){
		dis[i].first=1e15;
		dis[i].second=i;
		if(s[i]=='1') {
			idx=i;
			dis[i].first=0;
		}
		else if(idx!=-1){
			dis[i].first=i-idx+1;
		}
	}
	idx=-1;
	for(int i=n;i>=1;i--){
		if(s[i]=='1'){
			idx=i;
		}
		else if(idx!=-1){
			dis[i].first=min(dis[i].first,idx-i+1);
		}
	}
	sort(dis+1,dis+1+n);
	for(int i=1,j=1;i<=m;i++){
		auto [id,l,r,t]=que[i];
		while(j<=n && dis[j].first<=t) {
			add(dis[j].second);
			j++;
		}
		ans[id]=ask(r)-ask(l-1);
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
