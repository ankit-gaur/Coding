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

int findMax(unordered_multimap<int,int> colors)
{
	int max = 0;
	for(auto &v : colors)
	{
		if(colors.count(v.fs)>max) max = colors.count(v.fs);
		
	}
	return max;
}

int main()
{

	int n,m,k;

	cin>>n>>m>>k;

	int color[n+1];



	rep(i,n)
	{
		cin>>color[i+1];
	}

	viv graph;
	vi v;
	rep(i,n+1) graph.pb(v); 

	rep(i,m)
	{
		int a,b;
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	bool isVisited[n+1];
	fill_n(isVisited,n+1,false);
	int count = 0;
	for(int i = 1; i<n+1 ; i++)
	{
		if(isVisited[i]) continue;
		stack<int> s;
		s.push(i);
		int ncount = 0;
		
		unordered_map<int , int> colors;

		int max = 1;

		while(!s.empty())
		{
			int top = s.top();
			s.pop();
			if(!isVisited[top])
			{
				if(colors.count(color[top])>0)
				{
					int count = colors.at(color[top]);
				    colors[color[top]] += 1;
				    if(count+1>max) max = count +1; 
				}	
				else{
					colors[color[top]] = 1;
				}
				ncount ++;
				
			}	
			isVisited[top] = true;
			fov(i,graph[top])
			{
				if(!isVisited[graph[top][i]])
				{
					s.push(graph[top][i]);
				}
			}
		}


		if(ncount<2) continue;

      //  cout<<findMax(colors); el;

		count += ncount - max;

	}	

	cout<<count;


	return 0;
}