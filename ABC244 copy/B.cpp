#include<bits/stdc++.h>
using namespace std;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i <=_##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#define L(i, j, k) for(int i = (j); i <(k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
inline int lowbit(int x){ return x&-x;}
const int MAXN = 500000;
int n;
int c[MAXN];
void add(int x, int v) {
	for(;x<=n;x+=lowbit(x)){
		c[x]+=v;
	}
} 
int sum(int x){
	int ret=0;
	for(;x;x-=lowbit(x)){
		ret+=c[x];
	}
	return ret;
}
int sum(int l, int r){
	return sum(r)-sum(l-1);
}
int main(){
	
	// freopen("in.txt", "r", stdin);
    // freopen("out.txt","w", stdout);
	int q;
	cin>>n>>q;
	vi a(n+1);
	FOR(i,1,n){
		cin>>a[i];
		c[i]+=a[i];
		int j= i+lowbit(i);
		if(j<=n)c[j]+=c[i];
	}

	FOR(i,1,q){
		int k,l,r;
		cin>>k>>l>>r;
		if(k){
			cout<<sum(l+1,r)<<endl;
		}else{
			add(l+1,r);
		}
	}

	return 0;	
} 