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
//#define ls tree[p].l
//#define rs tree[p].r
//#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int len = s.length();
		bool flag = true;
		cout << s[0];
		frep(i, 1, len){
			if(s[i] == s[i - 1] && flag){
				cout << char((s[i] - 'a' + 1) % 26 + 'a');
				flag = false;
			}
			cout << s[i];
		}
		if(flag){
			cout << char((s[len - 1] - 'a' + 1) % 26 + 'a');
		}
		cout << endl;
	}
	return 0;
}
