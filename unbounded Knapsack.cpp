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

const int inf = numeric_limits<int>::max(); 
const LL linf = numeric_limits<LL>::max(); 
const double EPS = 1e-7;  
const int MAXN = 10000001; 
const int LOGMAXN = log2(MAXN) + 3;

int main()
{
	int t;
	cin>>t;
	rep(z,t)
	{
		int n,k;
		vi coins;
		cin>>n>>k;
		rep(i,n)
		{
			int x; cin>>x;
			coins.pb(x);
		}

		sort(coins.begin(),coins.end());

		bool isSum[k+1];
		fill_n(isSum,k+1,false);

        rep(i,n)
        {
        	 if(coins[i]>k) break;
             isSum[coins[i]] = true; 
        }

      
		for(int i = 1; i<k+1 ; i++)
		{
			for(int j = 0; j<n; j++)
	        {  
	        	if(isSum[i])
	        	 break;
	        	 	
				if(i-coins[j]<0)
				{
					isSum[i] = false;
					break;
				}	

				if(isSum[i-coins[j]])
				{
					isSum[i] = true;
					break;
				}	

			}	
		} 

		vi sums;

		for(int i = 0; i<k+1 ; i++)
		{
			if(isSum[i])
			{ 
				sums.pb(i);
				//cout<<i; el;
			}	
		}

		int last = sums.size()-1;
        
        if(last<0) cout<<0;
		else cout<<sums[last];
		el; 
	}
	return 0;
}