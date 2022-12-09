#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define ld long double

ld pi = 3.1415926;
ld ans = 5.8831725615;
ld a = 1e5;
using namespace std;

double func(double b,double c,double x){
    return (x*x+b*x+c)/sin(x);
}

void solve()
{
   double b,c;
   cin >> b >> c;

   double eps= 1e-8;
   double l=(1e-10);
   double r=asin(1)-1e-10;


   while((r-l) > eps){
      double m1= l + (r-l)/3;
      double m2= r - (r-l)/3;

      double f1=func(b,c,m1);
      double f2=func(b,c,m2);
      
      if(f1 > f2){
         l=m1;
      }
      else if(f1 < f2){
         r=m2;
      }
      else{ 
         l=m1;
         r=m2;
      }
   }

   cout << func(b,c,l) << endl;



}

int main()
{
	int t;	cin >> t;
	while(t--)
	{
		solve();
	}



	return 0;
}