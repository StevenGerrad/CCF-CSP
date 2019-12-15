




//////////////////////////////////////////////////  A  //////////////////////////////////////////////////

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int r,y,g;

int main() {
	cin>>r>>y>>g;
	int n;
	cin>>n;
	int ans = 0;
	while(n--){
		int k,t;
		cin>>k>>t;
		if(k == 0 || k == 1) ans += t;
		else if(k == 3) continue;
		else if(k == 2) ans += t+r; 
	}
	cout<<ans;
	return 0;
}
*/


//////////////////////////////////////////////////  B  //////////////////////////////////////////////////
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

typedef long long LL;

LL r,y,g;
LL MOD;

int main() {
	cin>>r>>y>>g;
	MOD = r+y+g;
	int n;
	cin>>n;
	LL ans = 0;
	while(n--){
		int k;
		LL t;
		cin>>k>>t;
		if(k == 0) {
			ans += t;
			//cout<<t<<endl;
		}
		else if(k == 1) {
			LL temp = ans;
			temp -= t;
			temp %= MOD;
			if(temp <= 0) ans -= temp;
			else if(temp <= g) continue;
			else {
				ans += (r+y+g)-temp;
				//cout<<(r+y+g)-temp<<endl;
			}
		}
		else if(k == 2)  {
			LL temp = ans;
			temp -= t;
			temp %= MOD;
			if(temp <= r+g && temp > r) continue;
			else {
				ans += r-temp;
				//cout<<r-temp<<endl;
			}
		}
		else {
			LL temp = ans;
			temp -= t;
			temp %= MOD;
			if(temp <= 0 || temp > r+y) continue;
			else {
				ans += (r+y)-temp;
				//cout<<(r+y)-temp<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
*/

//////////////////////////////////////////////////  C  //////////////////////////////////////////////////


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b 
using namespace std;

const int MAXN = 1e5 + 5;
struct Node{
	int arr[34];
	int len;
}hero[MAXN];

char s[25];

void init(int num){
	int i;
	int bits = 7;
	int temp = 0;
	for(i=0;i<15;i++){
		if(s[i] != '.' && s[i] != '/' && s[i] != '\0') {
			temp = (s[i]-'0') + temp*10;
		}
		else {
			int b = 0;
			while(temp > 0){
				hero[num].arr[bits-b] = (temp&1);		//????????????????
				temp >>= 1;
				b++;
			}
			bits += 8;
			temp = 0; 
		}
		if(s[i] == '/' || s[i] == '\0') {
			break;
		}
	}
	if(s[i] == '/') {
		i++;
		while(s[i] != '\0') {
			temp = (s[i]-'0') + temp*10;
			i++;
		}
		hero[num].len = temp;
	}
	else {
		hero[num].len = bits+1-8;
	}
}

bool cmp(Node A,Node B){
	int wid = min(A.len,B.len);
	bool who = A.len < B.len;
	//if(A.len < B.len) swap(A, B);
	if(A.len <= B.len){
		for(int i=0;i<wid;i++){
			//if(A.arr[i] < B.arr[i]) return true;		//????????????????
			if(A.arr[i] != B.arr[i]) return false; 
		}
		return who;
	}
	else {
		for(int i=0;i<wid;i++){
			if(B.arr[i] != A.arr[i]) return false;		//????????????????
		}
		return who;
	}
}

bool canIn(Node A, Node B){
	int wid = min(A.len,B.len);
	for(int i=0;i<wid;i++){
		if(A.arr[i] != B.arr[i]) return false;
	}
	//return A.len < B.len;
	return true;
}

Node another[MAXN];
Node ans[MAXN];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		init(i);
		//for(int j=0;j<32;j++) cout<<hero[i].arr[j];
		//cout<<" "<<hero[i].len<<endl;
	}
	sort(hero,hero+n,cmp);
	int ptr = 0;
	another[0] = hero[0];
	for(int i=0;i<n;i++){
		if(canIn(another[ptr], hero[i])) continue;
		else {
			another[++ptr] = hero[i];
		}
	}
	/*
	for(int i=0;i<ptr+1;i++){
		for(int j=8;j<=32;j+=8){
			int temp = 0;
			for(int k=8;k>=1;k--) temp = temp*2 + another[i].arr[j-k];
			if(j!=32)printf("%d.",temp);
			else printf("%d/",temp);
		}
		printf("%d\n",another[i].len);
	}
	*/
	
	int pA = 0;
	for(int i=0;i<ptr;i++){
		if(another[i].len != another[i+1].len) {
			ans[pA++] = another[i]; 
			if(i == ptr-1) ans[pA++] = another[i+1];
			continue;
		}
		if(another[i].arr[another[i].len-1] == another[i-1].arr[another[i-1].len-1]) {
			ans[pA++] = another[i]; 
			if(i == ptr-1) ans[pA++] = another[i+1];
			continue;
		}
		bool yes=  true;
		for(int j=0;j<another[i].len-1;j++)
			if(another[i].arr[j] != another[i+1].arr[j]) yes = false;
		if(yes){
			another[i+1].len--;
			if(i != 0){
				another[i--] = ans[--pA];
				//i--;
			}
		}
		else {
			ans[pA++] = another[i]; 
			if(i == ptr-1) ans[pA++] = another[i+1];
			continue;
		}
	}
	
	for(int i=0;i<pA;i++){
		for(int j=8;j<=32;j+=8){
			int temp = 0;
			for(int k=8;k>=1;k--) temp = temp*2 + ans[i].arr[j-k];
			if(j!=32)printf("%d.",temp);
			else printf("%d/",temp);
		}
		printf("%d\n",ans[i].len);
	}
	
	return 0;
}


//////////////////////////////////////////////////  D  //////////////////////////////////////////////////

// 最小生成树
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 5e4 + 5;
int n,m,root;
int pa[MAXN];
struct ledge{
	int f, t;
	int dis;
}arr[10005];

int find(int x){
	return pa[x] == x ? x : pa[x] = find(pa[x]);
}

bool cmp(ledge A, ledge B){
	return A.dis < B.dis;
}

int main(){
	cin>>n>>m>>root;
	for(int i=0;i<=n;i++) pa[i] = i;
	for(int i=0;i<m;i++){
		int v,u,d;
		cin>>v>>u>>d;
		arr[i].f = v;
		arr[i].t = u;
		arr[i].dis = d;
	}
	sort(arr,arr+m,cmp);
	int ans;
	int cnt = 0;
	for(int i=0;i<m && cnt <= n-1;i++){
		int xx = find(arr[i].f);
		int yy = find(arr[i].t);
		if(xx == yy) continue;
		else {
			pa[yy] = pa[xx];
			ans = arr[i].dis;
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}
*/


//////////////////////////////////////////////////  E  //////////////////////////////////////////////////





