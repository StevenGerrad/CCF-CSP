
// 求最小生成树中的最长边 

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define maxm 100000
#define maxn 50000 
using namespace std; 

struct Edge{
	int v,u,t;
	bool operator < (const Edge B) const {
		return t < B.t;
	}
}edg[maxm + 2];
int n,m,root;
int f[maxn];

int findd(int x){
	return f[x] == x ? x : f[x]=findd(f[x]);
	// 注意这个函数一定要书写准确，判断和重新赋值 
}
//
//int findd(int x){
//	if(f[x] == -1) return x;
//	return f[x] = findd(f[x]);
//}

int main()
{
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	scanf("%d %d %d",&n,&m,&root);
//	int v,u,t;
//	memset(f,-1,sizeof(f));
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&edg[i].v,&edg[i].u,&edg[i].t);
	}
	for(int i=0;i<=n;i++) f[i] = i;
	sort(edg,edg+m);
	int cnt = 0;
	int ptr = 0;
	int ans = 0;
	for(int i=0;i<m;i++){
		int xx = findd(edg[i].v);
		int yy = findd(edg[i].u);
		if(xx != yy){
			f[xx] = yy;	// 注意，此处的xx, yy 一定是处理过的 
			cnt++;
			ans = max(ans, edg[i].t);
//			ptr = i;
			if(cnt == n-1) break;
		}
	}
//	printf("%d",edg[ptr].t);
	printf("%d",ans);
	return 0;
}



