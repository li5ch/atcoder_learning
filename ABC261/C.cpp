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
// 题解：对于循环字符串，核心在于拼成两条，因为无论怎么循环，本质都是在2n的字符串上移动，这样就转为起始点st的更新，需要找到不变的点
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);
    int n;
    cin>>n;
    unordered_map<string,int> mp;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        cout<<s;
        if(mp.count(s)){
            cout<<"("<<mp[s]<<")";
        }
        cout<<endl;
        mp[s]++;
    }
    return 0;
}   