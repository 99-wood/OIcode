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
const int MAXN = 50;
char str[100] = "314159265358979323846264338327";
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--){
		char s[100];
		scanf("%s", s);
		int len = strlen(s);
		int ans = len;
		frep(i, 0, len){
			if(s[i] != str[i]){
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
//	cout << ans;
    return 0;
}
