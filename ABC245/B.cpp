#include<bits/stdc++.h>
using namespace std;
int mex,vi[2010],n;
signed main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		vi[x]=1;
		while(vi[mex])mex++;
	}
	cout<<mex;
} 