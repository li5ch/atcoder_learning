#include<bits/stdc++.h>
using namespace std;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i <=_##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#define L(i, j, k) for(int i = (j); i <(k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define pii pair<int,int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))

#define m_p(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define fi first
#define se second
#define mod 998244353
#define MAX 2005
int dp[MAX][MAX][2];
inline int rd(){
    register int x(0),f(1);register char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
inline void write(int X)
{
	if(X<0) {X=~(X-1); putchar('-');}
	if(X>9) write(X/10);
	putchar(X%10+'0');
}

int main(){
	
	freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);
    int n,m,k,s,t,x;
    cin>>n>>m>>k>>s>>t>>x;
    vector<pii> e(m+1);

    for(auto& [u,v]:e){
        cin>>u>>v;
        
    }
    dp[0][s][0]=1;
    FOR(i,1,k){
        for(auto [u,v]:e){
            dp[i][u][u==x]+=dp[i-1][]
        }
    }

    return 0;
}