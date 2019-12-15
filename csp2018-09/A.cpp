
// ‘Ã‚±‡∫≈£∫	201809-1
// ‘Ã‚√˚≥∆£∫	¬Ù≤À

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 2;
int a[maxn];
int b[maxn];

int main()
{
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	b[1] = (a[1]+a[2]) / 2;
	b[n] = (a[n-1]+a[n]) / 2;
	for(int i=2;i<n;i++){
		b[i] = (a[i-1]+a[i]+a[i+1]) / 3;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	return 0;
}
