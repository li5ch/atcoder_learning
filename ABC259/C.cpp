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
	string s,t;
	cin>>s>>t;
	int i,j,u;
	int M=s.size(),N=t.size();
	for(i=j=0;i<M||j<N;i++,j++){
		if(s[i]==t[j])continue;
		if(i-2>=0&&s[i-2]==s[i-1]&&t[j]==s[i-1]){
			for(u=j;u<N&&t[j]==t[u];u++);
			j=u;
		}else{
			break;
		}
	}
	printf("%s", (i >= M && j >= N) ? "Yes" : "No");

	return 0;	
} 