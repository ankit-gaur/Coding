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

bool compare(const pii lhs, const pii rhs){
    return lhs.fs<rhs.fs;
}

int main()
{  
	int n,k;
	cin>>n;
	vpii caps;
	vpii reqs;
	rep(i,n){
		int c,p;
		cin>>c>>p;
		reqs.pb(mp(c,p));
	}
	cin>>k;
	rep(i,k){
		int x; cin>>x;
		caps.pb(mp(x,i+1));
	}
    bool isaccepted[n];
    int mp[n+1];
    int numreqs = 0;
    int totalsum = 0;
    fill_n(isaccepted,n,false);
    sort(caps.begin(),caps.end(),compare);
    fov(i,caps){
    	int cap = caps[i].fs;
    	int tableindex = caps[i].sc;
    	int index = -1, maxp = 0,maxs=0;
    	for(int j = 0; j<reqs.size(); j++){
    		int size = reqs[j].fs;
    		int money = reqs[j].sc;
    		if(!isaccepted[j]&&size<=cap&&money>=maxp){
    			maxp = money; index = j;
    		}
    	}
    	if(index!=-1){
    		isaccepted[index] = true;
    		numreqs++;
    		totalsum+=maxp;
    		mp[index] = tableindex; 
    	}
    }
    
    cout<<numreqs<<" "<<totalsum; el;
    for(int i = 0; i<n; i++)
    {
    	if(isaccepted[i]){
    		cout<<i+1<<" "<<mp[i]; el;    	}
    }

    return 0;
}