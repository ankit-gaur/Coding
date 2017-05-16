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
  
   int n,h,d;
   cin>>n>>d>>h;
   if(d<h||h<(d+1)/2)
   {
   	  cout<<-1;
   	  return 0;
   }

   if(n>2&&h==1&&d==1)
     {
   	  cout<<-1;
   	  return 0;
   }
   int  count = 1;

   while(count<=h)
   {
   	   cout<<count<<" "<<count+1;
   	   el;
   	   count++;
   }

   //now count==h+1;
   int next = count+1;
  // cout<<next;

   if(d>h)
   {
   	 cout<<1<<" "<<next;
   	 el;
   	 int left = d - h - 1;
   	 while(left>0)
   	 {
        cout<<next<< " " << next + 1;
        el;
        left--;
        next++;
   	 }
     
     next++;

     left = n - d - 1;

     while(left>0)
     {
     	 cout<<1<<" "<<next;
     	 el;
     	 next++;
     	 left--;
     }	

   }
    else{

    	int left = n - h - 1;

    	while(left>0)
    	{
    		 cout<<2<<" "<<next;
    		 el;
    		 next++;
    		 left--;
    	}	
       
   }

   return 0;
}