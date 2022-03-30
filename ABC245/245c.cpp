// #include <bits/stdc++.h>
#include <iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
//原先的std命名空间也不能省
using namespace std;

// using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i <=_##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#define L(i, j, k) for(int i = (j); i <(k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);
    int n,k;
    cin>>n>>k;
    vi a(n+1),b(n+1);
    vi dp1(n+1),dp2(n+1);
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) cin>>b[i];
    dp1[1]=dp2[1]=1;

    FOR(i,1,n-1){
        if(abs(a[i]-a[i+1])>k && abs(a[i]-b[i+1])>k&&
        abs(b[i]-a[i+1])>k&&abs(b[i]-b[i+1])>k){
            cout<<"No"<<endl;
            return 0;
        }
        if(abs(a[i+1]-a[i])<=k && dp1[i]){
            dp1[i+1]=1;
        }
        if(abs(a[i+1]-b[i])<=k&&dp2[i]){
            dp1[i+1]=1;
        }

        if(abs(b[i+1]-a[i])<=k && dp1[i]){
            dp2[i+1]=1;
        }
        if(abs(b[i+1]-b[i])<=k&&dp2[i]){
            dp2[i+1]=1;
        }
        

    }
    if(dp1[n]||dp2[n])
    cout<<"Yes"<<endl;
    else{
        cout<<"No"<<endl;
    }
    return 0;
}   