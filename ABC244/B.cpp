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
int main(){
	
	freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);
	int n;
	cin>>n;
	int x=0; int y=0;
	int xi=1;int yi=0;
	FOR(i,1,n){
		char c;
		cin>>c;
		if(c=='S'){
			x+=xi;y+=yi;
			
		}else{
			swap(xi,yi);
			yi=-yi;
		}
	}
	cout<<x<<' '<<y<<endl;


	return 0;	
} 