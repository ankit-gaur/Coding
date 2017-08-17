#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;
#define V vector
typedef long long int LL;
typedef V<int> vi;
typedef V<LL> vl;
typedef V<pair<int ,int>> vpii;

#define rep(i,a) for(int i = 0; i<a ; i++)
#define fov(i,v) rep(i,v.size())
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#define el cout<<endl

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();

long long int curTimeMilli()
{
	timeval curTime;
gettimeofday(&curTime, NULL);
long long int ms = curTime.tv_sec * 1000 + curTime.tv_usec / 1000;
return ms;
}

#define indexof(c) ((int)c-(int)'a')

void countSort(string &s){
	int count[26];
	fill_n(count,26,0);
	fov(i,s){
		count[indexof(s[i])]++;
	}
	s = "";
	rep(i,26){
		while(count[i]--){
			s+=(char)(97+i);
		}
	}
	return;
}

int main(){
	ifstream ir("teststrings.txt");
	ofstream of("outputCountsort.txt");
	LL t1,t2;
	V<string> vs,vs2;
	string s;
	while(ir>>s){
		vs.pb(s);
	}

	vs2 = vs;

	t1 = curTimeMilli();
	fov(i,vs2){
		// cout<<vs2[i]<<endl;
		countSort(vs2[i]);
		// cout<<vs2[i]<<endl;
	}
	t2 = curTimeMilli();
	LL d1 = t2-t1;

	t1 = curTimeMilli();
	fov(i,vs){
		// cout<<vs[i]<<endl;
		sort(vs[i].begin(),vs[i].end());
		// cout<<vs[i]<<endl;
	}
	t2 = curTimeMilli();

	cout<<d1<<" "<<t2-t1; el;

	fov(i,vs2)of<<vs2[i]<<"\n";
	
	of.close();

	
	return 0;
}
