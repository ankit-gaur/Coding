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
	rep(i,q)
	{
		int n,m,s;
		cin>>n>>m;

		vi map[n+1];
		bool isVisited[n+1];

		rep(i,m)
		{
			int a,b;
			cin>>a>>b;
			map[a].pb(b);
			map[b].pb(a);

		}

		cin>>s;

		vi cost(n+1,-1);

		queue< pii > q;
		q.push(mp(s,0));
		while(!q.empty())
		{
			pii f = q.front();
			isVisited[f.fs] = true;
			q.pop();
			fov(i,map[f.fs])
			{
				if(!isVisited[map[f.fs][i]])
				{ 
                   q.push(mp(map[f.fs][i],f.sc+6));
                   cost[map[f.fs][i]] = f.sc+6;   
				}	
			}

		}
		fov(i,cost)
        {
        	if(i!=0&&i!=s) cout<<cost[i]<<" ";
        }	
         
         el;
           
	}
	return 0;
}