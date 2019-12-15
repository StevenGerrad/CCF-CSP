
/*
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e3 + 2;
const int maxm = 4e4 + 2;
char str[maxn][maxm];
bool vis[maxn];
int rest[maxn]; 
int n,s,l;


//void printWord(int local, int disk){
//	// ע��intռ��4���ֽڣ���32��������λ 
////	printf("local: %d, disk: %d\n",local,disk);
//	for(int i=0;i<8;i++){
//		char c = str[0][local+i];
//		int r = c<='9' ?  c-'0' : c-'A'+10;
////		printf("\n----------i :%d\n",i);
//		int res = r;
////		printf("res: %d\n",res);
//		// ����Ҫ���г�ʼ�����߼���������ظ��ٽ���һ�μ���(���������߼�) 
//		for(int j=1;j<n;j++){
//			char ct = str[j][local+i];
//			int rt = ct<='9' ?  ct-'0' : ct-'A'+10;
//			res ^= rt;
////			printf("rt: %d, res: %d\n",rt,res);
//			if(j == disk) {
//				res ^= rt;
////				printf("rt: %d, res: %d\n",rt,res);
//			}
//		}
//		if(disk == 0) {
//			res ^= r;
////			printf("r: %d, res: %d\n",r,res);
//		}
//		res = (res%16+16)%16;
////		printf("res: %d\n",res);
//		if(res <= 9){
//			c = '0';
//			cout<<char(res+c);
//		} else {
//			c = 'A';
//			cout<<char(res-10+c);
//		}
//	}
//	printf("\n");
//}

void printEight(int ans,int t){
	int res = (ans&15);
	ans >>= 4;
	char c;
	if(t < 7) printEight(ans, t+1);
	if(res <= 9){
		c = '0';
		cout<<char(res+c);
	} else {
		c = 'A';
		cout<<char(res-10+c);
	}
}

void printWord(int local, int disk){
	// ע��intռ��4���ֽڣ���32��������λ 
	memset(rest,0,sizeof(rest));
	for(int j=0;j<8;j++){
		char c = str[0][local+j];
		int res = c<='9' ?  c-'0' : c-'A'+10;
		rest[0] <<= 4;
		rest[0] |= res;
	}
	int ans = rest[0];
	for(int i=1;i<n;i++){
		if(disk == i) continue;
		for(int j=0;j<8;j++){
			char c = str[i][local+j];
			int res = c<='9' ?  c-'0' : c-'A'+10;
			rest[i] <<= 4;
			rest[i] |= res;
		}
//		printf("res: %d\n",rest[i]);
		ans ^= rest[i];
//		if(disk == i) ans ^= rest[i];
//		printf("ans_%d: %d\n",i,ans);
	}
	if(disk == 0) ans ^= rest[0];
	printEight(ans, 0);
	printf("\n");
}

int main() {
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	
	scanf("%d %d %d",&n,&s,&l);
	for(int i=0;i<l;i++){
		int ptr;
		scanf("%d",&ptr);
		vis[ptr] = 1;
		scanf("%s",str[ptr]);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int b;
		scanf("%d",&b);
		// �ж�����������ĸ�Ӳ�̵���һ��
		// �������� b/(s*(n-1))
		// �������е���ʼ�� (n-1)-(b/(s*(n-1))%n) 
		// �������̺�
		int disk = ((b%(s*(n-1)))/s + (n-1)-(b/(s*(n-1))%n) + 1) % n;
		// �������̵��ֽ���ʼλ��
		int local = (b/(n-1)/s)*s + b%s;
//		printf("����%d_������ʼ��%d_���̺�%d_�ֽ���ʼλ��%d\n",b/(s*(n-1)), (n-1)-(b/(s*(n-1))%n), disk, local);
		if(vis[disk] == 1){
			for(int i=0;i<8;i++){
				cout<<str[disk][i+local*8];
			}
			cout<<endl;
		} else {
			if(n-l >= 2){
				printf("-\n");
			} else {
				printWord(local*8, disk);
			}
		}
	}
	return 0;
}

*/


// ���Ӷ�̫����...
// �ð���ʵӦ�ò����Ǹ��Ӷȵ����� 


// Sample

//2 1 2
//0 000102030405060710111213141516172021222324252627
//1 000102030405060710111213141516172021222324252627
//2
//0
//1

//3 2 2
//0 000102030405060710111213141516172021222324252627
//1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7B0B1B2B3B4B5B6B7
//2
//2
//5



// 2019.9.4
// https://blog.csdn.net/ertcmmy/article/details/96875015

// ע��Ҫʹ�� sync_with_stdio(false) ��������cin,cout�Ļ���ᳬʱ 

#include <iostream>
#include <ios>
#include <cstdio>
#include <cstring>
#include <string>
#define maxn 1010
using namespace std;

string disk[maxn];

inline char getc(char n){
	if(n <= 9) return n+'0';
	else return n-10+'A';
}

inline char getn(char ch){
	if(ch<='9') return ch-'0';
	else return ch-'A'+10;
}

inline void _xor(string &s1, string s2){
	for(int i=0;i<8;i++){
		s1[i] = getc(getn(s1[i]) ^ getn(s2[i]));
	}
}

int main()
{
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\input.txt","r",stdin);
	freopen("D:\\auxiliaryPlane\\project\\scuCode\\output.txt","w",stdout);
	ios::sync_with_stdio(false);
	
//	for(char i=0;i<16;i++){
//		for(char j=0;j<16;j++){
//			cout<<(i^j)<<' '; 
//		}
//		cout<<endl;
//	} 
	
	int n,s,l;
	cin>>n>>s>>l;
	int size_s = 8*s; // ������С 
	int block_cnt = 0;
	
	for(int i=0;i<l;i++){
		int cur_d;
		cin>>cur_d;
		cin>>disk[cur_d];
		if(i == 0){
			block_cnt = disk[cur_d].length();
		}
	} 
	
	block_cnt *= n-1;
	block_cnt /= 8;
	
	int m; // ������
	cin>>m;
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		int b = a/s, d = a-b*s;
		int k = b/(n-1);
		int p = n - 1 - k%n;
		int c = (p+1+b-k*(n-1))%n;
		int beg = k*size_s + 8*d;  	// �ַ���ʼλ�� 
		if(a >= block_cnt){
			cout<<"-"<<endl;
		} else if(disk[c].length() != 0){
			cout<<disk[c].substr(beg, 8)<<endl;
		} else {
			// ��Ӳ�̲���������
			if(l < n-1){
				cout<<"-"<<endl;
			} else {
				string str = "00000000";		// o��wdnmdע��0�� 0�����0,0��1�����1 
				for(int i=(c+1)%n;i!=c;i=(i+1)%n){
//					cout<<str<<" "<<disk[i].substr(beg,8)<<endl;
					_xor(str, disk[i].substr(beg, 8));
//					cout<<str<<endl;
				}
				cout<<str<<endl;
			}
		}
	} 
	
	return 0;
}








