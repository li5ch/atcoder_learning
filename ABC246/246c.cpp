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
ll n, k, x,m,ans;
ll a[200005];
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);

    cin>>n>>k>>x;
    FOR(i,1,n) {
        cin>>a[i];
        ans+=a[i];
    }

    FOR(i,1,n){
        m+=a[i]/x;
        a[i]%=x;
    }
    m=min(k,m);
    ans-=m*x;k-=m;
    sort(a+1,a+1+n);

    for(int i=n;i>=1;i--){
        if(k==0)break;
        ans-=a[i],k--;
    }
    cout<<ans<<endl;
    
    return 0;
}   