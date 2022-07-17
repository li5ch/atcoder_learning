#include<queue>
#include<iostream>
#include<cstdio>
#include<vector>
#include <string>
#include <algorithm>
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
const int maxn = 1e5 + 7;
struct node
{
    int l,r,sum;
}T[maxn*50];
int n,m,cnt,a[maxn],root[maxn],x,y,k;
vector<int> v;
void update(int l, int r, int &x, int y, int pos) {
	T[++cnt] = T[y]; //先创造一个节点等于上一课线段树
	T[cnt].sum++; //这创造出来的树加上1  因为要包含新的点进来
	x = cnt; //root数组 保存下这棵树的头节点
	if (l ==  r) return; //已经到了根节点不用在进行创造了 
	int mid = (l + r) >> 1;
	if (pos <= mid) {
		//对左节点进行创造
		update(l, mid, T[x].l, T[y].l, pos);  //将y线段树的左节点传进去， 因为还要保存另外一个左（右）区间 
	} else {
		update(mid + 1, r, T[x].r, T[y].r, pos);
	}
}
int query(int l, int r, int x, int y, int k) {
	 if (r == k) {
 		return T[y].sum - T[x].sum;
	}
	int s = T[T[y].l].sum - T[T[x].l].sum;
	int mid = (l + r) >> 1;
	if (mid < k) {
		return s + query(mid + 1, r, T[x].r, T[y].r, k);
	} else {
		return query(l, mid, T[x].l, T[y].l, k);
	} 
}
int getId(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
} 

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d", a + i); //保存输入的值 
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
for (int i = 1; i <= n; i++) {
			//根据上一个树 来创造这次的线段树 root[i - 1]上一棵树的根节点 root[i]当前线段树的根节点 
			update(1, n, root[i], root[i - 1], getId(a[i]));
		} 

        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int l,r,k;
            cin>>l>>r>>k;
            int h = upper_bound(v.begin(), v.end(), k) - v.begin();
			if (h > 0) {
				printf("%d\n", query(1, n, root[x - 1], root[y], h)); //因为v数组是从0开始 
			} else {
				printf("0\n");
			} 
        }
    return 0;
}   