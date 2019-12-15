
/*

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e4 + 2;
char str[100];
struct Node{
	bool sr;
	int num;
};
queue<Node> qu[maxn];

int main(){
//	printf("====");
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	int T,n;
//	printf("====");
	scanf("%d %d",&T,&n);
	printf("%d %d\n",T,n);
//	getchar();
	while(T--){
		for(int k=0;k<n;k++){
//			scanf("%s\n",str);
//			getline(cin,str);
//			gets(str);
			cin.getline(str,100,'\n');
			// 这种输入方式有问题 ,还是有问题！！！我尼玛。。。 
			printf("-----: %s\n",str);
			int len = strlen(str);
			printf("len: %d\n",len);
			for(int i=0;i<len;i++){
				Node temp;
				temp.sr = (str[i]=='R' ? 0 : 1);
				i++;
				int cnt = 0;
				while(str[i]!=' ' || str[i]!='\0'){
					cnt = cnt*10+str[i]-'0';
					i++;
				}
				i--;
				temp.num = cnt;
				if(cnt == k) continue;
				else qu[k].push(temp);
			}
		}
		bool ans = 0;
		while(true){
			int cntS = 0;
			int fini = 0;
			for(int i=0;i<T;i++){
				if(qu[i].empty()) {
					continue;
					fini++;
				}
				Node f = qu[i].front();
				if(f.sr){
					Node ft = qu[f.num].front();
					if(!ft.sr && ft.num == i){
						qu[i].pop();
						qu[f.num].pop();
						cntS++;
					}
				}
			}
			if(cntS == 0){
				if(fini < T){
				ans = 0; break;
				} else if(fini == T){
					ans = 1; break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

*/



#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

struct Node{
	int ind,t;
	Node(string &s,int &n){
		int temp = 0, i = 1;
		if(s[0]=='R') ind = 0;
		else ind = 1;
		while(s[i]){
			temp = temp*10 + (s[i++]-'0');
		}
		t = temp%n;
	}
};

const int maxn = 1e4 + 2;
//queue<Node> m;
queue<Node> qu[maxn];

int main()
{
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	int T,n;
	scanf("%d %d",&T,&n);
	string s;
	getchar();
	stringstream ss;
	while(T--){
		for(int i=0;i<n;i++){
			getline(cin, s);
			ss<<s;
			while(ss>>s){
				qu[i].push(Node(s,n));
			}
			ss.clear();
		}
		bool ans = 0;
//		for(int i=0;i<n;i++)
//			printf("%d ",qu[i].size());
//		printf("\n");

/*
		while(true){
			int cntS = 0;
			int fini = 0;
			for(int i=0;i<n;i++){		// wdnmd总是把T和n打错 
				if(qu[i].empty()) {
					fini++;
					continue;
				}
				Node f = qu[i].front();
//				printf("--1\n");
				if(f.ind == 1){
					Node ft = qu[f.t].front();
//					printf("--2\n");
					if(ft.ind==0 && ft.t == i){
//						printf("--3\n");
						qu[i].pop();
						qu[f.t].pop();
//						printf("S: %d, R: %d\n",i,f.t);
//						printf("size: %d__%d\n",qu[i].size(),qu[f.t].size());
						cntS++;
					}
				}
			}
//			printf("cntS: %d, fini: %d\n",cntS,fini);
			if(cntS == 0){
				if(fini < n){
					ans = 1; break;
				} else if(fini == n){
					ans = 0; break;
				}
			}
		}
		*/
		while(1){
            int t=0;
            for(int i=0;i<n;i++){
                if(qu[i].empty())continue;
                Node k=qu[i].front();
                if(qu[k.t].empty())break;
                Node h=qu[k.t].front();
                if((h.ind+k.ind)!=1)continue;
                if(h.t!=i)continue;
                qu[i].pop();
				qu[k.t].pop();
                t++;i--;
            }
            if(!t)break;
        }
        for(int i=0;i<n;i++){
            if(!qu[i].empty()) { ans=1; break; }
        }
		for(int i=0;i<n;i++){
			while(!qu[i].empty()) qu[i].pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}



//3 2
//R1 S1
//S0 R0
//R1 S1
//R0 S0
//R1 R1 R1 R1 S1 S1 S1 S1
//S0 S0 S0 S0 R0 R0 R0 R0







