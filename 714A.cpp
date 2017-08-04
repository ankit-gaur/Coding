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
	LL l1,r1,l2,r2,k;
	LL ans = 0;
	cin>>l1>>r1>>l2>>r2>>k;
    if(r1<l2||r2<l1)ans = 0;
    else if(r1>=l2&&r2>=r1&&l2>=l1){
    	ans = r1-l2+1;
    	if(k>=l2&&k<=r1)ans-=1;
    }
    else if(r2>=l1&&r1>=r2&&l2<=l1){
    	ans = r2-l1+1;
    	if(k>=l1&k<=r2)ans-=1;
    }else if(l1>=l2&&r1<=r2){
    	ans = r1-l1+1;
    	if(k>=l1&&k<=r1)ans-=1;

    }
    else if(l2>=l1&&r2<=r1){
    	ans = r2-l2+1;
    	if(k>=l2&&k<=r2)ans-=1;
    }
    cout<<ans;
    return 0;
}