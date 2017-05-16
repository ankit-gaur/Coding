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

#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

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
	int q;
	cin>>q;
	vi v;
		viv mat;
	rep(i,q)
	{
		int n,m,cl,cr;
		LL total;
        rep(i,n+1) mat.pb(v);
		bool isVisited[n+1];

		cin>>n>>m>>cl>>cr;
	    rep(i,m)
	    {
	    	int a,b;
	    	cin>>a>>b;
            mat[a].pb(b);
            mat[b].pb(a);
	    }
        
       // cout<<"ok";
        
   
        if(cl<=cr)
        {
        	total = n*cl;
        	cout<<total; el;
        	continue;
        }

        vi s; 
        int libCount = 0;
        for(int i = 1; i<n+1 ; i++)
        {
        	if(isVisited[i]) continue;
            
            s.pb(i);
           // cout<<i; el;
            isVisited[i] = true;
            libCount++;
            while(!s.empty())
            {
            	int x  = s.back();
            	s.pop_back();
            	fov(j,mat[x])
            	{
            		if(!isVisited[mat[x][j]])
            		{
            			s.pb(mat[x][j]);
            			isVisited[mat[x][j]] = true;
            		}	
            	}
            }	

        }
  
        total = (n-libCount)*cr + libCount*cl;
        cout<<total; el;
        mat.clear();
	}
	return 0;
}#include<bits/stdc++.h>
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

#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

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
	int q;
	cin>>q;
	    
	rep(k,q)
	{
		int n,m,cl,cr;
		LL total;
		cin>>n>>m>>cl>>cr;
        viv mat;
        vi v;
        bool isVisited[n+1];
        fill_n(isVisited,n+1,false);
        rep(i,n+1) mat.pb(v);
	    rep(i,m)
	    {
	    	int a,b;
	    	cin>>a>>b;
            mat[a].pb(b);
            mat[b].pb(a);
	    }
       
   
        if(cl<=cr)
        {
        	total = (LL)n*(LL)cl;
        	cout<<total; el;
        	continue;
        }

        stack<int> s; 
        int libCount = 0;
        //cout<<"ok\n";
        for(int i = 1; i<n+1 ; i++)
        {
        	if(isVisited[i]) continue;
            //cout<<i<<"visited \n";
            s.push(i);
            isVisited[i] = true;
            libCount++;
            while(!s.empty())
            {
            	int x  = s.top();
                isVisited[x] = true;
                //cout<<x<<" visited from "<<i; el;
            	s.pop();
            	fov(j,mat.at(x))
            	{
            		if(!isVisited[mat[x][j]])
            		{
            			s.push(mat[x][j]);
            		}	
            	}
            }	

        }
  
      //  cout<<cl; el;
       /* total = 0;
        for(int i = 0 ; i<libCount; i++) {
            total+= cl;
            
        }
        int nroads = n-libCount;
        
        rep(i,nroads) {
            total+=cr;
        } */
        total = (LL)(n-libCount)*cr + (LL)libCount*cl; //one of the two term alone can exceed int range so typecast both;
        cout<<total; el; 
	}
	return 0;
}