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

bool comp(pii p1, pii p2)
{
	  if(p1.sc!=p2.sc)
	  {
	  	 return p1.sc<p2.sc;
	  }
	  else{
	  	return p1.fs>p2.fs;
	  }	
}

int main()
{
   int n,c,d;
   cin>>n>>c>>d;
   vpii fc,fd;
   vi vc,vd;
   int b1 = 0, b2= 0;
   rep(i,n)
   {
   	  int b,p;
   	  char cd;
   	  cin>>b>>p>>cd;
   	  if(cd=='C'&&p<=c){fc.pb(mp(b,p)); if(b>b1) b1 = b; }
   	  else if(cd=='D'&&p<=d){ fd.pb(mp(b,p)); if(b>b2) b2 = b;}
   }
   
   int cd=-1;

   if(fc.size()>0&&fd.size()>0)
   { 
   	  cd = b1+b2;

   }
   else{
   //	cout<<"can not buy cd/n";
   }	
   
   int bcc = -1, bdd = -1;

   sort(fc.begin(),fc.end(),comp);
   sort(fd.begin(),fd.end(),comp);
   
  /* fov(i,fc)
   {
   	 cout<<fc[i].fs<<" "<<fc[i].sc; el; //
   } 
*/
   rep(i,fc.size())
   {
   	 vc.pb(fc[i].sc);
   //	 cout<<fc[i].sc<<" "; //
   }
 //  el; //
   rep(i,fd.size())
   {
   	 vd.pb(fd[i].sc);
   }
   
   if(fc.size()>=2)
  rep(i,vc.size())
  {
  	 int f = vc[i];
  	 int left = c - vc[i];
  	 int l = lower_bound(vc.begin(),vc.end(),left)-vc.begin();

  	// cout<<"lower bound of "<<left<< " is "<<l; el;
    
     while(l>=0&&l<fc.size())
     {  
     	if(vc[l]<=left&&bcc<(fc[i].fs+fc[l].fs)&&i!=l)
     	{
           bcc  = fc[i].fs + fc[l].fs;
     	}	
        l--;
     }	
  }
 
 if(fd.size()>=2)
  rep(i,vd.size())
  {
  	 int f = vd[i];
  	 int left = d - vd[i];
      
  	 int l = lower_bound(vd.begin(),vd.end(),left)-vd.begin();
     while(l>=0&&l<fd.size())
     {  
     	if(vd[l]<=left&&bdd<(fd[i].fs+fd[l].fs)&&i!=l)
     	{
           bdd  = fd[i].fs + fd[l].fs;
     	}	
        l--;
     }	
  }
  


  int maxb = max(max(0,cd),max(bcc,bdd));
  cout<<maxb;

   
   return 0;
}