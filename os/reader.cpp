#include<bits/stdc++.h>
using namespace std;

int main(){
	ofstream of("sample.txt");
	of<<"this is initial text";
	of.close();

	ifstream fr("sample.txt");
	string s;
	fr>>s;
	cout<<s;
	int k;
	cin>>k;
	while(fr>>s)cout<<s<<endl;
	return 0;
}