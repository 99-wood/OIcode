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
const int MAXN = 1000010;
char str[MAXN];
int z[MAXN];
int main(){
//	freopen("P2909_2.in", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	while(scanf("\n%s", str) != EOF){
		z[0] = 0;
		int l = 0, r = 0;
		int len = strlen(str);
		frep(i, 1, len){
			if(r >= i){
				int p = i - l;
				if(z[p] < (r - i + 1)) z[i] = z[p];
				else{
					z[i] = (r - i + 1);
					while(i + z[i] < len && str[z[i]] == str[i + z[i]]) ++z[i];
				}
			}
			else{
				int k = 0;
				while(i + k < len && str[k] == str[i + k]) ++k;
				z[i] = k;
			}
			if(z[i] + i - 1 > r){
				r = z[i] + i - 1;
				l = i;
			}
		}
		drep(i, len - 1, 1){
			if(z[i] == (len - i)){
				printf("%d ", len - i);
			}
		}
		printf("%d\n", len);
	}
    return 0;
}
