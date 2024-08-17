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
#include<chrono>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define frep(i,a,b) for(int i=a;i<(b);++i)
#define drep(i,a,b) for(int i=a;i>=(b);--i)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;
//ll lcm = 1000000007;
const int MAXN = 1000010;
char str[MAXN];
int f[MAXN];
bool cmp(char a, char b){
	return (a == '(' && b == ')') || (a == '[' && b == ']');
}
int main(){
//	freopen("P2909_2.in", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	int ans = 0;
	rep(i, 1, n){
		if(str[i] == '(' || str[i] == '[') continue;
		if(cmp(str[i - f[i - 1] - 1], str[i])){
			f[i] = f[i - 1] + 2;
			f[i] = f[i - f[i]] + f[i];
		}
		if(f[i] > f[ans]) ans = i;
	}
	str[ans + 1] = '\0';
	printf("%s", str + ans - f[ans] + 1);
    return 0;
}
