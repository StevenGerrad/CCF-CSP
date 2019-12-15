
// ‘Ã‚±‡∫≈£∫	201809-2
// ‘Ã‚√˚≥∆£∫	¬Ú≤À

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
	int l,r;
};
typedef long long LL;
const int maxn = 2e3 + 2;
//int a[maxn];
//int b[maxn];
Node a[maxn];
Node b[maxn];

int main()
{
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
//		int x,y;
		scanf("%d %d",&a[i].l,&a[i].r);
	}
	for(int i=0;i<n;i++){
		scanf("%d %d",&b[i].l,&b[i].r);
	}
	int at = 0, bt = 0;
	int ans = 0;
	while(at < n && bt < n){
		if(a[at].l <= b[bt].l){
			if(a[at].r <= b[bt].l){
				at++;
			} else if(a[at].r <= b[bt].r){
				ans += a[at].r - b[bt].l;
				b[bt].l = a[at].r;
				at++;
			} else {
				ans += b[bt].r - b[bt].l;
				a[at].l = b[bt].r;
				bt++;
			}
		} else {
			if(b[bt].r <= a[at].l){
				bt++;
			} else if(b[bt].r <= a[at].r){
				ans += b[bt].r - a[at].l;
				a[at].l = b[bt].r;
				bt++;
			} else {
				ans += a[at].r - a[at].l;
				b[bt].l = a[at].r;
				at++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}



