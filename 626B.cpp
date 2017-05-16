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

string orstrs(string a, string b)
{
		string ans = "";
        if(a.find("R")!=string::npos||b.find("R")!=string::npos)
        {
        	ans = ans + "R";
        }
        if(a.find("G")!=string::npos||b.find("G")!=string::npos)
        {
        	ans = ans + "G";
        }
        if(a.find("B")!=string::npos||b.find("B")!=string::npos)
        {
        	ans = ans + "B";
        }
        return ans;
}

int main()
{
  
   int n;
   cin>>n;
   string s;
   cin>>s;

   
   int nr=0,ng=0,nb=0; 

   fov(i,s)
   {
      if(s[i]=='R') nr++;
      else if(s[i]=='G')ng++;
      else nb++;
   }
    


   string color[nr+1][ng+1][nb+1];
   rep(i,nr+1) rep(j,ng+1) rep(k,nb+1){
   	 color[i][j][k] = "";
   }
  
  //answer to smalles sub problems

  if(nr>0)
  {
  	color[1][0][0] = "R";
  	if(ng>0)
  	color[1][1][0] = "B";
  }    
  if(ng>0)
  {
    color[0][1][0] = "G";
  	if(nb>0)
  	color[0][1][1] = "R";
  }	
  if(nb>0)
  {
    color[0][0][1] = "B";
  	if(nr>0)
  	color[1][0][1] = "G";
  }	

     
   rep(r,nr+1)
   {
   	 rep(g,ng+1)
   	 {
   	 	rep(b,ng+1)
   	 	{

           if(r>0)
           {
           	  if(r<nr)
              color[r+1][g][b] = orstrs(color[r+1][g][b],color[r][g][b]);
              if(g<ng&&b<nb)
              color[r-1][g+1][b+1] = orstrs(color[r-1][g+1][b+1],color[r][g][b]);
           }
           if(b>0)
           {
           	  if(b<nb)
           	  color[r][g][b+1] = orstrs(color[r][g][b+1],color[r][g][b]);
           	  if(r<nr&&g<ng)
           	  color[r+1][g+1][b-1] = orstrs(color[r+1][g+1][b-1],color[r][g][b]);
           }	
           if(g>0)
           {
           	  if(g<ng)
           	  color[r][g+1][b] = orstrs(color[r][g+1][b],color[r][g][b]);
           	  if(r<nr&&b<nb)
           	  color[r+1][g-1][b+1] = orstrs(color[r+1][g-1][b+1],color[r][g][b]);
           }
      	
   	 	}
   	 }
   }

   rep(i,nr+1) rep(j,ng+1) rep(k,nb+1){
   	 cout<<i<<" "<<j<<" "<<" "<<k<<"  : "<<color[i][j][k]; el;
   }

   cout<<color[nr][ng][nb];

   return 0;
}