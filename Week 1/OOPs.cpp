// #include <iostream>
// #include <vector>
// #include <string>
#include<bits/stdc++.h>
using namespace std;

class vehicle
{
	const int st;
protected:
	int max_speed;
	int numTyres;
public:
	string clr;

	vehicle(int sta):st(sta)
	{

	}
	void get_data(int a, int b, string ch)
	{
		numTyres = a;
		max_speed = b;
		clr = ch;
	}

	void print()
	{
		cout<<numTyres<<" "<<max_speed<<" "<<clr<<endl;
		cout<<st;
	}
};

// class cars:protected vehicle
// {
// 	string name;
// public:
// 	void get_data(int b, int a, string cr, string n)
// 	{
// 		max_speed = a;
// 		numTyres = b;
// 		clr = cr;
// 		name = n;
// 	}

// 	void print()
// 	{
// 		cout<<numTyres<<" "<<max_speed<<" "<<clr<<" "<<name<<endl;
// 	}
// };

int main()
{
	vehicle v(5);
	int a, b;
	string s;
	cin >> a >> b >> s;
	v.get_data(a, b, s);
	v.print();
	// cars c;
	// string s2;
	// cin >> a >> b >> s >> s2;
	// c.get_data(a, b, s, s2);
	// c.print();



	return 0;
}