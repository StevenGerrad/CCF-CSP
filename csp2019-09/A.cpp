
#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 0;
const int maxn = 1e3 + 2;
int a[maxn];

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\input.txt","r",stdin);
	//freopen("C:\\Users\\Administrator\\Desktop\\output.txt","w",stdout);
	int n,m;
	int ptr = 1;
	int aMax = 0;
	scanf("%d %d",&n,&m);
	int sum = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int cnt = 0;
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			cnt -= x;
		}
		a[i] -= cnt;
		if(cnt > aMax){
			aMax = cnt;
			ptr = i;
		}
		sum += a[i];
	}
	printf("%d %d %d",sum,ptr,aMax);
	return 0;
}

