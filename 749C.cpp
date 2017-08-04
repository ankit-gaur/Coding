#include<bits/stdc++.h>
using namespace std;

#define V vector

typedef long long int LL;
typedef pair<int, int>  pii;
typedef pair<int, string> pis;

typedef V<int> vi;
typedef V<string> vs;
typedef V<LL> vl;
typedef V<double> vd;
typedef V<pii> vpii;
typedef V<vi> viv;  
typedef V<pis> vpis; //******************************************************************

#define forup(i,a,b) for(int i=(a); i<(b); ++i) 
#define fordn(i,a,b) for(int i=(a); i>(b); --i) 
#define rep(i,a) for(int i=0; i<(a); ++i) 
#define fov(i,a) rep(i,(a).size()) 
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++) 

#define pb push_back
#define mp make_pair

#define fs first
#define sc second

#define el cout<<endl 

#define all(x) (x).begin(), (x).end()  //***************************************************

const int inf = numeric_limits<int>::max(); 
const LL linf = numeric_limits<LL>::max();

int main()
{  
	int n; cin>>n;
	string s;
	cin>>s;
	int cr = 0;
	int cd = 0;
	int count = 0;
	bool isKilled[n];
	fill_n(isKilled,n,false);
	while(count<=log2(n)){
		count++;
		//cout<<s.size()<<" ";
		for(int i = 0; i<s.size(); i++){
			if(isKilled[i])continue;
			if(s[i]=='D'){
				if(cr>0){
					cr--;
					isKilled[i] = true;
					cd = 0;
				}else{
					cd++;
				}
			}else{
				if(cd>0){
					cd--;
					isKilled[i] = true;
					cr = 0;
				}else{
					cr++;
				}
			}
		}
		//cout<<count; el;
	}
	rep(i,n){
		if(!isKilled[i]){
			if(s[i]=='D')cout<<"D";
			else cout<<"R";
			break;
		}
	}
    return 0;
}