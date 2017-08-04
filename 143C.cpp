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
	LL n; 
	cin>>n;
	LL minz = 1000000000000;
	LL maxz = 0;
	for(LL i = 1; i<=sqrt(n); i++)
	{
		if(n%i!=0)continue;
		LL x = i,y,z,cmin,cmax,yz,k;
		yz = n/x;
		k = n+yz+4*x+4;
		cmax = k + (2*x+2)*(1+yz);

		for(LL i = sqrt(yz); i>=1; i--){
			if(yz%i==0){
			
				cmin = k + (2*x+2)*(i+yz/i);
				break;
			}	
		}
		//cout<<"cmax is "<<cmax;
		if(minz>cmin)minz = cmin;
		if(maxz<cmax)maxz = cmax;

		x = n/i;
		yz = n/x;
		k = n+yz+4*x+4;
		cmax = k + (2*x+2)*(1+yz);

		for(LL i = sqrt(yz); i>=1; i--){
			if(yz%i==0){
			
				cmin = k + (2*x+2)*(i+yz/i);
				break;
			}	
		}
		//cout<<"cmax is "<<cmax;
		if(minz>cmin)minz = cmin;
		if(maxz<cmax)maxz = cmax;

	}
	cout<<minz-n<<" "<<maxz-n;
    return 0;
}