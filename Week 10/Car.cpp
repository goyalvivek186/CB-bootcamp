#include <iostream>
#include <vector>
#include <string>
// #include <algorithm>
// #include <climits>

#define ll long long

using namespace std;

int main()
{
	int car[5][2];
	/*
	Production - price
	1000 20000
	1200 21000
	1300 22000
	1500 25000
	2000 30000
	*/
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			cin >> car[i][j];
		}
	}

	int loss[5][2];
	/*
	20000 0
	21000 5
	22000 10
	25000 25
	30000 50
	*/
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			cin >> loss[i][j];
		}
	}
	
	
	return 0;
}