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
	string s;
	cin>>s;
	bool found = false;
	int count = 0;
	for(int i = 0;i<s.size();i++){
		if(s[i]=='1'){
			found = true;
		}
		if(s[i]=='0'&&found){
			count++;
		}
	}	
	if(count>=6){
		cout<<"yes";
	}else{
		cout<<"no";
	}
	return 0;
}
