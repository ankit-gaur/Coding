#include<bits/stdc++.h>
#include<sys/time.h>

using namespace std;
long long int curTimeMilli()
{
	timeval curTime;
gettimeofday(&curTime, NULL);
long long int ms = curTime.tv_sec * 1000 + curTime.tv_usec / 1000;
return ms;
}
int main()
{
   long long int t1,t2;
   vector<int> v;
   t1 = curTimeMilli();
   for(int i = 0; i<1000*1000*10; i++)
   {
          v.push_back(i);
   }

   t2 = curTimeMilli();
   cout<<t2-t1;
} 