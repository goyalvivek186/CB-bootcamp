#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long

using namespace std;

void print_vector(vector<pair<int, int>> &a)
{
	for(auto i : a)	cout<<i.first<<" "<<i.second<<endl;
	cout<<endl;
}

void print_vector(vector<int> &a)
{
	for(auto i : a)	cout<<i<<" ";
	cout<<endl;
}

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if(p1.first == p2.first)
	{
		return	p1.second > p2.second;
	}
		return	p1.first < p2.first;
}



vector<int> frequencySort(vector<int>& a)
// void get(vector<int> &a)
{
	int n = a.size();
	int ma = a[0];
	int mi = a[0];
	for(int i = 0; i < a.size(); i++)	
	{
		ma = max(ma, a[i]);
		mi = min(mi, a[i]);
	}
	int m = max(abs(mi), ma);
	int m2 = 2*m + 1;
	vector<int> fre(m2, 0);
	for(int i = 0; i < n; i++)	fre[a[i] + m]++;

	vector<pair<int, int>>	v;
	for(int i = 0; i < m2; i++)
	{
		if(fre[i])	v.push_back({fre[i], i-m});
	} 
	sort(v.begin(), v.end(), compare);
	// print_vector(v);
	vector<int> ans;
	for(pair<int, int> p : v)
	{
		while(p.first--)
		{
			ans.push_back(p.second);
		}
	}
	return ans;

}

int main()
{
	int n;	cin >> n;
	vector<int> a(n, 0);
	// cout<<"Hi";
	for(int i = 0; i < n; i++)	cin >> a[i];

	// get(a);
	// print_vector(a);



	return 0;
}