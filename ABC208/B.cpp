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
	
	freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	

	return 0;	
} 