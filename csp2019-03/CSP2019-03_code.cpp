

//1	小中大	100.0	未提交		查看试题/答题

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
	//freopen("C:\Users\Administrator\Desktop\input.txt","r",stdin);
	//freopen("C:\Users\Administrator\Desktop\output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool upp = 1;
	if(a[n] < a[1]) upp = 0;
	double mid;
	if(n%2 == 0){
		mid = ((double)(a[n/2])+ (double)(a[n/2 + 1]))/2;
	} else {
		mid = a[(n+1)/2];
	}
	if(upp){
		if(int(mid*2)&1 == 1){
			printf("%d %.1lf %d",a[n],mid,a[1]);
		}
		else {
			printf("%d %.0lf %d",a[n],mid,a[1]);
		} 
	}else {
		if(int(mid*2)&1 == 1){
			printf("%d %.1lf %d",a[1],mid,a[n]);
		} else{
			printf("%d %.0lf %d",a[1],mid,a[n]);
		}
	}
	return 0;
}
*/

//2	二十四点	100.0	未提交		查看试题/答题

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

const int maxn = 10 + 5;
char str[maxn];
//int a[5];

int main() {
	//freopen("C:\input.txt","r",stdin);
	//freopen("C:\output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		int p = 0;
		//for(int i=0;i<7;i+=2) a[p++] = str[i] - '0';
		stack<int> S;
		queue<int> G;
		int top = 0;
		//printf("%d %d %d\n",'0','1','9');
		for(int i=0;i<7;i++){
			if(i%2 == 0){
				S.push(str[i] - '0');
			} else {
				if(str[i] == 'x'){
					int temp = S.top(); S.pop();
					temp *= str[++i] - '0';
					S.push(temp);
				} else if(str[i] == '/'){
					int temp = S.top(); S.pop();
					temp /= str[++i] - '0';
					S.push(temp);
				} else if(str[i] == '+'){
					if(i == 5 || str[i+2]=='+' || str[i+2]=='-'){
						if(!G.empty()){
							int yy = S.top(); S.pop();
							int xx = S.top(); S.pop();
							if(G.front() == 3){
								xx += yy;
							} else if(G.front() == 4){
								xx -= yy;
							}
							G.pop();
							S.push(xx);
							G.push(3);
						}
						else {
							G.push(3);
						}
					} else {
						G.push(3);
					}
				} else if(str[i] == '-'){
					if(i == 5 || str[i+2]=='+' || str[i+2]=='-'){
						if(!G.empty()){
							int yy = S.top(); S.pop();
							int xx = S.top(); S.pop();
							if(G.front() == 3){
								xx += yy;
							} else if(G.front() == 4){
								xx -= yy;
							}
							G.pop();
							S.push(xx);
							G.push(4);
						}
						else {
							G.push(4);
						}
					} else {
						G.push(4);
					}
				}
			}
		}
		while(!G.empty()){
			int yy = S.top(); S.pop();
			int xx = S.top(); S.pop();
			if(G.front() == 3){
				xx += yy;
			} else if(G.front() == 4){
				xx -= yy;
			}
			G.pop();
			S.push(xx);
		}
		//printf("%d\n",S.top());
		if(S.top() == 24) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
*/

//3	损坏的RAID5	100.0	未提交		查看试题/答题

/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e3 + 5;
const int maxp = 4e4 + 5;
bool have[maxn];
char str[maxp];

int main(){
	//printf("%d %d",1^1,1^0);
	int n,s,l;
	scanf("%d %d %d",&n,&s,&l);
	while(l--){
		int x;
		
	}
	return 0;
}
*/

//4	消息传递接口	100.0	未提交		查看试题/答题


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e4 + 5;
//char str[maxn][30];
char str[100];
//string str;
int p[maxn];
//int len[maxn];
int cmd[maxn][30], a[maxn][30];
int n;
//int a[5];

void println(){
	for(int i=0;i<n;i++){
		//printf("%d ",p[i]);
		if(p[i] <= cmd[i][0]){
			printf("1\n"); return ;
		}
	}
	printf("0\n");
	//return ;
}

int main() {
	int T;
	freopen("C:\\input.txt","r",stdin);
	//freopen("C:\output.txt","w",stdout);
	scanf("%d %d",&T,&n);
	//scanf("%d",&T);
	//scanf("%d",&n);
	//printf("%d %d\n",T,n);
	getchar();
	while(T--){
		//memset(p,0,sizeof(p));
		//memset(a,0,sizeof(a));
		//memset(cmd,0,sizeof(cmd));
		//printf("    0\n");
		//int lastP = 0;
		for(int i=0;i<n;i++) {
			//scanf("%s",str[i]);
			//len[i] = strlen(str[i]);
			//scanf("%s",str);
			//cin.getline(cin,30,str);
			
			/*
			int sp = 0;
			char ch;
			ch = getchar();
			while(ch != '\n'){
				str[sp++] = ch;
				//if(i == n-1 && !T) if(sp == lastP) break;
				ch = getchar();
			}
			str[sp] = '\0';
			*/
			gets(str);
			//getline(str);
			int len = strlen(str);
			//lastP = len;
			//int len = str.length();
			//printf("len: %d\n",len);
			//printf("%s\n",str);
			for(int j=0;j<=len;j++) a[i][j] = cmd[i][j] = 0;
			p[i] = 1;
			for(int j=0;j<len;j++){
				int ptr = j, x = 0;
				//printf("%d %d %d\n",j,i,T);
				while(str[++j] != ' ' && j != len){
					x = x*10 + str[j] - '0';
				}
				//printf("%d %d\n",x,j);
				if(x == i) continue;
				cmd[i][0]++;
				a[i][0]++;
				int t = a[i][0];
				a[i][t] = x;
				if(str[ptr] == 'S') cmd[i][t] = 1;
				else cmd[i][t] = 2;
			}
			//printf("4\n");
		}
		/*
		for(int i=0;i<n;i++){
			printf("%d %d\n",cmd[i][0],a[i][0]);
		}
		*/
		//printf("    1\n");
		int cnt = 0;
		while(cnt < n){
			int sum = 0;
			for(int i=0;i<n;i++){
				if(cmd[i][p[i]] == 2 || p[i] > cmd[i][0]) {
					//printf("%d %d\n",p[i],cmd[i][0]);
					sum++;
					continue; 
				}
				int w = a[i][p[i]];	
				if(p[w] > cmd[w][0]) continue;
				if(cmd[w][p[w]] == 2 && a[w][p[w]] == i) {
					p[w]++; p[i]++;
					//printf("%d %d\n",w,i);
					if(p[w] > cmd[w][0]) cnt++;
					if(p[i] > cmd[i][0]) cnt++;
				}
			}
			if(sum == n) break;
		}
		//printf("    2\n");
		println();
	}
	return 0;
}


/*
queue<int> S[maxn];
		queue<int> R[maxn];
		for(int i=0;i<n;i++){
			scanf("%s",str);
			int len = strlen(str);
			for(int j=0;j<len;j++){
				int p = j, x = 0;
				while(str[++j] != ' ' && j != len){
					x = x*10 + str[j] - '0';
				}
				if(str[p] == 'S') S[i].push(x);
				else R[i].push(x);
			}
		}


//5	317号子任务	100.0	未提交		查看试题/答题
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
//#include <algorithm>
using namespace std;

const int maxn = 1e4 + 5;
const int INF = 0x3f3f3f3f;
int is[maxn];
int mapp[maxn][maxn];
int dp[maxn][maxn];

int main(){
	//freopen("C:\\input.txt","r",stdin);
	//freopen("C:\\output.txt","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	printf("%d %d %d\n",n,m,k);
	//printf("1\n");
	memset(dp,INF,sizeof(dp));
	for(int i=1;i<=n;i++) {
		dp[i][i] = 0;
		scanf("%d",&is[i]);
	}
	memset(mapp,INF,sizeof(mapp));
	//printf("2\n");
	for(int i=1;i<=m;i++) {
		int x,y,d;
		scanf("%d %d %d",&x,&y,&d);
		if(x == y) continue;
		if(mapp[x][y] > d){
			mapp[x][y] = mapp[y][x] = d;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mapp[i][j] < INF) dp[i][j] = mapp[i][j];
		}
	}
	//printf("4\n");
	for(int s=1;s<=n;s++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = min(dp[i][j], dp[i][s] + dp[s][j]); 
			}
		}
	}
	//printf("5\n");
	for(int i=1;i<=n;i++){
		int ans = 0;
		//sort(dp[i]+1,dp[i]+n+1);
		priority_queue<int,vector<int>,greater<int> > G;
		for(int j=1;j<=n;j++){
			if(!is[j]) continue;
			if(dp[i][j] < INF) G.push(dp[i][j]);
		}
		for(int j=1;j<=k;j++){
			int temp = G.top(); G.pop();
			ans += temp;
			if(G.empty()) break;
		}
		printf("%d\n",ans);
	}
	//printf("6\n");
	return 0;
}

*/








