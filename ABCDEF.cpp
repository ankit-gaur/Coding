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

int lowerBoundIndex(vi v, int value)
{
  
   int l = 0; int h = v.size()-1;

   int i = -1;

   while(l<=h)
   { 

   	  int mid = (l+h)/2;
   	  if(v[mid]==value)
   	  	{i = mid; break;}
   	  else if(v[mid]>value)
        h = mid - 1;
       else l = mid + 1;
   }

  for(int j = i; j>=0; j--)
  {
  	if(v[j]<value)
  		return j+1;
  } 	
 
 return -1;
}
int upperBoundIndex(vi v, int value)
{
 int l = 0; int h = v.size()-1;

   int i = -1;

   while(l<=h)
   { 

   	  int mid = (l+h)/2;
   	  if(v[mid]==value)
   	  	{i = mid; break; }
   	  else if(v[mid]>value)
        h = mid - 1;
       else l = mid + 1;
   }

  for(int j = i; j<v.size(); j++)
  {
  	if(v[j]>value)
  		return j;
  }
  return -1; 	
}
bool binarySearch(vector<int> v, int value)
{
	int l= 0;
	int h = v.size()-1;
	while(l<=h)
	{
		int mid = (l+h)/2;
		if(v[mid]==value)
			return true;
		else if(v[mid]<value)
		{
			l = mid+1;
		}else {
			h = mid-1;
		}
	}
	return false;	
}
int main()
{
	//a*b+c/d - e  =f;
	int n; cin>>n;
	int arr[n];
	rep(i,n)
	{
        int x; cin>>x;
        arr[i] = x;
	}
	int a,b,c,d,e,f;
	vi l; vi r;
	rep(i,n)
	{
		a = arr[i];
		e = arr[i];
		rep(i,n)
		{
			b = arr[i];
			d = arr[i];
			rep(i, n)
			{
				c = arr[i];
				f = arr[i];
				int le =  a*b + c;
				int ri = d*(e+f);
				l.pb(le);
				if(d!=0)
				r.pb(ri);
			}
		}
	}
	//sort(l.begin(), l.end());
	sort(r.begin(),r.end());
	
	int sum = 0;
	fov(i,l)
	{
       if(binary_search(r.begin(),r.end(),l[i]))
       {
       	 int lb = lower_bound(r.begin(),r.end(),l.at(i)) - r.begin();
       	 int rb = upper_bound(r.begin(),r.end(),l.at(i)) - r.begin();
       	 if(lb==r.size()) lb = 0;
       	 if(rb==r.size()) rb = r.size();
       	 sum+= rb-lb;
       }
	}
	cout<<sum;
}