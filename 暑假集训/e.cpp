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
int n;
void add1(int p){
	while(p <= n){
		a[p]++;
		p += (p & (-p));
	}
}
void add2(int p){
	while(p <= n){
		b[p]++;
		p += (p & (-p));
	}
}
void del1(int p){
	while(p <= n){
		a[p]--;
		p += (p & (-p));
	}
}
void del2(int p){
	while(p <= n){
		b[p]--;
		p += (p & (-p));
	}
}
int ask1(int p){
	int sum = 0;
	while(p){
		sum += a[p];
		p -= (p & (-p));
	}
	return sum;
}
int ask2(int p){
	int sum = 0;
	while(p){
		sum += b[p];
		p -= (p & (-p));
	}
	return sum;
}
int cnt1[MAXN], cnt2[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> n >> q;
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int x, y;
			cin >> x >> y;
			if(cnt1[x] == 0){
				add1(x);
			}
			if(cnt2[y] == 0){
				add2(y);
			}
			++cnt1[x];
			++cnt2[y];
		}
		else if(op == 2){
			int x, y;
			cin >> x >> y;
			--cnt1[x];
			--cnt2[y];
			if(cnt1[x] == 0){
				del1(x);
			}
			if(cnt2[y] == 0){
				del2(y);
			}
		}
		else{
			int x0, x1, y0, y1;
			cin >> x0 >> y0 >> x1 >> y1;
			if(ask1(x1) - ask1(x0 - 1) == (x1 - x0 + 1) || ask2(y1) - ask2(y0 - 1) == (y1 - y0 + 1)){
				cout << "Yes" << endl;
			}
			else cout << "No" << endl;
		}
	}
	
    return 0;
}
