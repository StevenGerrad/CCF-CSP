
// ÎÒÌ«ÄÑÁË


#include <iostream>
#include <cstdio>
#include <string>
using namespace std; 

struct IP{
	string ip="";
	int length = -1;
};

IP stringToIp(string &input){
	IP ip;
	string s = "";
	vector<int> pow2 = {1,2,4,8,16,32,64,128};
	for(int i=0;i<=input.size();i++){
		if(i == input.size() || )
	}
}

int main()
{
	int N;
	cin>>N;
	list<IP> ipAddress;
	while(N--){
		string input;
		cin>>input;
		ipAddress.push_back(stringToIp(input));
	}
	return 0;
}
