
////////////////////////////////////////////////////////////////////////////////////////////////// 
//
//		2019.12.15 string 
//
////////////////////////////////////////////////////////////////////////////////////////////////// 




//vector

//queue

//priority_queue

//stack

//string

//char

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector> 
using namespace std;

const int maxn = 100 + 2;
char str[maxn];
int acc[maxn];

int main(){
	/* scanf printf */
	int a;
	scanf("%d",&a);
	printf("%d",a);
	
	/* freopen */
	freopen("","r","stdin");
	freopen("","r","stdin");
	
	for(int i=0;i<100;i++)
		acc[i] = i;
	printf("\n");
	
	/* vector */
	printf("vector: \n")
	vector<int> b;
	for(int i=0;i<10;i++){
		b.push_back(i);
		printf("%d ",b.back());
		
	}
	printf("\n");
	while(!b.empty()){
		b.pop_back();
		printf("%d ", b.back());
	}
	printf("\n");
	
	/* queue */
	printf("queue: \n");
	queue<int> c;
	for(int i=0;i<10;i++){
		c.push(i);
		printf("%d ",c.back());
	}
	printf("\n");
	while(!c.empty()){
		printf("%d ",c.front());
		c.pop();
	}
	printf("\n");
	
	/* priority_queue */
	priority_queue<int, vector<int>, greater<int> > d1;
	priority_queue<int, vector<int>, less<int> > d2;
	
	/* char getchar(), getstring(),  */
	
	return 0;
}






////////////////////////////////////////////////////////////////////////////////////////////////// 
//
//		2019.12.15 dijstra 
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

/* 
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 0;
const int maxn = 1e3 + 2;
int a[maxn];


struct Edge{
	int from, to, dist;
	Edge(int f, int t, int d) :from(f), to(t), dist(d){}
};

struct Node{
	int d,u;
	Node(int d, int u) :d(d), u(u){}
	bool operator < (const Node& rhs) const {
		return d > rhs.d;
	}
};

struct Dijstra{
	int n,m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	
	void init(int n){
		this->n = n;
		for(int i=0;i<n;i++){
			G[i].clear();
		}
		edges.clear();
	}
	
	void AddEdge(int from, int to, int dist){
		edges.push_back(Edge(from, to ,dist));
		m = edges.size();
		G[from].push_back(m - 1);
	}
	
	void dijstra(int d[], int p[], int s){
		priority_queue<Node> Q;
		for(int i=0;i<n;i++)
			d[i] = INF;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push(Node(0, s));
		while(!Q.empty()){
			Node x = Q.top();
			Q.pop();
			int u = x.u;
			if(done[u])
				continue;
			done[u] = true;
			for(int i=0;i<G[u].size();i++){
				Edge& e = edges[G[u][i]];
				if(d[e.to] > d[u] + e.dist){
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push(Node(d[e.to], e.to)); 
				}
			}
			
		}
	}
}DJ;

int main(){
	
	return 0;
}


*/ 












