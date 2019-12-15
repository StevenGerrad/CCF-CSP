
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 2e3 + 2;
int mapp[maxn][maxn];
struct Edge{
	int v,u;
};
vector<int> vec;
vector<int> edg[maxn];
bool vis[maxn];

int zu[maxn];

int ans;
int n,m,k;

void calMap(int x,int y){
	queue<int> q;
	q.push(x);
	memset(vis,0,sizeof(vis));
	vis[x] = 1;
	printf("1 ");
	while(!q.empty()){
		int f = q.front();
		q.pop();
		//vis[f] = 1;
		for(int i=0;i<edg[f].size();i++){
			int t = edg[f][i];
			if(vis[t] == 1) continue;
			printf("%d ",t);
			mapp[x][t] = mapp[x][f] + mapp[f][t];
			mapp[t][x] = mapp[x][t];
			//if(t == y) return;
			q.push(t);
			vis[t] = 1;
		}
	}
}

int tempZu[maxn];

void calDis(){
	int cnt = 0;
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			cnt += mapp[tempZu[i]][tempZu[j]];
		}
	}
	if(cnt < ans) ans = cnt;
}

void calZu(int p,int c){
	if(c == k){
		calDis();
		return;
	}
	if(m-p+1 == k-c){
		for(int i=c+1;i<=k;i++) tempZu[i] = zu[p++];
		calDis();
		return;
	}
	tempZu[c+1] = zu[p];
	calZu(p+1,c+1);
	calZu(p+1,c);
}

int main()
{
	freopen("C:\\Users\\Administrator\\Desktop\\input.txt","r",stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\output.txt","w",stdout);
	
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x; scanf("%d",&x);
		zu[i] = x;
	}
	for(int i=1;i<n;i++){
		int x,y,z; scanf("%d %d %d",&x,&y,&z);
		mapp[x][y] = mapp[y][x] = z;
		edg[x].push_back(y);
		edg[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		for(int j=j+1;j<=n;j++){
			if(mapp[i][j] == 0){
				calMap(i, j);
			}
		}
	}
	ans = INF;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",mapp[i][j]);
		}
		printf("\n");
	}
	
	calZu(1,0);
	printf("%d",ans);
	return 0;
}

