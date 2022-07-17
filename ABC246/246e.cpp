#include<queue>
#include<iostream>
#include<cstdio>
#include<vector>
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
#define P pair<int,int>
#define m_p(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define fi first
#define se second

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);

    int dx[2]={1,-1};
    int dy[2]={1,-1};
    int n;
    cin>>n;
    int ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    vector<vector<char>> g(n+1,vector<char>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    queue<P> q;
    q.push({ax,ay});
    vector<vector<int>> dist(n+1,vector<int>(n+1,INT_MAX));
    vector<vector<int>> v(n+1,vector<int>(n+1));
    v[ax][ay]=1;
    dist[ax][ay]=0;
    while(!q.empty()){
        auto u=q.front();q.pop();
        v[u.fi][u.se]=1;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                int x=dx[i]+u.fi,y=dy[j]+u.se;
                if(x>=n||y>=n||x<1||y<1||g[x][y]=='#'||v[x][y])continue;
                dist[x][y]= min(dist[x][y],dist[u.fi][u.se]+1);
                if(x==bx&&y==by) break;
                q.push({x,y});
            }
        }
    }
    if(dist[bx][by]==INT_MAX){
        cout<<-1<<endl;return 0;
    }
    cout<<dist[bx][by]<<endl;
    return 0;
}   