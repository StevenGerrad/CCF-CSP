
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5;
int a[maxn + 5];

int main(int argc, char** argv) {
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
//	sort(a,a+n);
	// 他已经保证有序 
	double mid = 0;
	if(n&1){
		mid = a[(n-1)/2];
	} else {
		mid = (a[(n-1)/2]+a[(n-1)/2+1]);
		mid /= 2;
	}
	if(a[n-1] < a[0]){
		swap(a[n-1], a[0]);
	}
	if((int)(mid*2)&1)
		printf("%d %.1lf %d",a[n-1],mid,a[0]);
	else 
		printf("%d %.0lf %d",a[n-1],mid,a[0]);
	return 0;
}
