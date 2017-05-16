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

int lis(vi &v)
{
	vi tails(v.size(),0);
    
    int curLength = 1; //currentLenght points latest empty slot in tails array;
    
    tails[0] = v[0]; // tail of first possible lis is first element itself;

    for(int i = 1; i<v.size(); i++)
    {
    	if(tails[0]>v[i])
    	{
    		tails[0] = v[i]; // new active list with tail as v[i] also the starting point;
    	}	
    	else if(tails[curLength-1]<=v[i]) 
    	{
            //add v[i] to largest current lis 
            tails[curLength] = v[i];
            curLength++; 
    	}	
    	else
    	{
    		 //v[i] is greater the smallest of all actives and less than largest so it will replace one of the active lists last element 
    		int cl = lower_bound(tails.begin(),tails.begin()+curLength-1, v[i])-tails.begin();
            tails[cl] = v[i];
    	}

    }	

    return curLength;


}

int main()
{
   
   int n;
   cin>>n;
   vi v;
   rep(i,n)
   {
   	 int x; cin>>x;
   	 v.pb(x);
   } 
   
   cout<<lis(v);

   return 0;
}