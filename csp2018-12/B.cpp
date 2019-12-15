
//试题编号：	201812-1
//试题名称：	小明上学

// 本题需注意数据范围 

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef long long LL;
int r,y,g;
int li;

inline int lantern(LL time){
	if(time < r){
		return r - time;
	} else if(time < r+g){
		return 0;
	} else {
		return li-time+r;
	}
}

int main()
{
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	scanf("%d %d %d",&r,&y,&g);
	int n;
	li = r + y + g;
	scanf("%d",&n);
	LL ans = 0;
	for(int i=0;i<n;i++){
		int k;
		LL t;
		scanf("%d %lld",&k,&t);
		if(k == 0){
			ans += t;
		} else if(k == 1){
			t = r - t;
			ans += lantern((ans+t)%li);
		} else if(k == 2){
			t = li - t;
			ans += lantern((ans+t)%li);
		} else if(k == 3){
			t = r + g - t;
			ans += lantern((ans+t)%li);
		} 
//		printf("%d: %d\n",i,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
