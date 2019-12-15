
#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 0;
const int maxn = 1e3 + 2;
int a[maxn];
int mm[maxn];

int main()
{
	freopen("C:\\Users\\Administrator\\Desktop\\input.txt","r",stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\output.txt","w",stdout);
	int n;
	int aCnt = 0;
	scanf("%d",&n);
	int sum = 0;
	for(int i=1;i<=n;i++){
		int x,y,fir;
		scanf("%d %d",&x,&fir);
		int cnt = 0;
		for(int j=2;j<=x;j++){
			scanf("%d",&y);
			if(y <= 0){
				cnt -= y;
				fir += y;
			} else {
				cnt += fir - y;
				if(fir-y > 0){
					a[i] = 1;
				}
				fir = y;
			}
		}
		sum += fir;
		//printf("%d\n",fir);
		if(a[i] == 1){
			aCnt++;
		}
	}
	
	int ans = 0;
	if(a[n]==1 && a[n-1]==1){
		mm[1] = 2 + a[1];
	} else if(a[n-1] == 1){
		mm[1] = 1 + a[1];
	}
	if(mm[1] == 3) ans++;
	for(int i=2;i<=n;i++){
		if(a[i] == 1){
			mm[i] = mm[i-1] + 1;
			if(mm[i] > 3){
				mm[i] = 3;
			}
		} else {
			mm[i] = 0;
		}
		if(mm[i] == 3){
			ans++;
		}
	}
	printf("%d %d %d",sum,aCnt,ans);
	return 0;
}


/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0

5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
*/



