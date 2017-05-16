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


//********************** GETTING WRONG ANSWERw
int main()
{
	int t; cin>>t;
	LL maxn  = 1000*1000*1000;
	LL sqm = sqrt(maxn);
	bool isprime[sqm+1];
	fill_n(isprime, sqm,true);
	for(LL i = 2; i<=sqrt(sqm); i++)
	{
		if(isprime[i])
		{
			for(LL j = i*i; j<=sqm; j+=i)
			{   

               isprime[j] = false;
			}	
		}	
	}
  
 // cout<<"reached";
   
   isprime[1] = false;

	rep(i,t)
	{
	   	LL m, n;
		cin>>m>>n;
		
		
        
        if(m<=sqm)
        {
          for(int j = m; j<=sqm&&j<=n; j++)
          {
          	if(isprime[j])
          	{
          		cout<<j<<"\n";
          	}
          }
          m = sqm+1;

        }
        if(n<=sqm) continue;

        bool arr[n-m+1];
		fill_n(arr,n-m+1,true);
        for(int i = 2; i<=sqm; i++)
        {
        	if(isprime[i])
        	{
                 int start;
                 start = m/i;
                 start = start*i;
        		for(LL j = start;  j<=n; j+=i)
        		{   
        			//cout<<j<<" ";
        			if(j>m)
        			arr[j-m] = false; 
        		}	
        		//cout<<"\n";	
        	}
        	
        }
        for(LL i = 0; i<=n-m; i++)
        {
        	if(arr[i])
        	{
        		if(m+i>1)
        		cout<<m+i<<"\n";
        	}
        }	
        el;


	}
	return 0;
}