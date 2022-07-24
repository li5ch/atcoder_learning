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
#define DEBUG
ll n;
ll f(ll a,ll b){
    return (a+b)*(a*a+b*b);
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);
    #endif
    int n,x;
    cin>>n>>x;
    ll min_b=INT_MAX;
    ll ans = numeric_limits<ll>::max();
    ll s=0;
    vi a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        if(i>x) break;
        // min_b=min(min_b,(ll)b[i-1]);
        s+=a[i-1]+b[i-1];
         ans=min(ans,s+(ll)(x-i)*b[i-1]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}   