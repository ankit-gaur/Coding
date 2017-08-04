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
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)  //???????????????????????????????

#define pb push_back
#define mp make_pair

#define fs first
#define sc second

#define el cout<<endl 

#define all(x) (x).begin(), (x).end()  //***************************************************

int main()
{  
	int n;
	cin>>n;
	vl v; 
	rep(i,n){
		int x;
		cin>>x;
		v.pb(x);
	}
	sort(v.begin(),v.end());
	LL count = 0;
	for(int i = 0; i<v.size(); i++){
		int x = v[i];
		int tp = log2(x);
		for(int j = tp+1;pow(2,j)<=pow(2,(int)log2(v[n-1])+1) ; j++){
			LL z = pow(2,(LL)j);
			// cout<<"z is "<<z<<" x is "<<v[i]<<" i is "<<i; el;
			if(binary_search(v.begin()+i+1,v.end(),z-v[i])){ 
				// cout<<"found "<<v[i]<<" "<<z-v[i]; el;
				count+= (upper_bound(v.begin()+i+1,v.end(),z-v[i])-v.begin()) - (lower_bound(v.begin()+i+1,v.end(),z-v[i]) - v.begin());
			}
		}
		
	}
	cout<<count;
    return 0;
}