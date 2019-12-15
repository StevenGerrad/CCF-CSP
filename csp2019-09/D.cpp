
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 3e4 + 2;
const int maxm = 50 + 2;

struct Node{
	int id,sc;
	bool operator < (const Node B) const {
		return sc == B.sc ? id > B.id : sc < B.sc;
	}
};
int a[maxm];
priority_queue<Node> q[maxm];
priority_queue<int,vector<int>,greater<int> > ch[maxm];
int m,n;

void erass(int num, int id){
	// can must find
	if(q[num].empty()){
		printf("erase erroe\n");
		return;
	}
	Node temp = q[num].top();
	q[num].pop();
	if(temp.id == id) return;
	else erass(num, id);
	q[num].push(temp);
};

void choos(int c,int K){
	if(c > K) return ;
	int ptr = 0; int score = -1;
	Node temp{INF,-1};
	//int cnt = 0;
	for(int i=1;i<=m;i++){
		if(a[i] == 0 || q[i].empty()) {
			//cnt ++;
			//printf("-----1 %d\n",i);
			continue;
		}
		if(q[i].top().sc > temp.sc){
			temp.id = q[i].top().id;
			temp.sc = q[i].top().sc;
			//printf("-----2--%d %d\n",temp.id,temp.sc);
			ptr = i;
		}
	}
	if(ptr == 0) return;
	ch[ptr].push(temp.id);
	//printf("chos: %d\n",temp.id);
	q[ptr].pop();
	a[ptr]--;
	choos(c+1,K);
	
	q[ptr].push(temp);
};

int main()
{
	freopen("C:\\Users\\Administrator\\Desktop\\input.txt","r",stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\output.txt","w",stdout);
	
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		for(int j=1;j<=m;j++){
			Node temp{x,y};
			q[j].push(temp);
		}
	}
	/*
	for(int j=1;j<=m;j++){
		printf("--%d %d\n",q[j].top().id,q[j].top().sc);
	}*/
	
	int op;
	scanf("%d",&op);
	//printf("before op\n");
	for(int i=1;i<=op;i++){
		int cao;
		scanf("%d",&cao);
		if(cao == 1){
			//printf("before 1\n");
			int x,y,z; scanf("%d %d %d",&x,&y,&z);
			x++;
			Node temp{y,z};
			q[x].push(temp);
		} else if(cao == 2){
			//printf("before 2\n");
			int x,y; scanf("%d %d",&x,&y);
			x++;
			erass(x, y);
		} else {
			//printf("before 3\n");
			int K;
			scanf("%d",&K);
			for(int j=1;j<=m;j++){
				scanf("%d",&a[j]);
			}
			choos(1,K);
			for(int j=1;j<=m;j++){
				if(ch[j].empty()){
					printf("-1\n");
					continue;
				}
				while(!ch[j].empty()){
					printf("%d ",ch[j].top());
					ch[j].pop();
				}
				printf("\n");
			}
		}
	}
	return 0;
}

/*
2 3
1 3
2 2
3 1
8
3 100 1 1
1 0 4 3
1 0 5 1
3 10 2 2
3 10 1 1
2 0 1
3 2 1 1
3 1 1 1
*/
