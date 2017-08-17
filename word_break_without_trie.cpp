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
int n;
bool check(string dict[],string s){
    for(int i = 0;i<n;i++){
        if(dict[i].compare(s)==0)return true;
    }
    return false;
}
bool canbemade(string dict[], string s){
    if(s.size()==0)return true;
    int sz = s.size();
    bool dp[sz];
    fill_n(dp,sz,false);
    for(int i = 0; i<sz; i++){
        if(check(dict,s.substr(0,i+1)))dp[i] = true;
        if(dp[i]){
            if(i==sz-1)return true;
            for(int j = i+1; j<sz;j++){
                if(check(dict,s.substr(i+1,j-i)))dp[j] = true;
                if(j==sz-1&&dp[j])return true;
            }
            
        }
    }
    return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	    cin>>n;
	    string dict[n];
	    rep(i,n)cin>>dict[i];
	    string s;
	    cin>>s;
	    if(canbemade(dict,s))cout<<"1"<<endl;
	    else cout<<"0"<<endl;
	}
	return 0;
}