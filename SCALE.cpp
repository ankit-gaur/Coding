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
	LL n,x;
	cin>>n>>x;
	vi l,r; 
	LL lsum = x, rsum = 0,totalsum = 0;
	vector<long long> w(n+1); 
	vector<long long> cw(n+1);
	cw[0] = 0;
	cw[1] = 1; 
	w[0] = 0;

	rep(i,n)
	{
		w[i+1] = pow(3,i);
		cw[i+1] = cw[i] + w[i+1];
		
	}

	totalsum = cw[n];
	int diff = x;

	if(totalsum<x) {
		cout<<"-1"; return 0;
	}
    
	while(diff>0)
	{
		
		if(binary_search(cw.begin(),cw.end(),diff))
		{    
			int index = lower_bound(cw.begin(),cw.end(),diff) - cw.begin();
			//cout<<"diff is equal to cw element "<<cw[index] <<" "<<w[index]<< " " <<diff;
			int weight = w[index];
			if(rsum>lsum)
			{
				for(int i = index; i>0;i--)
				{
					l.pb(i);
				}	
			}else{
				for(int i = index; i>0;i--)
				{
					r.pb(i);
				}
			}
			break;
		}	
        
        //cout<<diff<<" "; 

		int ub = upper_bound(cw.begin(),cw.end(),diff) - cw.begin();
		//cout<<ub<<" "; el;
		int weight = w[ub];
		if(rsum>lsum)
		{
			lsum += weight;
			l.pb(ub);
		}else{
			rsum +=weight;
			r.pb(ub);
		}
		diff = abs(rsum-lsum);

	}	

	fov(i,l)
	{
		cout<<l[l.size()-1-i]<<" ";
	}
	el;
	fov(i,r)
	{
		cout<<r[r.size()-1-i]<<" ";
	}

	return 0;

}