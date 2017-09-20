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

void backtrack(vi &v, int ind){

    if(ind<v.size()){
    	cout<<v[ind]<<" ";
    }
    if(ind<v.size()-1)
    backtrack(v,ind+1);
    cout<<endl;
    if(ind<v.size()-1)
    backtrack(v,ind+1);
}
int main(){
	int n;
	cin>>n;
	vi v(n);
	rep(i,n){
		cin>>v[i];
	}	
	sort(v.begin(),v.end());	
	backtrack(v,0);
	return 0;
}
