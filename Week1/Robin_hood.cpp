#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(vector<int> &a)
{
	int i = 0, j = a.size()-1;
	while(i < a.size() and a[i] > a[i+1])
	{
		swap(a[i], a[i+1]);
		i++;
	}
	if(i == a.size())	j--;
	while(j >= 0 and a[j] < a[j-1])
	{
		swap(a[j], a[j-1]);
		j--;
	}
}

int main()
{
	int n, k;	cin >> n >> k;

	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	while(a[0] != a[n-1] and k--)
	{
		if(a[0] == a[n-1] or a[0] == a[n-1] - 1)	break;
		a[0]++;
		a[n-1]--;
		check(a);
	}
	cout<<a[n-1] - a[0];



	return 0;
}

/*
500000 1000000000
54 52 68 72 87 78 50 78 118 89 102 39 31 72 38 116 44 109 2 115 66 60 61 77 108 21 66 84 56 117 1 49 10 26 105 11 80 74 51 11 2 110 94 8 88 95 35 80 101 23 13 112 59 4 43 42 87 38 78 69 28 48 25 23 21 112 23 22 63 63 41 51 62 112 35 105 113 68 40 19 10 113 99 55 14 8 70 116 46 119 45 102 70 33 15 72 1 27 65 45 79 35 45 42 83 32 78 35 47 104 41 109 32 68 29 101 3 83 21 36 46 111 58 4 75 30 43 99 64 68 17 110 35 102 88 43 36 95 116 32 12 17 91 7 73 16 43 101 14 64 24 26 38 45 58 55 47 80
*/