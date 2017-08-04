#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long int LL;
typedef V<int> vi;
typedef V<LL> vl;
typedef V<pair<int ,int>> vpii;

#define rep(i,a) for(int i = 0; i<a ; i++)
#define fov(i,v) rep(i,v.size())
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++) 
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#define el cout<<endl

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();

int main(){
	int t; cin>>t;
	while(t--){
		string s;
		cin>>s;
		map<string,int> mp;
		for(int i = 0; i<s.size() ; i++){
			for(int j = i; j<s.size();j++){
				string sub = s.substr(i,j-i+1);
				//cout<<sub<<" -->";
				sort(sub.begin(),sub.end());
			//	cout<<sub; el;
				if(mp.count(sub)==0){
					mp[sub] = 1;
				}else{
					mp[sub]++;
				}
			}
		}
		LL ans = 0;
		map<string,int>::iterator it;
		for(it = mp.begin(); it!=mp.end(); it++){
			int num = it->sc;
			//cout<<it->fs<<" "<<it->sc; el;
			ans+=((num)*(num-1))/2;
		}
		cout<<ans; el;
	}	
	return 0;
}
