
//试题编号：	201812-1
//试题名称：	小明上学

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int r,y,g;

int main()
{
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	scanf("%d %d %d",&r,&y,&g);
	int n;
	scanf("%d",&n);
	int ans = 0;
	for(int i=0;i<n;i++){
		int k,t;
		scanf("%d %d",&k,&t);
		if(k == 0){
			ans += t;
		} else if(k == 3){
			continue;
		} else if(k == 1){
			ans += t;
		} else if(k == 2){
			ans += t + r;
		}
	}
	printf("%d\n",ans);
	return 0;
}
