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
const int MAXN = 1000010;
ll js(ll m, ll n){
	if(n * n - 4 * m < 0) return -1;
	ll ans = (n + sqrt(n * n - 4 * m)) / 2;
	if(ans > 0 && n - ans > 0 && ans * (n - ans) == m) return ans;
	else return -1;
}
int n;
ll q[MAXN];
struct node{
	int w, t, l, r, siz;
}tree[MAXN];
int endd;
int add(int w){
	tree[endd].w = w;
	tree[endd].t = -1;
	tree[endd].l = tree[endd].r = -1;
	++endd;
	return endd - 1;
}
void del(){
	--endd;
}
int sum;
int pre[MAXN];
int id[MAXN];
int rt;
//map
bool dfs(int p, int pos, map<int, bool> &mp){
	if(p == 1){
		return true;
	}
	if(tree[pos].l == -1){
		if(mp[tree[pos].w]) return false;
		mp[tree[pos].w] = true;
		int a = js(tree[pos].w, q[p - 1] - (sum - tree[pos].w));
		if(a != -1){
			tree[pos].t = id[p];
			tree[pos].l = add(a);
			tree[pos].r = add(tree[pos].w / a);
			int tmp = sum;
			sum -= tree[pos].w;
			sum += a + tree[pos].w / a;
			map<int, bool> mpp;
			if(dfs(pre[p], rt, mpp)) return true;
			else{
				del(); del();
				tree[pos].t = -1;
				tree[pos].l = tree[pos].r = -1;
				sum = tmp;
				return false;
			}
		}
		return false;
	}
	else{
		if(dfs(p, tree[pos].l, mp)) return true;
		else if(dfs(p, tree[pos].r, mp)) return true;
		else return false;
	}
}
void print1(int p){
	if(tree[p].t == -1){
		tree[p].siz = 1;
		cout << tree[p].w << " ";
		return;
	}
	print1(tree[p].l);
	print1(tree[p].r);
	tree[p].siz = tree[tree[p].l].siz + tree[tree[p].r].siz;
	return;
}
int out[MAXN];
void print2(int p, int len){
	if(tree[p].t == -1){
		return;
	}
	out[tree[p].t] = len + tree[tree[p].l].siz;
	print2(tree[p].l, len);
	print2(tree[p].r, len + tree[tree[p].l].siz);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> q[i];
	int p = 1;
	int cnt = 0;
	pre[1] = -1;
	rep(i, 2, n){
		if(q[i] - q[i - 1] == -1){
			++cnt;
		}
		else{
			pre[i] = p;
			id[i] = id[p] + 1;
			p = i;
		}
	}
	int cnt_ = cnt;
	rep(i, 2, n){
		q[i - 1] -= cnt_;
		if(pre[i]) continue;
		else cnt_--;
	}
	bool flag = true;
	rep(i, 2, n){
		if(q[i] <= 0){
			cout << -1;
			return 0;
		}
	}
	rt = add(q[p]);
	sum = q[p];
	map<int, bool> mp;
	if(dfs(p, rt, mp)){
		print1(rt);
		rep(i, 1, cnt) cout << 1 << " ";
		cout << endl;
		print2(rt, 0);
		int last = n - 1;
		rep(i, 2, n){
			if(pre[i]){
				cout << out[id[i]] << endl;
			}
			else cout << (last--) << endl;
		}
	}
	else{
		cout << -1;
	}
	
    return 0;
}
