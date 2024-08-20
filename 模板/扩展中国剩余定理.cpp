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
using namespace std;
typedef long long ll;
//ll lcm = 1000000007;
const int MAXN = 1000010;
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}
struct node{
	ll r, a;
	node(ll r = 0, ll a = 0) : r(r), a(a){
	}
};
ll mul(ll a,ll b,ll p){
	b = (b % p + p) % p;
	ll ans=0,x=a;
	while(b!=0)
	{
		if(b&1)
		{
			ans=(ans+x)%p;
		}
		x=(x+x)%p;
		b>>=1;
	}
	return (ans%p+p)%p;
}
void exgcd(ll a, ll b, ll &x, ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return;
	}
	exgcd(b, a % b, x, y);
	ll tx = x, ty = y;
	x = ty;
	y = tx - (a / b) * ty;
	return;
}
node merge(node a, node b){
	ll g = gcd(a.a, b.a);
	ll l = lcm(a.a, b.a);
	ll x, y;
	exgcd(a.a / g, b.a / g, x, y);
	ll k1 = (a.r +  mul(mul(x % l, ((b.r - a.r) / g) % l, l), a.a, l) + l) % l;
	return node(k1, l);
}
int main(){
//	freopen("P2909_2.in", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin >> n;
	stack<node> s;
	while(n--){
		ll r, a;
		cin >> a >> r;
		s.push(node(r, a));
	}
	while(s.size() >= 2){
		node a, b;
		a = s.top();
		s.pop();
		b = s.top();
		s.pop();
		s.push(merge(a, b));
	}
	cout << s.top().r;
    return 0;
}
