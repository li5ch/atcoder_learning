#include <bits/stdc++.h>
//原先的std命名空间也不能省
using namespace std;

// using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i <=_##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#define L(i, j, k) for(int i = (j); i <=(k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 

ll f(ll a,ll b){
    return (a+b)*(a*a+b*b);
}
#define M 5001
#define N 5001
ll Y[N];
ll X[N];
int n,m;
ll ans;
// 题解：dp，刚开始从dp入手但是发现跟常规转移方程对不上，实际上dp可以转移但是需要正确计算cnt=0的状态值，最后的最大值需要对cnt遍历一遍
void dfs(int i,ll t,int cnt){

    if(i==n){
        ans=max(ans,t);
        return;
    }
    dfs(i+1,t+X[i]+Y[cnt+1],cnt+1);
    dfs(i+1,t,0);
}
ll dp[M][N];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);
  
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>X[i];
    }
    for(int j=0;j<m;j++){
        int c,y;
        cin>>c>>y;
        Y[c]=y;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j)
            dp[i][j]=dp[i-1][j-1]+X[i-1]+Y[j];
        }
        for(int j=0;j<i;j++)
         dp[i][0]=max(dp[i][0],dp[i-1][j]);
    }
    for(int i=0;i<=n;i++){
        ans=max(ans,dp[n][i]);
    }
    
    cout<<ans<<endl;
    return 0;
}   