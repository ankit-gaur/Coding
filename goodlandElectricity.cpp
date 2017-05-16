//thank u brother... :)
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
	int n,k;
	cin>>n>>k;

    bool isTower[n];
	rep(i,n)
	{
       int x; cin>>x;
       if(x==0) isTower[i] = false; else isTower[i] = true;
	}
	vpii v; 
	rep(i,n)
	{
		if(isTower[i])
		{
			int lb = i - k + 1;
			//if(lb<0) lb =0;
			int ub = i + k - 1;
			//if(ub>n-1) ub = n-1;
            pii p = mp(lb,ub);
            v.pb(p);
		}	
	}

	int count = 0;
 	int targetCity = 0;
    
    
 
	fov(i,v)
	{
		pii p = v[i];
		if(p.fs >targetCity)
		{
			//should take the previous tower to take the current city
			if(i>0&&v[i-1].sc!=(targetCity-1))
			{
			  // cout<<i-1<<" taken "<<i; el;	
               targetCity = v[i-1].sc + 1; 
               i--; // look for this tower again because our target city has been changed;
               count++;
			}
			else break;	 //  current city can not be covered;
		}else 
		  if(p.fs<=targetCity&&i == v.size()-1)
		{
          //cout<<i<< " taken"; el;
           targetCity = v[i].sc+1;
           count++;
		}	


		//all cities covered then target will be greater than n-1th city;
		if(targetCity>n-1) break;	
	}
	if(targetCity>n-1)
	{
		cout<<count;
	}
	else cout<<"-1";
}