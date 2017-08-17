#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long int LL;
typedef V<int> vi;
typedef V<LL> vl;
typedef V<pair<int ,int>> vpii;

#define rep(i,a) for(int i = 0; i<a ; i++)
#define fov(i,v) rep(i,v.size())
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#define el cout<<endl

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();

int main(){
	ifstream ir("words_sorted.txt");
	string str;
	V<string> v;
	while(ir>>str)v.push_back(str);
	fov(i,v){
		string s  = v[i];
		if(binary_search(v.begin(),v.end(),s))cout<<"exist"<<endl; else cout<<"not"<<endl;
	}	
	return 0;
}
