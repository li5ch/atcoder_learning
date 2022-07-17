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
ll n;
ll f(ll a,ll b){
    return (a+b)*(a*a+b*b);
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);

    cin>>n;
    ll l=0,r=1e6,ans=1e18;
    while(l<=r){
        while(f(l,r)>=n&&l<=r){
            ans=min(ans,f(l,r));
            r--;
        }
        l++;
    }
    cout<<ans<<endl;
    return 0;
}   