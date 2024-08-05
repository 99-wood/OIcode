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
const int MAXN = 100020;
char str[MAXN];
int a[MAXN];
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		char s;
		scanf("%d %c", &n, &s);
		scanf("\n%s", str + 1);
		if(s == 'g'){
			printf("0\n");
			continue;
		}
		int t = 0x3f3f3f3f;
		drep(i, n, 1){
			if(str[i] == 'g'){
				t = 0;
			}
			a[i] = t;
			++t;
		}
		drep(i, n, 1){
			if(str[i] == 'g'){
				t = 0;
			}
			a[i] = min(t, a[i]);
			++t;
		}
		int ans = 0;
		rep(i, 1, n){
			if(str[i] == s) ans = max(ans, a[i]);
		}
		printf("%d\n", ans);
	}
    return 0;
}
