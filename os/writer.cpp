#include<bits/stdc++.h>
using namespace std;

int main(){
	ofstream of("sample.txt");
	of<<"final text updated by the writer";
	of.close();
	ifstream fr("sample.txt");
	string s;
	while(fr>>s)cout<<s<<endl;
	fr.close();
	return 0;
}