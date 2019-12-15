
// https://blog.csdn.net/weixin_42062229/article/details/99830143

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct Edges{
	int v,w;
	bool operator < (const Edges B) const {
		return w > B.w;		// 为什么要这样设置？ 
	}
};
const int INF = 0x3f3f3f3f;
int n,m,k;
int ff[10000 + 5];
priority_queue<int, vector<int>, greater<int> > d[10000];
vector<Edges> edge[10000];

void dijsktra(int mou){
	priority_queue<Edges> Q;
	int dis[10000];
//	memset(dis,INF,sizeof(dis));
	for(int i=0;i<n;i++) dis[i] = INF;
	dis[mou] = 0;
	Q.push((Edges){k,0});
	while(!Q.empty()){
		Edges f = Q.top();
		Q.pop();
		if(f.w != dis[f.v]) continue;
		d[f.v].push(f.w);
		int m = edge[f.v].size();
		int u,w;
		for(int i=0;i<m;i++){
			u = edge[f.v][i].v;
			w = edge[f.v][i].w;
			if(dis[u] > w + dis[f.v]) {
				dis[u] = w + dis[f.v];
				Q.push((Edges){u, dis[u]});
			}
		}
	}
}

int main()
{
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	
	scanf("%d %d %d",&n,&m,&k);
	int num = 0, x;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x) ff[num++] = i;
	}
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		u--; v--;
		edge[u].push_back((Edges){v,w});
		edge[v].push_back((Edges){u,w});
	}
	for(int i=0;i<num;i++) dijsktra(ff[i]);
	long long ans;
	
	for(int i=0;i<n;i++){
		int cnt = k;
		ans = 0;
		while(!d[i].empty() && cnt--){
			ans += d[i].top();
			d[i].pop();
		}
		printf("%lld\n",ans);
	}
	return 0;
}

//7 6 2
//1 0 1 0 1 1 0
//1 4 1
//1 2 3
//2 4 4
//2 3 5
//2 5 7
//6 7 5
