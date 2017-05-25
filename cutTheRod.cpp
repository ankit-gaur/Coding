#include<bits/stdc++.h>
#include<sys/time.h>
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
int prices[MAXN];

//make table to memorize
int val[MAXN];
int countIter = 0;


long long int curTimeMilli()
{
	timeval curTime;
gettimeofday(&curTime, NULL);
long long int ms = curTime.tv_sec * 1000 + curTime.tv_usec / 1000;
return ms;
}


int maxVal(int n)
{
	int maxvalue = 0;
	for(int i = 1; i<=n; i++)
	{   
		if(val[n-i]!=-1)
		{
			maxvalue = max(maxvalue,prices[i]+val[n-i]);
		}else{
			val[n-i] = maxVal(n-i);
			maxvalue = max(maxvalue,prices[i]+val[n-i]);
		}	
	}
	return maxvalue;
}

int main()
{
   int n;
   cin>>n;
   fill_n(val,1000,-1);
   val[0] = 0;
   prices[0] = 0;
   rep(i,n)
   {
   	 int p; 
   	 cin>>p;
   	 prices[i+1] = p;
   }
 
 LL t1 = curTimeMilli(); 

 cout<<maxVal(n); //max value using top-down approch

 LL t2 = curTimeMilli();

 el;


//bottom-up aprroach O(n2)

 int values[n+1];
 values[0] = 0;
 

 for(int i =1 ; i<=n; i++)
 {   values[i] =0;
 	for(int j = 1; j<=i; j++)
 	{
 		values[i]  = max(values[i],values[i-j]+prices[j]);
 	}
 }

LL t3  = curTimeMilli();

 cout<<values[n]; el;

 cout<<"time in top-down approach "<<t2-t1; el;
 cout<<"time in bottom-up approach "<<t3-t2; el;


   return 0;
}
