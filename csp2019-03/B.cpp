
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>
using namespace std;

//const int maxn = 1e5;
//int a[maxn + 5];
char str[10];
stack<int> num;
stack<int> opera;

int main() {
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		for(int i=0;i<7;i++){
			if(str[i]>='0' && str[i]<='9'){
				num.push(str[i]-'0');
			} else {
				if(str[i] == '+'){
					opera.push(1);
				} else if(str[i] == '-'){
					num.push('0'-str[++i]);
					opera.push(1);
				} else if(str[i] == 'x'){
					int xx = num.top();
					num.pop();
					int yy = str[++i]-'0';
					num.push(xx*yy);					
				} else if(str[i] == '/'){
					int xx = num.top();
					num.pop();
					int yy = str[++i]-'0';
					num.push(xx/yy);
				}
			}
		}
		int res = num.top(); num.pop();
		while(!num.empty()){
			res += num.top();
			num.pop();
		}
		if(res == 24){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
